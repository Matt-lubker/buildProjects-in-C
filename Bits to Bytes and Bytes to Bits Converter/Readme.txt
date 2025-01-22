# Bits to Bytes and Bytes to Bits Converter

## Overview
This C program is a simple, menu-driven application that allows users to convert:
- **Bits to Bytes**
- **Bytes to Bits**

It uses clear input/output formatting and validates user input to ensure the program is easy and reliable to use.

---

## Features
1. **Bits to Bytes Conversion**:
   - Converts the number of bits to bytes using the formula:
     \[ \text{bytes} = \frac{\text{bits}}{8.0} \]
   - Outputs the result with two decimal places.

2. **Bytes to Bits Conversion**:
   - Converts the number of bytes to bits using the formula:
     \[ \text{bits} = \text{bytes} \times 8 \]

3. **Input Validation**:
   - Ensures no negative values are accepted for both bits and bytes.
   - Provides error messages for invalid inputs.

4. **Menu-Driven Design**:
   - Easy navigation with options to:
     1. Convert bits to bytes.
     2. Convert bytes to bits.
     3. Exit the program.
   - Loops until the user chooses to exit.

---

## How to Use
1. Compile the program using a C compiler:
   ```bash
   gcc -o converter converter.c
   ```

2. Run the compiled program:
   ```bash
   ./converter
   ```

3. Follow the prompts:
   - Choose an option from the menu by entering the corresponding number (1, 2, or 3).
   - Enter the value for conversion when prompted.
   - View the results printed to the console.

4. Repeat or exit:
   - The program will return to the main menu after each conversion.
   - Choose option 3 to exit the program.

---

## Example Usage
### Menu Display:
```
Conversion Menu:
1. Convert bits to bytes
2. Convert bytes to bits
3. Exit
Enter your choice (1-3):
```

### Sample Conversions:
#### Bits to Bytes:
Input:
```
Enter the number of bits: 16
```
Output:
```
16 bits = 2.00 bytes
```

#### Bytes to Bits:
Input:
```
Enter the number of bytes: 5
```
Output:
```
5 bytes = 40 bits
```

---

## Error Handling
- **Negative Input**:
  - If a user enters a negative number for bits or bytes, the program will display an error message:
    ```
    Number of bits/bytes cannot be negative.
    ```

- **Invalid Menu Choice**:
  - If the user enters an invalid menu option, the program will prompt them to try again:
    ```
    Invalid choice. Please try again.
    ```

---

## Program Structure
1. **`main` Function**:
   - Displays the menu and handles user input.
   - Calls the appropriate conversion function based on user choice.

2. **`bitsToBytes` Function**:
   - Handles bits-to-bytes conversion and displays the result.

3. **`bytesToBits` Function**:
   - Handles bytes-to-bits conversion and displays the result.

---

## License
This program is open-source and can be used, modified, and distributed freely.

