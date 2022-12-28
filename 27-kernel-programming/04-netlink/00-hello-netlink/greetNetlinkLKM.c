#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/netlink.h>
#include <net/sock.h>
#include <linux/string.h>

/* should be less than MAX_LINKS which is 32 */
#define NETLINK_TEST_PROTOCOL 31

void netlink_recv_msg_fn(struct sk_buff *skb_in);

static struct netlink_kernel_cfg cfg = {
  .input = netlink_recv_msg_fn,
};

static struct sock *nl_sk = NULL;

static void nlmsg_dump(struct nlmsghdr *nlh) {
  printk(KERN_INFO "Length: %u\n", nlh->nlmsg_len);
  printk(KERN_INFO "flags: %u\n", nlh->nlmsg_flags);
  printk(KERN_INFO "PID: %u\n", nlh->nlmsg_pid);
  printk(KERN_INFO "Seq: %u\n", nlh->nlmsg_seq);
  printk(KERN_INFO "Type: %u\n", nlh->nlmsg_type);
}

void netlink_recv_msg_fn(struct sk_buff *skb_in) {
  struct nlmsghdr *nlh_recv, *nlh_reply;
  int user_space_process_port_id, user_space_data_len, res;
  char *user_space_data;
  char kernel_reply[256];

  // for sending message to user space.
  struct sk_buff *skb_out;

  printk(KERN_INFO "%s() invoked", __FUNCTION__);

  nlh_recv = (struct nlmsghdr*) (skb_in->data);

  nlmsg_dump(nlh_recv);

  user_space_process_port_id = nlh_recv->nlmsg_pid;

  printk(KERN_INFO "%s(%d): port id: %u\n", __FUNCTION__, __LINE__, user_space_process_port_id);

  // get pointer to data using function nlmsg_data
  user_space_data = (char *) nlmsg_data(nlh_recv);

  user_space_data_len = skb_in->len;

  printk(KERN_INFO "Data from userspace: %s", user_space_data);

  // send ack if user space asks for it
  if (nlh_recv->nlmsg_flags & NLM_F_ACK) {
    memset(kernel_reply, 0, sizeof(kernel_reply));

    // create response like sprintf
    snprintf(kernel_reply, sizeof(kernel_reply), "Msg from Process %d has been processed by kernel", nlh_recv->nlmsg_pid);

    // create new socket buffer (memory allocation, need to free)
    skb_out = nlmsg_new(sizeof(kernel_reply), 0);

    nlh_reply = nlmsg_put(skb_out, 0, nlh_recv->nlmsg_seq, NLMSG_DONE, sizeof(kernel_reply), 0);

    strncpy(nlmsg_data(nlh_reply), kernel_reply, sizeof(kernel_reply));

    // if success, will free skb_out
    res = nlmsg_unicast(nl_sk, skb_out, user_space_process_port_id);

    if (res < 0) {
      printk(KERN_INFO "Error while sending data to userspace\n");

      // free skb_out
      kfree_skb(skb_out);
    }
  }
}



int hello_netlink_init_module(void) {
  printk(KERN_INFO "Hello Netlink! Module loaded successfully.\n");

  nl_sk = netlink_kernel_create(&init_net, NETLINK_TEST_PROTOCOL, &cfg);

  if (!nl_sk) {
    printk(KERN_ERR "Creating netlink socket failed for protocol %u\n", NETLINK_TEST_PROTOCOL);

    // may not be correct reason but still
    return -ENOMEM;
  }

  printk(KERN_INFO "Netlink socket created successfully.\n");
  return 0;
}

void hello_netlink_cleanup_module(void) {
  printk(KERN_INFO "Goodbye Netlink \n");

  netlink_kernel_release(nl_sk);
  nl_sk = NULL;
}

module_init(hello_netlink_init_module);
module_exit(hello_netlink_cleanup_module);

#define AUTHOR_NAME "Parikshit_Patil"
#define MODULE_DESC "hello netlink"

MODULE_AUTHOR(AUTHOR_NAME);
MODULE_DESCRIPTION(MODULE_DESC);
MODULE_LICENSE("GPL");
