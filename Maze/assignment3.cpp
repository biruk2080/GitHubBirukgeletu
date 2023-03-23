#include <iostream>
#include <fstream>
#include <cstdlib>
#include "maze.h"
#include "creature.h"
using namespace std;
int Test1()
{
    cout << "Test 1 for maze.txt:" << endl;
    cout << endl;
    Maze maze1("maze1.txt");
    cout << "Solve this maze: " << endl;
    cout << maze1 << endl;
    
    Creature c1(5, 17);
    cout << "Path: " << c1.Solve(maze1) << endl;
    
    
    cout << maze1 << endl;
    cout << c1 << endl;
    return 0;
}

int Test2()
{
    cout << "Test 2 for maze.txt:" << endl;
    cout << endl;
    Maze maze2("maze.txt");
    cout << "Solve this maze: " << endl;
    cout << maze2 << endl;
    
    Creature c2(5, 1);
    cout << "Path: " << c2.Solve(maze2) << endl;
    
    
    cout << maze2 << endl;
    cout << c2 << endl;
    
    return 0;
}

int Test3()
{
    cout << "Test 3 for maze.txt:" << endl;
    cout << endl;
    Maze maze3("maze.txt");
    cout << "Solve this maze: " << endl;
    cout << maze3 << endl;
    
    Creature c3(5, 12);
    cout << "Path: " << c3.Solve(maze3) << endl;
    
    
    cout << maze3 << endl;
    cout << c3 << endl;
    
    return 0;
}

int Test()
{
    cout << "Test 4 for maze100.txt:" << endl;
    cout << endl;
    Maze maze4("maze100.txt");
    cout << "Solve this maze: " << endl;
    cout << maze4 << endl;
    
    Creature c4(1, 1);
    cout << "Path: " << c4.Solve(maze4) << endl;
    
    cout << maze4 << endl;
    cout << c4 << endl;
    
    return 0;
    return 0;
}
int Test4()
{
    cout << "Test 4 for maze0.txt:" << endl;
    cout << endl;
    Maze maze("maze0.txt");
    cout << "Solve this maze: " << endl;
    cout << maze << endl;
    
    Creature c(3, 1);
    cout << "Path: " << c.Solve(maze) << endl;
    
    cout << maze << endl;
    cout << c << endl;
    
    return 0;
}

int Test5()
{
    cout << "Test 5 for maze0.txt:" << endl;
    cout << endl;
    Maze maze5("maze0.txt");
    cout << "Solve this maze: " << endl;
    cout << maze5 << endl;
    
    Creature c5(1, 3);
    cout << "Path: " << c5.Solve(maze5) << endl;
    
    cout << maze5 << endl;
    cout << c5 << endl;
    
    return 0;
}

int Test6()
{
    cout << "Test 6 for maze0.txt:" << endl;
    cout << endl;
    Maze maze6("maze0.txt");
    cout << "Solve this maze: " << endl;
    cout << maze6 << endl;
    
    Creature c6(2, 7);
    cout << "Path: " << c6.Solve(maze6) << endl;
    
    cout << maze6 << endl;
    cout << c6 << endl;
    
    return 0;
}

int Test7()
{
    cout << "Test 7 for mazeSimple.txt:" << endl;
    cout << endl;
    Maze maze7("mazeSimple.txt");
    cout << "Solve this maze: " << endl;
    cout << maze7 << endl;
    
    Creature c7(5, 8);
    cout << "Path: " << c7.Solve(maze7) << endl;
    
    cout << maze7 << endl;
    cout << c7 << endl;
    
    return 0;
}

int Test8()
{
    cout << "Test 8 for testMaze.txt:" << endl;
    cout << endl;
    Maze maze7("testMaze.txt");
    cout << "Solve this maze: " << endl;
    cout << maze7 << endl;
    
    Creature c7(1, 1);
    cout << "Path: " << c7.Solve(maze7) << endl;
    
    cout << maze7 << endl;
    cout << c7 << endl;
    
    return 0;
}

int main()
{
    Test1();
    // Test2();
    // Test3();
    // Test4();
    // Test5();
    // Test6();
    // Test7();
    // Test8();
    
    return 0;
}