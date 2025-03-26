//
// Created by Viola Durghalli on 11/4/24.
//

#include "Output_Functions.h"
#include <fstream>
#include <vector>
#include <string>
#include<algorithm>

void printEquation(int top, int bottom, char op, std::ostream &fout)
{
    /*
    int t = maxDigits(top, bottom);
    int b = t == top ? bottom : top;
    */
    int t, b;
    t = top;
    b = bottom;
    /*
    if(top>=bottom)
    {
        t = top;
        b = bottom;
    }
    else
    {
        t = bottom;
        b = top;
    }
    */
    int tCount = countDigits(t);
    int bCount = countDigits(b);

    if(tCount == bCount)
    {
        fout << std::setw(tCount + 1) << t << std::endl;
        fout << op << b<< std::endl;
    }
    else
    {
        fout << t << std::endl;
        fout << op << std::setw(tCount - 1) << b << std::endl;
    }
    fout << std::string(tCount+1, '-') << std::endl;

}

void printEquation(std::vector<int> carries, int top, int bottom, int answer, char op, std::ostream &cout)
{
    if(op == '+')
    {
        printCarries(carries, countDigits(top));

    }
    else if(op == '-')
    {
        printCarriesSub(carries, top);

    }
    else
    {
        printCarriesM(carries, top);
    }
    //beginning of the exact code as prior print function
    //just couldn't call it because i don't want it on a file yet.
    /*
    int t = maxDigits(top, bottom);
    int b = t == top ? bottom : top;
    */
    int t, b;
    /*
    if(t>=b)
    {
        t = top;
        b = bottom;
    }
    else
    {
        t = bottom;
        b = top;
    }
    */
    t= top;
    b = bottom;
    int tCount = countDigits(t);
    int bCount = countDigits(b);

    if(tCount == bCount)
    {
        std::cout << std::setw(tCount + 1) << t << std::endl;
        std::cout << op << b<< std::endl;
    }
    else
    {
        std::cout << t << std::endl;
        std::cout << op << std::setw(tCount - 1) << b << std::endl;
    }
    std::cout << std::string(tCount+1, '-') << std::endl;
    //end of codes same as prior printEquation function, but all the couts were fout in the other one.
    if(tCount == bCount)
        std::cout << std::setw(tCount+1) << answer << "\n" << std::endl;
    else
        std::cout << std::setw(tCount) << answer << "\n" << std::endl;

}

void add(int top, int bottom, std::ostream &cout)
{
    int t;
    if(bottom > top)
    {
        t = bottom;
        bottom = top;
        top = t;
    }
    //copied from subtract function


    int answer = top + bottom;;
    std::vector<int> carries;
    char op ='+';
    t = maxDigits(top, bottom);
    int tCount = countDigits(t);
    int bCount = countDigits(bottom);
    int tp = top;
    int bt = bottom;
    int steps =1;
    //std::cout << "\nStep 1:\n";
    printEquation(top, bottom, '+', cout);
    // carries.push_back(0);
    for(int i = 1; i < bCount; i++)
    {
        std::cout << "Step " << steps << ":\n";
        carries.push_back((tp%10 + bt%10) > 9 ? 1 : 0);
        printEquation(carries, top, bottom, answer%static_cast<int>(pow(10,i)), '+', cout);
        tp = tp/10;
        bt = bt/10;
        steps++;

    }
    std::cout << "Step " << steps<< ":\n";
    printEquation(carries, top, bottom, answer, '+', cout);
}

void printCarries(std::vector<int> carries, int space)
{
    std::string s;
    for(int i = carries.size()-1; i >= 0; i--)
    {
        if(carries.at(i) > 0)
        {
            s += std::to_string(carries.at(i));
        }
        else
            s +=  " ";
    }
    std::cout << std::setw(space) << s <<  std::endl;
}
void generateRandProblems(std::string arr[][100], int &numUsed, int numProblems)
{
    int tCount;
    char op;
    for(int i = 0; i<numProblems; i++)
    {
        ///generate two integers

        int num1 = rand() % 1000;
        int num2 = rand() % 1000;
        ///if int1 > int2 make int1 the top else make int 2 the top
        ///then put in arr
        if(num1>= num2)
        {
            arr[0][i] = std::to_string(num1);
            tCount = arr[0][i].size() + 1;
            //arr[1][i] = "+" + std::to_string(num2);// this will be where randOp should be called
            arr[1][i] = randOperator(op) + std::to_string(num2);
            //randOperator(op);
            arr[2][i] =  std::string(tCount, '-');
        }
        else
        {
            arr[0][i] = std::to_string(num2);
            tCount = arr[0][i].size() + 1;
            arr[1][i] = "+" + std::to_string(num1);
            arr[2][i] =  std::string(tCount, '-');
        }
        numUsed++;
    }
}

void printRandProblems(std::string arr[][100], int numUsed, int cols)
{

    std::ofstream fout;
    //Attach a file to fout
    fout.open("quiz.txt");
    //
    // //Check if file opened successfully
    if(fout.fail())
    {
         std::cout << "Can not open file.";
         exit(28);
     }


    fout << "Solve the following equations: \n" << std::endl;
    int loops = 0;
    int number = 1;
    while(loops < numUsed)
    {
        for(int i = 0; i<3; i++)
        {
            for(int j = 0; j<cols; j++)
            {
                // if(i==0 && number <= numUsed)
                // {
                // fout << std::setw(7) << number << ") " << arr[i][j+loops];
                //     number++;
                // }
                // else
                    fout << std::setw(12) << arr[i][j+loops];
            }
            fout << std::endl;
        }
        loops += cols;
    }
}

void printAnswer(std::string arr[][100], int numUsed)
{
    int top;
    int bottom;
    add(top, bottom, std::cout);
}
void run()
{
    srand(time(0));
    std::vector<int> carries;
    int answer = 0;


    int top;
    int bottom;
    int equations;
    char type1, type2, type3;
    std::cout << "Enter the number of equations you would like: " ;
    std::cin >> equations;

     std::cout << "Enter three types of equations you would like your exam to contain.(+,-,*,/):" << std::endl;
     //std::cin >> type1 >> type2 >> type3;

     std::ofstream fout;

    //Attach a file to fout
     fout.open("file1.txt");

     //Check if file opened successfully
     if(fout.fail())
     {
         std::cout << "Can not open file.";
         exit(28);
     }
     int count = 1;
     while(count <= equations)
     {
     top = rand()%5001;
     bottom= rand()%5001;
         printEquation(top, bottom, '+', fout);
         count++;
     }


     //Always close the file when finished
     fout.close();


     add(456, 589, std::cout);



     int i = 1;
     while(i <= equations)
     {
         top = rand()%5001;
         bottom= rand()%5001;
         printEquation(carries, top, bottom, answer, '+', std::cout);
         i++;
     }


    int numUsed;
    std::string arr[100][100];
    int rows;
    int cols;
    int num1, num2;
    std::cout << "Enter the amount of columns you would like: ";
    std::cin >> cols;
    generateRandProblems(arr, numUsed, equations);
    printRandProblems(arr, numUsed, cols);
    //accessEquation(arr[][100], rows, cols, equations);
    add(top, bottom, std::cout);


    //subtract(1004, 935, std::cout);
    //add(456, 589, std::cout);

}

void test()
{
    srand(time(0));

    int equations;
    std::cout << "Enter the number of equations you would like: " ;
    std::cin >> equations;

    int numUsed;
    std::string arr[100][100];
    int cols;
    int num1, num2;
    std::cout << "Enter the amount of columns you would like: ";
    std::cin >> cols;
    if(equations%cols != 0)
    {
        while(equations%cols != 0)
        {
            std::cout << "Invalid input. \nEnter the amount of columns you would like: ";
            std::cin >> cols;
        }
    }


    generateRandProblems(arr, numUsed, equations);
    printRandProblems(arr, numUsed, cols);

    std::ifstream fin;

    //// attach a file to the ifstream object
    fin.open("quiz.txt");

    //// check if the file attached properly
    if(fin.fail())
        exit(23);

    /// we need a variable to store values from the file
    std::string next;
    int num;

    getline(fin, next);

    // std::cout << "We got " << next;
    // fin >> num;
    // std::cout << num;
    // fin >> num;
    // std::cout << num;

    std::string arr2[100][100]; //will hold the values from the file

    int rows;
    //find rows
    // if(equations%cols == 0)
    {
        rows =3* equations/cols;
    }
    // else
    // {
    //     rows=(3*equations/cols)+3;
    // }

    for(int j = 0; j<rows; j++) //This loop accesses each equation
    {
        for(int i = 0; i<cols;i++)
        {
            fin>> arr2[j][i];
        }
    }
/*
    for(int i=0; i<3*equations; i++)
    {
        fin >> arr2[col][0];
        fin >> arr2[col][1];
        fin >> arr2[col++][2];

    }
    */
    for(int j = 0; j<rows; j++) // prints each equation to the console
    {
        for(int i = 0; i<cols;i++)
        {
            std::cout << std::setw(10) << arr2[j][i];
        }
        std::cout << std::endl;
    }
    //std::cout << rows << ", " << cols << ", " << equations<<std::endl;
    accessEquation(arr2, 0, cols, equations); // the problem was that i had been calling this with rows instead of using zero
    //finalMultiply(top, bottom, std::cout);

    //add(top, bottom, &cout);
    //multiply1(758,8, std::cout);

}

void fileRead()
{
    //// To read a file, you sust create a ifstream object
    std::ifstream fin;

    //// attach a file to the ifstream object
    fin.open("quiz.txt");

    //// check if the file attached properly
    if(fin.fail())
        exit(23);

    /// we need a variable to store values from the file
    std::string next;
    int num;

    getline(fin, next);

    std::cout << "We got " << next;
    fin >> num;
    std::cout << num;
    fin >> num;
    std::cout << num;




}

void accessEquation(std::string arr2[][100], int rows, int cols, int equations)
{
    // std::ofstream fout; jk cant get it to work on the file

    int probCounter = 1;
    int top;
    int bottom;
    std::string bottomFixed; //this is to separate the '+' from the bottom number
    //while(rows * cols < equations)

    while(rows * cols < 3 * equations)
    {
/*
        std::ofstream fout;
        //Attach a file to fout
        fout.open("quiz.txt");
        //
        // //Check if file opened successfully
        if(fout.fail())
        {
            std::cout << "Can not open file.";
            exit(28);
        }

*/

        for (int i = 0; i < cols; ++i)
        {
            std::cout << "\nProblem " << probCounter << ")\n";

            //arr2[rows][i]; //this will access the top of every equation
            top = std::stoi(arr2[rows][i]); //changes the number accessed in the array from string to int
            std::cout << std::setw(10) << arr2[rows][i] << std::endl;
            std::cout << std::setw(10) << arr2[rows + 1][i] << std::endl; //this will access the bottom
            bottomFixed = (arr2[rows + 1][i]).substr(1);
            bottom = std::stoi(bottomFixed); //takes the code of the array that gets the bottom number and makes it an int
            std::cout << std::setw(10) << arr2[rows + 2][i] << std::endl; //this accesses the ---- holder
            //dont forget to change them from string to int before putting them into a top & bottom variable.

            std::cout << "Top: " << top << std::endl;
            std::cout << "Bottom: " << bottom << std::endl;
            //add(top, bottom, std::cout);
            //subtract(top, bottom, std::cout);
            //idea for checking the type of equation it is
            //do if (arr2[rows+1][i]).substr(put the right number idk where the char is, i think it would be (0,1))
            //then make separate if statements with the code above to check if it equals '-', '+', or 'x' then call the matching functions
            char op = arr2[rows+1][i].at(0);
            if(op == '+')
            {
                add(top, bottom, std::cout);
            }
            else if(op == '-')
            {
                subtract(top, bottom, std::cout);
            }
            else
                finalMultiply(top, bottom, std::cout);

            probCounter++;
        }
        rows += 3;

    }
}

void subtract(int top, int bottom, std::ostream &cout)
{
    std::vector<int> carries2;
    char op ='-';
    int t;

    if(bottom > top)
    {
        t = bottom;
        bottom = top;
        top = t;
    }
    t = maxDigits(top, bottom);

    int answer = top - bottom;;

    int tCount = countDigits(t);
    int bCount = countDigits(bottom);
    int tp = top;
    int bt = bottom;
    int steps =1;
    //std::cout << "\nStep 1:\n";
    printEquation(top, bottom, '-', cout);
    // carries.push_back(0);
    for(int i = 1; i < bCount; i++)
    {
        std::cout << "Step " << steps << ":\n";
        //carries.push_back((tp%10 + bt%10) > 9 ? 1 : 0); // this is the carries for addition
        if(tp%10 < bt%10)
        {
            carries2.push_back((tp%10)+10);
        }
        else
        {
            carries2.push_back(0);
        }
        printEquation(carries2, top, bottom, answer%static_cast<int>(pow(10,i)), '-', cout);
        tp = tp/10;
        bt = bt/10;
        steps++;

    }
    std::cout << "Step " << steps<< ":\n";
    printEquation(carries2, top, bottom, answer, '-', cout);
}

void printCarriesSub(std::vector<int> carries, int top)
{
    int space = countDigits(top);
    std::string s;
    for(int i = carries.size()-1; i >= 0; i--)
    {
        if(carries.at(i) > 0)
        {
            if(i > 0 && carries.at(i-1) != 0)
            {
                s += std::to_string(carries.at(i)-1);
            }
            else
            s += std::to_string(carries.at(i));
        }
        else
            s +=  " ";
    }
    std::cout << std::setw(space+1) << s <<  std::endl;
}

void multiply1(int top, int bottom, std::ostream &cout)
{
    int t;
    if(bottom > top)
    {
        t = bottom;
        bottom = top;
        top = t;
    }
    //copied from subtract function


    int answer = top * bottom;;
    std::vector<int> carries3;
    char op ='x';
    t = maxDigits(top, bottom);
    int tCount = countDigits(t);
    int bCount = countDigits(bottom);
    int tp = top;
    int bt = bottom;
    int steps =2;
    //std::cout << "\nStep 1:\n";
    printEquation(top, bottom, 'x', cout);
    // carries.push_back(0);
    for(int i = 1; i < tCount; i++)
    {
        std::cout << "Part " << steps << ":\n";
        carries3.push_back((tp%10 * bt) > 9 ? (tp%10 * bt/10) : 0);
        printEquation(carries3, top, bottom, answer%static_cast<int>(pow(10,i)), 'x', cout);
        tp = tp/10;
        //bt = bt/10;
        steps++;

    }
    std::cout << "Part " << steps<< ":\n";
    printEquation(carries3, top, bottom, answer, 'x', cout);
}

void printCarriesM(std::vector<int> carries, int top)
{
    int space = countDigits(top);
    std::string s;
    for(int i = carries.size()-1; i >= 0; i--)
    {
        if(carries.at(i) > 0)
        {
            if(i > 0 && carries.at(i-1) != 0)
            {
                s += std::to_string((carries.at(i)*10+carries.at(i-1))/10);
            }
            else
                s += std::to_string(carries.at(i));
        }
        else
            s +=  " ";

    }
    std::cout << std::setw(space-1) << s <<  std::endl;
}

void finalMultiply(int top, int bottom, std::ostream &cout)
{
    printEquation(top, bottom, 'x', std::cout);

    //std::cout << top << " = " top/pow(10,i);
    int bt = bottom;
    int i =1;
    int j = 0;
    int answer[4];
    //std::vector<int> answer;
    //int size = 10;
    int step = 1;
    while(bt > 0)
    {
        std::cout << "Step " << step << ")\nPart 1\n" ;
        multiply1(top, bt%10, cout);
        step++;
        answer[j] = top * (bt%10);
        bt /= 10;
        i *= 10;
        answer[j+1] = 0;
        j++;
    }

    //int total = 0;
    for(int z = 0; z <= 2; z++)
    {
        if(z == 0) //(answer[z+1] != 0 && z == 0)
        {
            std::cout << answer[z] << " + ";
            //total += answer[z];
        }
        else if(z < 2 && answer[z+1] != 0)
        {
            std::cout << answer[z] << "(" << pow(10,z) << ") + ";
            //total += answer[z]* pow(10, z);
        }
        else
        {
            //total += answer[z];
            std::cout << answer[z] << "(" << pow(10,z) << ")" << " = " << top*bottom;

            break;
        }
    }
    std::cout << "\nTherefore, " <<top << " x " <<bottom << " = " << top*bottom;
}

char randOperator(char &op)
{
    //42, 43, 45
    int opBefore; //holds the value before making it a char
    opBefore = rand() % (45 - 42 + 1) +42;

    while(opBefore == 44)
    {
        opBefore = rand() % (45 - 42 + 1) +42;
    }

    op = static_cast<char>(opBefore);
    return op;
}