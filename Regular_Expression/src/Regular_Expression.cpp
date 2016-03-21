//============================================================================
// Name        : Regular_Expression.cpp
// Author      : Vivek
// Version     :
// Copyright   : Copyright Vivek Malik, 2011
// Description : Regular Expression for (a|b)*abb
//============================================================================

/*#include <iostream>
using namespace std;

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}*/

/*
 * regex.cpp
 *
 *  Created on: 11-Dec-2013
 *      Author: vivek
 */
#include <iostream>
#include <cassert>
#include <string>

using namespace std;

typedef int     fsm_state;
typedef char    fsm_input;


bool is_final_state(fsm_state state)
{
    return (state == 3) ? true : false;
}


fsm_state get_start_state(void)
{
    return 0;
}


fsm_state move(fsm_state state, fsm_input input)
{
    // our alphabet includes only 'a' and 'b'
    if (input != 'a' && input != 'b')
        assert(0);

    switch (state)
    {
        case 0:
            if (input == 'a')
            {
                return 1;
            }
            else if (input == 'b')
            {
                return 0;
            }
            break;

        case 1:
            if (input == 'a')
            {
                return 1;
            }
            else if (input == 'b')
            {
                return 2;
            }
            break;

        case 2:
            if (input == 'a')
            {
                return 1;
            }
            else if (input == 'b')
            {
                return 3;
            }
            break;

        case 3:
            if (input == 'a')
            {
                return 1;
            }
            else if (input == 'b')
            {
                return 0;
            }
            break;

        default:
            assert(0);
    }
}


bool recognize(string str)
{
    if (str == "")
        return false;

    fsm_state state = get_start_state();

    string::const_iterator i = str.begin();
    fsm_input input = *i;

    while (i != str.end())
    {
        state = move(state, *i);
        ++i;
    }

    if (is_final_state(state)){
    	cout<<"Regular Expression Okay";
    	return true;
    }

    else{
    	cout<<"Not Okay";
        return false;
    }
}

// simple driver for testing
int main(){
//int main(int argc, char** argv)
//{
//    recognize(argv[1]) ? cout << 1 : cout << 0;
	recognize("aababaaabababababb");

    return 0;
}

