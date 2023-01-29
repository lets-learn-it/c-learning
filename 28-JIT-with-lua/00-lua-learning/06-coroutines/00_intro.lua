local co = coroutine.create(function (argument)
  print(argument)
end)

print(coroutine.status(co))

coroutine.resume(co, "This is argument")

print(coroutine.status(co))
