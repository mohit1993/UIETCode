#include "DisplayText.h"

string DisplayText::characters[26][5] = {{" *** ","*   *","*****","*   *","*   *"},{"**** "," *  *"," *** "," *  *","**** "},{" ****","*    ","*    ","*    "," ****"},{"**** "," *  *"," *  *"," *  *","**** "},{"*****"," *   "," *** "," *   ","*****"},{"*****"," *   "," *** "," *   "," *   "},{" ****","*    ","* ***","*   *"," ****"},{"*   *","*   *","*****","*   *","*   *"},{"*****","  *  ","  *  ","  *  ","*****"},{"*****","   * ","   * ","*  * "," *** "},{"*  **","* *  ","**   ","* *  ","*   *"},{"*    ","*    ","*    ","*   *","*****"},{"*   *","** **","* * *","*   *","*   *"},{"*   *","**  *","* * *","*  **","*   *"},{" *** ","*   *","*   *","*   *"," *** "},{"**** "," *  *"," *** "," *   "," *   "},{" *** ","*   *","* * *","*  **"," ****"},{"**** "," *  *"," *** "," * * "," *  *"},{" ****","*    "," *** ","    *","**** "},{"*****","  *  ","  *  ","  *  ","  *  "},{"*   *","*   *","*   *","*   *"," *** "},{"*   *","*   *","*   *"," * * ","  *  "},{"*   *","*   *","* * *","** **","*   *"},{"*   *"," * * ","  *  "," * * ","*   *"},{"*   *"," * * ","  *  ","  *  ","  *  "},{"*****","   * ","  *  "," *   ","*****"}};

void DisplayText::display(string s){
	cout<<endl;
	for(int count = 0;count<5;count++){
		for(int i=0;i<s.size();i++){
			int index = int(s[i]);
			if(index > 64 && index<91)
				index = index - 65;
			else if(index > 96)
			     index = index - 97;
			showchar(index,count);
			cout<<"   ";
		}
		cout<<endl;
	}
}

void DisplayText::showchar(int i,int count){
	for(int j=0;j<5;j++){
		cout<<characters[i][count][j]<<" ";
	}
}