-- class

BankAccount = {
  account_number = 0,
  holder_name = "",
  balance = 0.0
}

-- constructor
function BankAccount:new(t)
  t = t or {}
  setmetatable(t, self)
  self.__index = self
  return t
end

function BankAccount:deposit(amount)
  self.balance = self.balance + amount
end

function BankAccount:withdraw(amount)
  self.balance = self.balance - amount
end

function BankAccount:tostring()
  print("{ holder_name: ", self.holder_name, ", account_number: ", self.account_number
    , ", balance: ", self.balance, " }")
end

account1 = BankAccount:new({holder_name="Parikshit", balance=10000, account_number=12345})

account1:deposit(5000)

print(account1:tostring())