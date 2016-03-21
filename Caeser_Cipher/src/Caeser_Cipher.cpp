//============================================================================
// Name        : Caeser_Cipher.cpp
// Author      : Vivek
// Version     :
// Copyright   : Copyright Vivek Malik, 2011
// Description : Hello World in C++, Ansi-style
//============================================================================

/*#include <iostream>
using namespace std;

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}

#include <string>
#include <iostream>
#include <algorithm>
#include <cctype>

class MyTransform {
private :
   int shift ;
public :
   MyTransform( int s ) : shift( s ) { }

  char operator( )( char c ) {
      if ( isspace( c ) )
	 return ' ' ;
      else {
	 static std::string letters( "abcdefghijklmnopqrstuvwxyz" ) ;
	 std::string::size_type found = letters.find(tolower( c )) ;
	 int shiftedpos = ( static_cast<int>( found ) + shift ) % 26 ;
	 if ( shiftedpos < 0 ) //in case of decryption possibly
	    shiftedpos = 26 + shiftedpos ;
	 char shifted = letters[shiftedpos] ;
	 return shifted ;
      }
  }
} ;

int main( ) {
   std::string input ;
   std::cout << "Which text is to be encrypted ?\n" ;
   getline( std::cin , input ) ;
   std::cout << "shift ?\n" ;
   int myshift = 0 ;
   std::cin >> myshift ;
   std::cout << "Before encryption:\n" << input << std::endl ;
   std::transform ( input.begin( ) , input.end( ) , input.begin( ) ,
	 MyTransform( myshift ) ) ;
   std::cout << "encrypted:\n" ;
   std::cout << input << std::endl ;
   myshift *= -1 ; //decrypting again
   std::transform ( input.begin( ) , input.end( ) , input.begin( ) ,
	 MyTransform( myshift ) ) ;
   std::cout << "Decrypted again:\n" ;
   std::cout << input << std::endl ;
   return 0 ;
}*/


#include <stdio.h>
#include<iostream>
#include <string.h>

using namespace std;

int main(){
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	char plain[200], cipher[200], decipher[200];

	int a=0, key=3, i=0;  //Caesar cipher key is 3

	memset(plain, NULL, sizeof(plain));
	memset(cipher, NULL, sizeof(cipher));
	memset(decipher, NULL, sizeof(decipher));

	//printf(“Enter the text to be encrypted : “);
	cout<<"Enter the text to be encrypted :";
	gets(plain);
	/* Uncomment if you wish to change the default key (3)

	cout<<"\nEnter Key :";
	cin>>key;

	 */
	//scanf(“%s”, plain);
	cout<<"\nPlain text  :"<<plain;
	//printf(“\n Plain text  : %s\n”, plain);

	/* Encryption */

	while( plain[i] != NULL){
		a = plain[i];
		a = a+key;
		cipher[i] = a;
		i++;
	}
	//printf(“\nEncrypted text : %s\n”, cipher);
	cout<<"\nEncrypted Text: "<<cipher;
	i=0;

	/* Decryption */

	while(cipher[i] != NULL){
		a = cipher[i];
		a = a-key;
		decipher[i] = a;
		i++;
	}

	//printf(“\nDecrypted text : %s\n”, decipher);
	cout<<"\nDecrypted Text :"<<decipher;
	return(0);
}
