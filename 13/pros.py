
# Class Definition
class User:
    def __init__(self, name, profession):
        self.name = name
        self.profession = profession


class Engineer(User):
    def __init__(self, name, field):
        super().__init__(name, f"{field} Engineer")


class ElectricalEngineer(Engineer):
    def __init__(self, name):
        super().__init__(name, "Electrical")


class ComputerEngineer(Engineer):
    def __init__(self, name):
        super().__init__(name, "Computer")


class MechanicalEngineer(Engineer):
    def __init__(self, name):
        super().__init__(name, "Mechanical")


class Technician(User):
    def __init__(self, name):
        super().__init__(name, "Technician")


class Barber(User):
    def __init__(self, name):
        super().__init__(name, "Barber")


class Politician(User):
    def __init__(self, name):
        super().__init__(name, "Politician")


# Holds the predefined classes, for dynamic creation cases.
# Great for restrictions.
PREDEFINED_CLASSES = [
    User, Engineer, Technician, Barber, Politician,
    ElectricalEngineer, ComputerEngineer, MechanicalEngineer
]


if __name__ == "__main__":
    # Get input data from user, about the new class to create.
    new_class_name = input("Please enter the name of new class: ")
    base_class_name = input("Please enter name of base class (blank if none): ")

    base_class = None
    for predefined_class in PREDEFINED_CLASSES:
        # Prevent duplicates
        if predefined_class.__name__ == new_class_name:
            print(f"Class with name {new_class_name} already exists.")
            exit(1)
        # Look for base class by name
        if predefined_class.__name__ == base_class_name:
            base_class = predefined_class

    # None = not found!
    if base_class is None and base_class_name:
        print(f"Base class {base_class_name} could not be found!")
        exit(1)

    # Build class dictionary - holds method & attribute
    new_method = input(f"Please enter name of new method for class {new_class_name}: ")
    new_attribute = input(f"Please enter name of new attribute for class {new_class_name}: ")

    # Create the final class
    bases = (base_class,) if base_class else ()

    dict_for_class = {
        new_attribute: None,
        new_method: lambda self: None
    }

    created_class = type(new_class_name, bases, dict_for_class)

    # Print information
    print(f"Class __name__ is {created_class.__name__}")
    print(f"Class __dict__ is {created_class.__dict__}")
