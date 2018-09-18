#include<iostream>
#include<stdlib.h>
#include<math.h>
using namespace std;
unsigned long hex_to_dec(char hex[]);

int main()
{
        unsigned long dec_1;
        unsigned long dec_2;
        unsigned long dec_3;
        unsigned long dec_4;
        char signal_1[9]="00000140";  
        char signal_2[9]="00000640";
        char signal_3[9]="00000960";
        char signal_4[9]="00000C80";
        dec_1 = hex_to_dec(signal_1)*0.03125;
        dec_2 = hex_to_dec(signal_2)*0.03125;
        dec_3 = hex_to_dec(signal_3)*0.03125;
        dec_4 = hex_to_dec(signal_4)*0.03125;
        cout<<"\n The Decoded message for signal 1 is : "<<dec_1<<"\n";
        cout<<"\n The Decoded message for signal 2 is : "<<dec_2<<"\n";
        cout<<"\n The Decoded message for signal 3 is : "<<dec_3<<"\n";
        cout<<"\n The Decoded message for signal 4 is : "<<dec_4<<"\n";
        return 0;
}

unsigned long hex_to_dec(char hex[])
{
        char *hex_str;
        int length = 0;
        const int base = 16;    
        unsigned long dec = 0;
        int i;	
        for (hex_str = hex; *hex_str != '\0'; hex_str++)  
        {
                length++;
        }

        hex_str = hex;  
        for (i = 0; *hex_str != '\0' && i < length; i++, hex_str++)
        {
                
                if (*hex_str >= 48 && *hex_str <= 57)   
                {
                        dec+= (((int)(*hex_str)) - 48) * pow(base, length - i - 1);
                }
                else if ((*hex_str >= 65 && *hex_str <= 70))   
                {
                        dec+= (((int)(*hex_str)) - 55) * pow(base, length - i - 1);
                }
                else if (*hex_str >= 97 && *hex_str <= 102)   
                {
                        dec += (((int)(*hex_str)) - 87) * pow(base, length - i - 1);
                }
                
        }
        return dec;
}
