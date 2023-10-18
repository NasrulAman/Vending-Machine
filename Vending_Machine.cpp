#include <string>
#include <iomanip>
#include <iostream>
#include <windows.h>
#include <fstream>
#include <stdio.h>
#include <map>
#include<vector>
#include<sstream>

using namespace std;




//receipt function prototype

void receipt(float,float,float,string);
 






//Text Color

class Color{ 
  public: 
         Color(int desiredColor){ 
             consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE); 
             color = desiredColor; 
         } 
 
         friend ostream& operator<<(ostream& ss, Color obj){ 
             SetConsoleTextAttribute(obj.consoleHandle, obj.color); 
             return ss; 
         } 
  private: 
         int color; 
         HANDLE consoleHandle; 
}; 

	    
int main()


{
	
	
//FONT 

CONSOLE_FONT_INFOEX cfi;
cfi.cbSize = sizeof(cfi);
cfi.nFont = 5;
cfi.dwFontSize.X = 0;                   // Width of each character in the font
cfi.dwFontSize.Y = 15;                  // Height
cfi.FontFamily = FF_DONTCARE;
cfi.FontWeight = FW_HEAVY;

SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);

//variable declaration
    
	int quantity,number,z = 0, sum = 0,k = 0,l = 0;
	
	char yesno;
	
	float money, price, newprice, change, remaining, newremaining;
	
	string icon,strToReturn;
	
		
	// set array for product 
	
	string flavour [12] = {"Vanilla","Cinnamon", "Mint", "Lime",
	 
						 "Matcha", "Chocolate", "Coffee", "Strawberry",
						   
						 "BubbleTea", "SaltedCaramel","CookieNcream","MusangKing"};
		
	//icon declaration	
	
	icon[1] = 16;
	icon[2] = 17;
	    
	
        
    // Shop name and Menu
    
{
cout << Color(11) << "\t\t\t\t\t\t*************************************************************************************************                                       "        << endl;
cout <<              "\t\t\t\t\t\t*                                                                                               *                                       "        << endl;                                                                     
cout <<              "\t\t\t\t\t\t*" << Color(3) << "                       * * * *      *    *           *     * * * * *   " << Color(11) << "                        *  "        << endl;           
cout <<              "\t\t\t\t\t\t*" << Color(3) << "                       *       *    *    * *         *   *             " << Color(11) << "                        *  "        << endl;
cout <<              "\t\t\t\t\t\t*" << Color(3) << "                       *       *    *    *   *       *   *             " << Color(11) << "                        *  "        << endl;          
cout <<              "\t\t\t\t\t\t*" << Color(3) << "                       * * * *      *    *     *     *   *      * * *  " << Color(11) << "                        *  "        << endl;                             
cout <<              "\t\t\t\t\t\t*" << Color(3) << "                       *       *    *    *       *   *   *           * " << Color(11) << "                        *  "        << endl;                             
cout <<              "\t\t\t\t\t\t*" << Color(3) << "                       *       *    *    *         * *   *           * " << Color(11) << "                        *  "        << endl;                                   
cout <<              "\t\t\t\t\t\t*" << Color(3) << "                       * * * *      *    *           *     * * * * *   " << Color(11) << "                        *  "        << endl;
cout <<              "\t\t\t\t\t\t*                                                                                               *  "                                             << endl;
cout <<              "\t\t\t\t\t\t*" << Color(3) << "      * * * * *    *       *   *    *         *          *    *           *      * * * * *   " << Color(11) << "  *  "        << endl;
cout <<              "\t\t\t\t\t\t*" << Color(3) << "    *              *       *   *    *         *          *    * *         *    *             " << Color(11) << "  *  "        << endl;
cout <<              "\t\t\t\t\t\t*" << Color(3) << "    *              *       *   *    *         *          *    *   *       *    *             " << Color(11) << "  *  "        << endl;
cout <<              "\t\t\t\t\t\t*" << Color(3) << "    *              * * * * *   *    *         *          *    *     *     *    *      * * *  " << Color(11) << "  *  "        << endl;
cout <<              "\t\t\t\t\t\t*" << Color(3) << "    *              *       *   *    *         *          *    *       *   *    *           * " << Color(11) << "  *  "        << endl;
cout <<              "\t\t\t\t\t\t*" << Color(3) << "    *              *       *   *    *         *          *    *         * *    *           * " << Color(11) << "  *  "        << endl;
cout <<              "\t\t\t\t\t\t*" << Color(3) << "      * * * * *    *       *   *    * * * *   * * * *    *    *           *      * * * * *   " << Color(11) << "  *  "        << endl;
cout <<              "\t\t\t\t\t\t*                                                                                               *   "                                            << endl;
cout <<              "\t\t\t\t\t\t*" << Color(11) << "************************************************************************************************   "                         << endl;
cout <<              "\t\t\t\t\t\t*" << Color(6) << "   * * * * *     * * * * *     * * * * *     * * * * * " << Color(11) << "   * " << Color(15) << "  ______________________________  " << Color(11) << " *\t                                                  "                     << endl;
cout <<              "\t\t\t\t\t\t*" << Color(6) << "   *       *     *       *     *       *     *       * " << Color(11) << "   * " << Color(15) << " |                              | " << Color(11) << " *\t                                                  "                     << endl;
cout <<              "\t\t\t\t\t\t*" << Color(6) << "   *   1   *     *   2   *     *   3   *     *   4   * " << Color(11) << "   * " << Color(15) << " |           WELCOME            | " << Color(11) << " *\t                                                  "                     << endl;                                                                                
cout <<              "\t\t\t\t\t\t*" << Color(6) << "   *       *     *       *     *       *     *       * " << Color(11) << "   * " << Color(15) << " |                              | " << Color(11) << " *\t" << Color(8) << "          * * * * * * *         "                     << endl;
cout <<              "\t\t\t\t\t\t*" << Color(6) << "   * * * * *     * * * * *     * * * * *     * * * * * " << Color(11) << "   * " << Color(15) << " |             T O              | " << Color(11) << " *\t" << Color(8) << "        *               *       "                     << endl;
cout <<              "\t\t\t\t\t\t*" << Color(2) << "    Vanilla       Cinnamon       Mint          Lime    " << Color(11) << "   * " << Color(15) << " |                              | " << Color(11) << " *\t" << Color(8) << "      *                   *     "                     << endl;
cout <<              "\t\t\t\t\t\t*" << Color(7) << "    RM 1.00       RM 2.00       RM 2.00       RM 2.00  " << Color(11) << "   * " << Color(15) << " |        BING CHILLING!        | " << Color(11) << " *\t" << Color(8) << "     *    * * * * * * *    *    "                     << endl;
cout <<              "\t\t\t\t\t\t*" << Color(11)<< "                                                       " << Color(11) << "   * " << Color(15) << " |                              | " << Color(11) << " *\t" << Color(8) << "    *   *               *   *   "                     << endl;
cout <<              "\t\t\t\t\t\t*" << Color(6) << "   * * * * *     * * * * *     * * * * *     * * * * * " << Color(11) << "   * " << Color(15) << " |                              | " << Color(11) << " *\t" << Color(8) << "   *   *                 *   *  "                     << endl;
cout <<              "\t\t\t\t\t\t*" << Color(6) << "   *       *     *       *     *       *     *       * " << Color(11) << "   * " << Color(15) << " |       Touch The Screen       | " << Color(11) << " *\t" << Color(8) << "   *   *                 *   *  "                     << endl;
cout <<              "\t\t\t\t\t\t*" << Color(6) << "   *   5   *     *   6   *     *   7   *     *   8   * " << Color(11) << "   * " << Color(15) << " |         To Continue...       | " << Color(11) << " *\t" << Color(8) << "   *   * * * * * * * * * *   *  "                     << endl;
cout <<              "\t\t\t\t\t\t*" << Color(6) << "   *       *     *       *     *       *     *       * " << Color(11) << "   * " << Color(15) << " |                              | " << Color(11) << " *\t" << Color(8) << "   *                         *  "                     << endl;
cout <<              "\t\t\t\t\t\t*" << Color(6) << "   * * * * *     * * * * *     * * * * *     * * * * * " << Color(11) << "   * " << Color(15) << " |______________________________| " << Color(11) << " *\t" << Color(8) << "   ***************************  "                     << endl;
cout <<              "\t\t\t\t\t\t*" << Color(13)<< "    Matcha       Chocolate      Coffee      Strawberry " << Color(11) << "   * " << Color(15) << "   _______________      _______   " << Color(11) << " *\t" << Color(8) << "   |                         |  "                     << endl;
cout <<              "\t\t\t\t\t\t*" << Color(7) << "    RM 2.00       RM 2.00       RM 3.00       RM 3.00  " << Color(11) << "   * " << Color(15) << "  |_______________|    |_______|  " << Color(11) << " *\t" << Color(8) << "   ***************************  "                     << endl;
cout <<              "\t\t\t\t\t\t*" << Color(11)<< "                                                       " << Color(11) << "   * " << Color(15) << "                                  " << Color(11) << " *\t" << Color(8) << "    *\t\t\t    * "                                    << endl;
cout <<              "\t\t\t\t\t\t*" << Color(6) << "   * * * * *     * * * * *     * * * * *     * * * * * " << Color(11) << "   * " << Color(15) << "                                  " << Color(11) << " *\t" << Color(8) << "    *\t\t\t    * "                                    << endl;
cout <<              "\t\t\t\t\t\t*" << Color(6) << "   *       *     *       *     *       *     *       * " << Color(11) << "   * " << Color(10) << "      **              * * *       " << Color(11) << " *\t" << Color(8) << "    *\t\t\t    * "                                    << endl;
cout <<              "\t\t\t\t\t\t*" << Color(6) << "   *   9   *     *  1 0  *     *  1 1  *     *  1 2  * " << Color(11) << "   * " << Color(10) << "    *    *          *       *     " << Color(11) << " *\t" << Color(8) << "    *\t" << Color(7) << "        *    \t" << Color(8) << "    * "                                    << endl;
cout <<              "\t\t\t\t\t\t*" << Color(6) << "   *       *     *       *     *       *     *       * " << Color(11) << "   * " << Color(10) << "   *      *       *           *   " << Color(11) << " *\t" << Color(8) << "    *\t" << Color(7) << "       * *   \t" << Color(8) << "    * "                                    << endl;
cout <<              "\t\t\t\t\t\t*" << Color(6) << "   * * * * *     * * * * *     * * * * *     * * * * * " << Color(11) << "   * " << Color(10) << "  *        *     *             *  " << Color(11) << " *\t" << Color(8) << "    *\t" << Color(7) << "      *   *  \t" << Color(8) << "    * "                                    << endl;
cout <<              "\t\t\t\t\t\t*" << Color(12)<< "    Bubble        Salted        Cookies&      Musang   " << Color(11) << "   * " << Color(10) << "  *        *     *             *  " << Color(11) << " *\t" << Color(8) << "    *\t         \t    * "                                    << endl;
cout <<              "\t\t\t\t\t\t*" << Color(12)<< "     Tea          Caramel        Cream         King    " << Color(11) << "   * " << Color(10) << "  *        * "<< Color(14) << "    ***************" << Color(11) << "   *\t" << Color(8) << "    *\t\t\t    *" << endl;
cout <<              "\t\t\t\t\t\t*" << Color(7) << "    RM 4.00       RM 4.00       RM 4.00       RM 5.00  " << Color(11) << "   * " << Color(10) << "  *        * "<< Color(14) << "     *           *" << Color(11) << "    *\t" << Color(8) << "    *\t" << Color(7) << "   *         *  " << Color(8) << "    *" << endl;
cout <<              "\t\t\t\t\t\t*" << Color(11)<< "                                                       " << Color(11) << "   * " << Color(10) << "  *        * "<< Color(14) << "      *         *" << Color(11) << "     *\t" << Color(8) << "    *\t" << Color(7) << "  *           * " << Color(8) << "    *" << endl;
cout <<              "\t\t\t\t\t\t*" << Color(8) << "    _________________________________________________  " << Color(11) << "   * " << Color(10) << "   ********  "<< Color(14) << "       *       *" << Color(11) << "      *\t" << Color(8) << "    *\t" << Color(7) << " * * *     * * *" << Color(8) << "    *" << endl;
cout <<              "\t\t\t\t\t\t*" << Color(8) << "   |                                                 | " << Color(11) << "   * " << Color(14) << "    *    *   "<< Color(14) << "        *     *" << Color(11) << "       *\t" << Color(8) << "    *\t\t\t    *" << endl;
cout <<              "\t\t\t\t\t\t*" << Color(8) << "   |                                                 | " << Color(11) << "   * " << Color(14) << "    *    *   "<< Color(14) << "         *   *" << Color(11) << "        *\t" << Color(8) << "    *\t\t\t    *" << endl;
cout <<              "\t\t\t\t\t\t*" << Color(8) << "   |                                                 | " << Color(11) << "   * " << Color(14) << "    *    *   "<< Color(14) << "          * *" << Color(11) << "         *\t" << Color(8) << "    *\t\t\t    *" << endl;
cout <<              "\t\t\t\t\t\t*" << Color(8) << "   |_________________________________________________| " << Color(11) << "   * " << Color(14) << "     ****    "<< Color(14) << "           *" << Color(11) << "          *\t" << Color(8) << "    *\t\t\t    *" << endl;
cout <<              "\t\t\t\t\t\t*" << Color(11)<< "                                                       " << Color(11) << "   *                                    *\t" << Color(8) << "    *                       *"                                    << endl;
cout <<              "\t\t\t\t\t\t*" << Color(11)<< "*******************************************************" << Color(11) << "*****************************************\t" << Color(8) << "    *************************"<< Color(7)                         << endl;

    

    
    // Accepting the order from customers 
    
     
    for(int i = 0; i - 1; i++)       
    {
      {
	  
		
    	cout << "\t\t\t\t\t\t\t" << icon[1] << " WELCOME TO BING CHILLING! Press Enter to Continue." << endl;
              
			                                                                      	
		getchar();
	
	
		cout << "\n\t\t\t\t\t\t\t" << icon[1] << " Choose a number to purchase. (If Exit, Please Press 13) : "; 
        cin >> number;
        cin.clear();
        cin.ignore(100, '\n');
        
   
        
        if (number == 13) 
        {
	    
		
                cout << "\n\t\t\t\t\t\t\t  Thank you, have a nice day!";          
               return 0;
               
		}
        
        
         else if (number == 1) {
         	
        
               cout << "\n\t\t\t\t\t\t\t  Please select your quantity: ";
               cin >> quantity;
               price = quantity * 1;
               cout << "\n\t\t\t\t\t\t\t  You have selected " << flavour[i-1 + number] << " flavour x " << quantity << endl; 
               cout << "\n\t\t\t\t\t\t\t  The total price would be: RM " << price << endl;
            
            
        }
	

        else if (number >= 2 && number <= 6) {
               cout << "\n\t\t\t\t\t\t\t  Please select your quantity: ";
               cin >> quantity;
               price = quantity * 2;
               cout << "\n\t\t\t\t\t\t\t  You have selected " << flavour[i-1 + number] << " flavour x " << quantity << endl;
               cout << "\n\t\t\t\t\t\t\t  The total price would be: RM " << price << endl;
        }

        else if (number == 7 || number == 8) {
               cout << "\n\t\t\t\t\t\t\t  Please select your quantity: ";
               cin >> quantity;
               price = quantity * 3;
               cout << "\n\t\t\t\t\t\t\t  You have selected " << flavour[i-1 + number] << " flavour x " << quantity << endl;
               cout << "\n\t\t\t\t\t\t\t  The total price would be: RM " << price << endl;
        
        }
        
        
        
		else if (number >= 9 && number <= 11) {
			   cout << "\n\t\t\t\t\t\t\t  Please select your quantity: ";
			   cin >> quantity;
			   price = quantity * 4;
			   cout << "\n\t\t\t\t\t\t\t  You have selected " << flavour[i-1 + number] << " flavour x " << quantity << endl;
			   cout << "\n\t\t\t\t\t\t\t  The total price would be: RM " << price << endl;
					
		}
             
        else if (number == 12) {
        	   cout << "\n\t\t\t\t\t\t\t  Please select your quantity: ";
        	   cin >> quantity;
        	   price = quantity * 5;
        	   cout << "\n\t\t\t\t\t\t\t  You have selected " << flavour[i-1 + number] << " flavour x " << quantity << endl;
        	   cout << "\n\t\t\t\t\t\t\t  The total price would be: RM " << price << endl;
        	  }    
            
        else {
		 
          	   cout << "\n\t\t\t\t\t\t\t  Invalid Number, Please Enter And Try Again.\n\n ";
          	   
          	   getchar();
          	   
          	   main();
         	   
			} 
			
       }
         
               //declaring flavours for mapping(receipt)
               map<int,string> flav;
               flav.insert(pair<int,string>(1,"Vanilla"));
               flav.insert(pair<int,string>(2,"Cinammon"));
               flav.insert(pair<int,string>(3,"Mint"));
               flav.insert(pair<int,string>(4,"Lime"));
               flav.insert(pair<int,string>(5,"Matcha"));
               flav.insert(pair<int,string>(6,"Chocolate"));
               flav.insert(pair<int,string>(7,"Coffee"));
               flav.insert(pair<int,string>(8,"Strawberry"));
               flav.insert(pair<int,string>(9,"Bubble Tea"));
               flav.insert(pair<int,string>(10,"Salted Caramel"));
               flav.insert(pair<int,string>(11,"Cookies & Cream"));
               flav.insert(pair<int,string>(12,"Musang King"));    
		
		        map<int,string>qty1;
				qty1.insert(pair<int,string>(1,"1"));
		        qty1.insert(pair<int,string>(2,"2"));
		        qty1.insert(pair<int,string>(3,"3"));
		        qty1.insert(pair<int,string>(4,"4"));
		        qty1.insert(pair<int,string>(5,"5"));
		        qty1.insert(pair<int,string>(6,"6"));
		        qty1.insert(pair<int,string>(7,"7"));
		        qty1.insert(pair<int,string>(8,"8"));
		        qty1.insert(pair<int,string>(9,"9"));
		        qty1.insert(pair<int,string>(10,"10"));
		        qty1.insert(pair<int,string>(11,"11"));
		        qty1.insert(pair<int,string>(12,"12"));   

		//created a map to store the choices(reciept)			
		        map<int,string> choosen;
		
		        string chs=flav[number];
		
	           	map<int,string>s_total;
		
		        stringstream ss1;

		        ss1<<price;
		
		        string sub_price=ss1.str();
		
		        string sub=sub_price;
		
		        s_total.insert(pair<int,string>(l,sub));
		
		        choosen.insert(pair<int,string>(z,chs));
		
		        map<int,string>qty;
		
		        string q=qty1[quantity];
		
		        qty.insert(pair<int,string>(k,q));
   
 
			   //Request for User whether to add-ons product before proceed to checkout.
            
		  	   cout <<"\n\n\t\t\t\t\t\t\t" << icon [1] << " Want to Add-Ons? (Y / N ): ";
			   cin >> yesno;
			
			   while (yesno == 'Y' || yesno == 'y'){	
			
		       //mapping int(receipt)	
		       	z++;
				k++;
				l++;
	           //*****************************************************************************************//	
	           // Add ons statement


	      		    
     	       cout << "\n\t\t\t\t\t\t\t" << icon[1] << " Choose a number to purchase: ";
		       cin >> number;
		       cin.clear();
		       cin.ignore(100, '\n');
        
            
        if (number == 13) {
		
               cout << "\n\t\t\t\t\t\t\t  Thank you\nHave a nice day!";          
               return 0;
               }
        
        
         if (number == 1) {
         	
        
               cout << "\n\t\t\t\t\t\t\t   Please select your quantity: ";
               cin >> quantity;
               newprice = quantity * 1;
               cout << "\n\t\t\t\t\t\t\t  You have selected " << flavour[i-1 + number] << " flavour x " << quantity << endl; 
               cout << "\n\t\t\t\t\t\t\t   The total price would be: RM " << newprice << endl;
            
               }
	

        else if (number >= 2 && number <= 6) {
               cout << "\n\t\t\t\t\t\t\t  Please select your quantity: ";
               cin >> quantity;
               newprice = quantity * 2;
               cout << "\n\t\t\t\t\t\t\t  You have selected " << flavour[i-1 + number] << " flavour x " << quantity << endl;
               cout << "\n\t\t\t\t\t\t\t  The total price would be: RM " << newprice << endl;
               
               }

        else if (number == 7 || number == 8) {
               cout << "\n\t\t\t\t\t\t\t  Please select your quantity: ";
               cin >> quantity;
               newprice = quantity * 3;
               cout << "\n\t\t\t\t\t\t\t  You have selected " << flavour[i-1 + number] << " flavour x " << quantity << endl;
               cout << "\n\t\t\t\t\t\t\t  The total price would be: RM " << newprice << endl;
        
               }
        
        
        
		else if (number >= 9 && number <= 11) {
			   cout << "\n\t\t\t\t\t\t\t  Please select your quantity: ";
			   cin >> quantity;
			   newprice = quantity * 4;
			   cout << "\n\t\t\t\t\t\t\t  You have selected " << flavour[i-1 + number] << " flavour x " << quantity << endl;
			   cout << "\n\t\t\t\t\t\t\t  The total price would be: RM " << newprice << endl;
					
		       }
             
        else if (number == 12) {
        	   cout << "\n\t\t\t\t\t\t\t  Please select your quantity: ";
        	   cin >> quantity;
        	   newprice = quantity * 5;
        	   cout << "\n\t\t\t\t\t\t\t  You have selected " << flavour[i-1 + number] << " flavour x " << quantity << endl; 
        	   cout << "\n\t\t\t\t\t\t\t  The total price would be: RM " << newprice << endl;
        	
        	
		       }    
            
        else   {
		 
          	   cout << "\n\t\t\t\t\t\t\t  Invalid Number, Please Try Again. \n\n ";
          	   
          	   yesno =='y';
          	   
          	   getchar();
         	   
               }
               
   		//created a map to store the choices(reciept)			

		       chs=flav[number];
		
		       choosen.insert(pair<int,string>(z,chs));
		       		
			   stringstream ss1;

			   ss1<<newprice;
				
			   string sub_price=ss1.str();
				
			   string sub=sub_price;
				
			   s_total.insert(pair<int,string>(l,sub));
		               
    	       string q=qty1[quantity];
		
			   qty.insert(pair<int,string>(k,q));	
        
        
        //Request for User whether to add-ons product before proceed to checkout(Again).
         
		       cout <<"\n\n\t\t\t\t\t\t\t" << icon [1] << " Want to Add-Ons? (Y / N ): ";
		       cin >> yesno;
		    
		       price = (price + newprice);	
			

       

	
	   }   	
               //iteration for the chosen flavours(receipt)
	
	        map<int, string>::iterator it;   	
	        strToReturn;
	        map<int, string>::iterator itr; 
	        map<int, string>::iterator iter; 
	        for (itr = choosen.begin(),it = qty.begin(),iter=s_total.begin(); itr != choosen.end(),it != qty.end(),iter != s_total.end(); ++itr,++it,++iter) {
	           strToReturn.append(itr->second);
	           strToReturn.append(" x ");
	           strToReturn.append(it->second);
	           strToReturn.append("\t");
	           strToReturn.append("RM");
	           strToReturn.append(iter->second);
	           strToReturn.append("\n");           
    }
			
			//Check if user whether to checkout or not 
			
		       cout <<"\n\t\t\t\t\t\t\t" << icon [1] <<" Proceed to checkout? // Please Note that your order will be cancelled if checkout is declined \n";
		       cout <<"\n\t\t\t\t\t\t\t" << "\t\t\t  and it will return you back to Menu section. ( Y / N ) : ";
			   cin >> yesno;
			   
			   
			// If checkout is declined, it will return back to Menu section.
			
			while (yesno == 'N' || yesno == 'n'){
			
			   cout << "\n\t\t\t\t\t\t\t  Going back to Menu...\n\n ";
			   Sleep(5000); // Time Delay (miliseconds) // 
			   main();
			}
				
			// Shown the product and the price after being checkout.	
				
			cout << "\n\t\t\t\t\t\t\t  You have Selected : \n " << endl;	
				
					
		    
		    {
	        for (itr = choosen.begin(),it = qty.begin(),iter=s_total.begin(); 
			itr != choosen.end(),it != qty.end(),iter != s_total.end(); ++itr,++it,++iter) {
	           cout <<"\n\t\t\t\t\t\t\t" << icon [1] << " ";
	           cout<<itr->second;
	           cout<<" x ";
	           cout<<it->second;
	           cout<<"\t";
	           cout<<"RM";
	           cout<<iter->second;
	           cout<<"\n";           	
    }
	
	
	           // Showing the total price.
	
		       cout << "\n\t\t\t\t\t\t\t" << icon[1] << " Total amount will be RM : " << price << endl; 	
			}

			//Accept money from customer
			{	
			   cout << "\n\t\t\t\t\t\t\t" << icon [1] << " Please Insert RM " << price << " To The Bill Acceptors // Coin Insert.\n\t\t\t\t\t\t\t  RM : ";
               cin >> money; 
            }
            
            {
            	
            	
			}    
			   
        
            
            // Calculating the amount and giving back the change to customer.
      	 
			
			// If no change occured.
				          
            if (money >= price) {
				
				change=(money - price);
				
				if (change == 0){
					
				cout << "\n\t\t\t\t\t\t\t  Your Order is being processed... Please wait for a while.\n";
				Sleep(5000);// Time Delay (miliseconds) //	
				
				cout << "\n\t\t\t\t\t\t\t  Order Completed. Please take your product from dispenser.\n";
				Sleep(3000); // Time Delay (miliseconds) //
				
                cout << "\n\t\t\t\t\t\t\t " << icon [1] << " Change calculated: RM " << change << endl;
                cout << "\n\t\t\t\t\t\t\t " << icon [1] << " Your Product has been dropped into the dispenser." << endl;
                cout << "\n\t\t\t\t\t\t\t " << icon [1] << " Enjoy your BING CHILLING!!!  Please come again!" << endl;
                
                receipt(price,money,change,strToReturn);
                
                return 0;
                
                }
                
                // If change occured.
                
                else if (change != 0){
				
                cout << "\n\t\t\t\t\t\t\t  Your Order is being processed... Please wait for a while.\n";
				Sleep(5000);// Time Delay (miliseconds) //	
				
				cout << "\n\t\t\t\t\t\t\t  Order Completed. Please take your product from dispenser.\n";
				Sleep(3000); // Time Delay (miliseconds) //
               
                cout << "\n\t\t\t\t\t\t\t " << icon [1] << " Change calculated: RM " << change << endl;
                cout << "\n\t\t\t\t\t\t\t " << icon [1] << " Your Product and Change has been dropped into the dispenser." << endl;
                cout << "\n\t\t\t\t\t\t\t " << icon [1] << " Enjoy your BING CHILLING!!!  Please come again!" << endl;
                
           receipt(price,money,change,strToReturn);
                
                return 0;
                
                }
              
                
                
            }

                


        {
        	
        	//Statement for the user inserted money that is lower than the total price.
			//The program will alawys looping until the user insert enough money for the product. 
        	
            if(money < price){
			
        	
        	   remaining = (price - money);                                      
               cout << "\n\t\t\t\t\t\t\t" << icon [1] << " Insufficient Amount. Please Insert Another RM " << remaining << " to proceed your order " << "\n";
               cout << "\n\t\t\t\t\t\t\t" << icon [1] << " RM : ";
               cin >> newremaining; sum += newremaining;
                }        
            
            
            while (newremaining < remaining)
			{
			   remaining = (remaining - newremaining);                           
			   cout << "\n\t\t\t\t\t\t\t" << icon [1] << " Insufficient Amount. Please Insert Another RM " << remaining << " to proceed your order " << "\n";
               cout << "\n\t\t\t\t\t\t\t" << icon [1] << " RM : ";
               cin>> newremaining; sum += newremaining;
            }
			
		    if (newremaining >= remaining)
			{	
			
			   money = money + sum;
			
			   change = money - price;
		
			if (change == 0){
				
			
			   cout << "\n\t\t\t\t\t\t\t  Your Order is being processed... Please wait for a while.\n";
			   Sleep(5000);	// Time Delay (miliseconds) //
				
			   cout << "\n\t\t\t\t\t\t\t  Order Completed. Please take your product from dispenser.\n";
			   Sleep(3000); // Time Delay (miliseconds) //	
				
               cout << "\n\t\t\t\t\t\t\t" << icon [1] << " Change calculated: RM " << change << endl;
               cout << "\n\t\t\t\t\t\t\t" << icon [1] << " Your Product has been dropped into the dispenser." << endl;
               cout << "\n\t\t\t\t\t\t\t" << icon [1] << " Enjoy your BING CHILLING!!!  Please come again!" << endl;
               receipt(price,money,change,strToReturn); 
               
               return 0;
            }
                            
            else if (change != 0){
            	
            	
               cout << "\n\t\t\t\t\t\t\t  Your Order is being processed... Please wait for a while.\n";
			   Sleep(5000);	// Time Delay (miliseconds) //
				
			   cout << "\n\t\t\t\t\t\t\t  Order Completed. Please take your product from dispenser.\n";
			   Sleep(3000); // Time Delay (miliseconds) //
            	
               cout << "\n\t\t\t\t\t\t\t" << icon [1] << " Change calculated: RM " << change << endl;
               cout << "\n\t\t\t\t\t\t\t" << icon [1] << " Your Product and Change has been dropped into the dispenser." << endl;
               cout << "\n\t\t\t\t\t\t\t" << icon [1] << " Enjoy your BING CHILLING!!!  Please come again!" << endl;
				
					
               receipt(price,money,change,strToReturn);
			}    
                
                return 0;
            }
          	 
			
	   }
	
     }

   }

	
}

//Receipt
void receipt(float Tot,float pd,float chg,string name){
	 ofstream MyFile("receipt.txt");
	  MyFile << "***************"<<endl;
	  MyFile << "*BING CHILLING*"<<endl;
	  MyFile << "***************"<<endl;
	  MyFile << "Flavours"<<"\t"<<"Price"<<endl;
	  MyFile << left<<""<<name<<endl;
	  MyFile << "Total  :RM  "<<Tot<<endl;
	  MyFile << "Paid   :RM  "<<pd<<endl;
	  MyFile << "Change :RM  "<<chg<<endl;
	  MyFile << "Thank You ""\U0001F600"<<endl;
	  MyFile << "***************"<<endl;
	  MyFile.close();
}
