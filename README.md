# Calculator_App
Description

The Calculator App is a graphical user interface (GUI)-based application built using C++ and wxWidgets. It provides functionality for performing basic and advanced mathematical operations, including unary and binary calculations. This project emphasizes modular programming and unit testing, making it a great example of a well-structured and maintainable application.
Features

    Basic Arithmetic Operations: Addition, subtraction, multiplication, division, and modulo.
    Unary Operations: Trigonometric functions such as sine, cosine, and tangent.
    Negative Numbers: Handles unary negation properly.
    Decimal Support: Performs calculations involving floating-point numbers.
    Error Handling:
        Division by zero.
        Invalid input formats like consecutive decimals (..) or standalone decimals (.).
    GUI:
        Light blue buttons for numbers.
        Orange buttons for operators.
        Green button for the = operator.
    Keyboard-Free Interaction: All operations are performed using the provided buttons.

Project Structure

The project is divided into several components for better organization and modularity:
Core Classes

    CalculatorProcessor:
        Implements the Shunting-Yard algorithm to evaluate mathematical expressions in the correct order of operations.
        Handles all string parsing and calculations.
        Designed as a singleton for global access.

    ButtonFactory:
        Responsible for creating buttons for the GUI.
        Encapsulates button properties like labels, sizes, and colors.
        Simplifies button creation using factory methods.

    CalculatorFrame:
        The main GUI frame for the application.
        Handles user input and manages the layout of the calculator.

Testing

    Unit tests are implemented for both ButtonFactory and CalculatorProcessor using Microsoft's C++ Unit Test Framework.
    Tests cover various scenarios, such as:
        Valid and invalid input handling.
        Operator precedence and associativity.
        GUI button properties (e.g., labels, sizes, colors).

Installation and Usage
Prerequisites

    Visual Studio with C++ development environment installed.
    wxWidgets library configured in your project.
    Git (optional, for version control).

Clone the Repository

git clone <https://github.com/Roxythe/Calculator_App.git>
cd CalculatorApp

Build and Run

    Open the solution file (CalculatorApp.sln) in Visual Studio.
    Build the solution to compile the application.
    Run the application to start using the calculator.

Testing

    Open the solution file and set the Test Project (CalculatorAppTests) as the startup project.
    Run the unit tests using the Test Explorer in Visual Studio.

Known Issues

    No support for parentheses or advanced mathematical functions.

Future Improvements

    Parentheses Support: Add the ability to evaluate expressions with parentheses.
    Enhanced Trigonometric Functions: Support for degrees and radians.
    Theme Customization: Allow users to change button colors or themes.
    Keyboard Integration: Enable input from the keyboard.

License

This project is licensed under the MIT License.
Author

[Roxythe (Rocky) Harding]
A C++ student with a focus on game development and software design.
