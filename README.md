# Qt
This project implemented in QT c++. Mainwindow.cpp is the cpp file that contains all button connections and functions.It can perform 4 basic operations. It has also integers for decimal and hexadecimal modes. 
The calculator has 16 buttons :
Hex and Dec buttons determine in which mode the operations are performed. Hex is for hexadecimal, Dec is for decimal.
 +, -, *, / are the four basic operations. + button performs the summation operation. - button performs the subtraction operation. * button performs the multiplication operation. / button performs the division operation.
 = button shows the result of operations. 
clr button clears the screen of the calculator and it resets all values. The calculator returns to its initial state. 
Other buttons are integers that can be used in operations. 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 buttons can be used in both modes. However, A, B, C, D, E, F buttons can be only used in hexadecimal mode. It gives result in the mode which is selected. If the hex button is pressed, the result will be in hexadecimal mode. Otherwise, it will be in decimal.
In this implementation, when you press the = button, it shows the result of all operations up to now on the screen. However, it does not show any result before pressing = button. If you want to see the result, you should press = button. Then, you can move on the other operations. Additionally, you cannot use both mode in same operation. You must use them in separately (hex or dec). Default value for the mode is decimal. If you do not press any mode, it makes all operations in decimal mode. Moreover, you cannot divide any number with 0. Dividing with 0 gives an error message, like “wrong operation, press clear button”. You must press clr button to start again. 
 
