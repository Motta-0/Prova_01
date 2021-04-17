#include <iostream>
#include <string>
using namespace std;

string converter(char character=' ')
{
    switch(character)
    {
    case '0':
        return("A");
        break;
    case '1':
        return("B");
        break;
    case '2':
        return("C");
        break;
    case '3':
        return("D");
        break;
    case '4':
        return("E");
        break;
    case '5':
        return("F");
        break;
    case '6':
        return("G");
        break;
    case '7':
        return("H");
        break;
    case '8':
        return("I");
        break;
    case '9':
        return("J");
        break;
    case 'A':
        return("0");
        break;
    case 'B':
        return("1");
        break;
    case 'C':
        return("2");
        break;
    case 'D':
        return("3");
        break;
    case 'E':
        return("4");
        break;
    case 'F':
        return("5");
        break;
    case 'G':
        return("6");
        break;
    case 'H':
        return("7");
        break;
    case 'I':
        return("8");
        break;
    case 'J':
        return("9");
        break;
    }
}
int transformarInt(char character=' ')
{
    switch(character)
    {
    case '0':
        return(0);
        break;
    case '1':
        return(1);
        break;
    case '2':
        return(2);
        break;
    case '3':
        return(3);
        break;
    case '4':
        return(4);
        break;
    case '5':
        return(5);
        break;
    case '6':
        return(6);
        break;
    case '7':
        return(7);
        break;
    case '8':
        return(8);
        break;
    case '9':
        return(9);
        break;
    }
}

int main()
{
    bool falou = false;
    char processar_dados=' ';
    string codigo="";
    string codigo_processado="";
    string resultado="";

    cout << "Digite C para codificar ou D para decodificar: ";
    cin >> processar_dados;
    fflush(stdin);
    cout<<"Escreva o codigo: ";
    cin>>codigo;

    int tamanho=codigo.length();
    string codigo_aux="";
    if(tamanho>999)
    {
        for(int i=0; i<999; i++)
        {
            codigo_aux = codigo_aux + codigo[i];
        }
        codigo = codigo_aux;
    }
    if((processar_dados == 'C')||(processar_dados=='c'))
    {

        for(int i=0; i<tamanho; i++)
        {

            codigo[i]=toupper(codigo[i]);

            if((codigo[i] >= 48) && (codigo[i] <=57))
            {

                codigo_processado += "Z" + converter(codigo[i]);

            }
            else if ((codigo[i] >= 65) && (codigo[i] <= 89))
            {

                codigo_processado += codigo[i];

            }
            else if (codigo[i] == 90)   //Z
            {
                codigo_processado += "ZZ";
            }
        }

        int cont=1;
        int repeticao=1;
        char letra=' ';
        tamanho=codigo_processado.length();

        for(int i=0; i<tamanho+1; i++)
        {
            letra=codigo_processado[i];
            if(codigo_processado[i]==codigo_processado[i+1])
            {
                if(i<tamanho-1)
                {
                    while(codigo_processado[i]==codigo_processado[i+1])
                    {
                        i++;
                        repeticao++;
                    }
                }
            }
            if(repeticao>1)
            {
                resultado += to_string(repeticao)+letra;
            }
            else
            {
                resultado += letra;
            }
            repeticao=1;
        }
        cout << resultado << endl;

    }
    else if((processar_dados=='D')||(processar_dados=='d'))
    {
        tamanho=codigo.length();
        for(int i=0; i<tamanho; i++)
        {
            codigo[i]=toupper(codigo[i]);
            if((codigo[i] >= 65) && (codigo[i] <= 89))
            {
                if((codigo[i-1] >= 48) && (codigo[i-1] <=57))
                {
                    for (int j=0; j<transformarInt(codigo[i-1]); j++)
                    {
                        codigo_processado += codigo[i];
                    }
                }
                else if(codigo[i-1]==90)
                {
                    if((codigo[i-2]>=48)&&(codigo[i-2]<=57))
                    {
                        int valor_inteiro=transformarInt(codigo[i-2]);
                        for (int k=0; k<(valor_inteiro/2); k++)
                        {
                            codigo_processado+="Z";
                        }
                        if (valor_inteiro % 2 != 0)
                        {
                            codigo_processado+=converter(codigo[i]);
                        }
                    }
                    else
                    {
                        codigo_processado+=converter(codigo[i]);
                    }
                }
                else
                {
                    codigo_processado += codigo[i];
                }
            }
            else if(codigo[i] == 90)
            {
                if(tamanho-i==1)
                {
                    if((codigo[i-1]>=48)&&(codigo[i-1]<=57))
                    {
                        int valor_inteiro=transformarInt(codigo[i-1]);
                        for (int k=0; k<(valor_inteiro/2); k++)
                        {
                            codigo_processado+="Z";
                        }
                    }
                    else
                    {
                        codigo_processado = " ";
                    }
                }
            }
        }
        cout << codigo_processado << endl;
    }
}
