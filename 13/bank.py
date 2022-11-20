
class BankAccount:
    def __init__(self, name, amt):
        self.name = name
        self.amt = amt
        pass

    def __str__(self):
        return f"Your account, {self.name}, has {self.amt} dollars."


if __name__ == "__main__":
    t1 = BankAccount("Bob", 100)
    print(t1)
