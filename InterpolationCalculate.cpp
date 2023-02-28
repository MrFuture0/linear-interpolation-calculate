
 #include <iostream>
 #include  <cmath>
 #include <iomanip>
 using namespace std;

float a,b,c,fonksiyona,fonksiyonb,fonksiyonc;
float hatadegeri=0.001;
float hatakontroldegeri,tempc;
float IterasyonHesapla();

    int main()
    {
         cout<< setprecision(7)<< fixed;
        cout << "2x^3-3x^2-4x+5 fonksiyonumuz icin belirlediginiz [a,b] araliginda iterasyon islemi yapilacaktir." << endl;
        cout << "Lutfen a degerini giriniz :"<< endl;
        cin>>a;
    
        if(!cin.fail())
        {
            cout << "Lutfen b degerini giriniz :"<< endl;
            cin>>b;
            if(!cin.fail())
            {
                    if(b>a)
                    
                    {	
						c=(a+b)/2;
						cout << " Tekrar\ta(n)\t\t\tb(n)\t\t\tc(n)\t\t\tHata(n)"<<endl;
						cout << " ----------------------------------------------------------------------------------------"<<endl;
						hatakontroldegeri=(b-a)/2;
						cout<< " " <<"1" << "\t"<< a << "\t\t"<< b << "\t\t" << c << "\t\t"<< hatakontroldegeri <<endl;
                        IterasyonHesapla();
                    }
                    else
                    {
                        
                        cout << "[a,b] araliginda a kucuk olan aralik degeri ve b buyuk olan aralik degeri olacak sekilde NUMERIK degeler giriniz."<<endl;
                    }
            }
            else
            {
                cout <<"Lutfen b icin numerik bir deger giriniz!" <<endl;
            }
        }
        else
        {
            cout <<"Lutfen a icin numerik bir deger giriniz!" <<endl;
        }
        
          
    }

    float IterasyonHesapla()
    {
        fonksiyona=2*pow(a,3)-3*pow(a,2)-(4*a)+5;
        fonksiyonb=2*pow(b,3)-3*pow(b,2)-(4*b)+5;
        
        if((fonksiyona*fonksiyonb)<0)
        {   
            
            int Index;
            for(Index=2; Index <=10 ; Index++)
            {             
                
                fonksiyonc=2*pow(c,3)-3*pow(c,2)-(4*c)+5;
                if(fonksiyonc*fonksiyona<0)
                {
                    b=c;
                    tempc=c;
                    c=(a+b)/2;
                    hatakontroldegeri=(b-a)/pow(2,Index);
                    if (hatakontroldegeri>hatadegeri)
                    {
                       
                    }
                    else
                    {
                        
                        cout << "Hata degerine ulasildigi icin fonksiyon sonlandirilmistir." << endl;
                        cout << "Kokumuz ise : " << tempc << " olmustur" << endl;
                        break;
                    }
                }
                else if((fonksiyonb*fonksiyonc)==0)
                {
                    cout << "f(b)*f(c)=0 oldugu icin Kok degerimiz :  \t" << c << " olmaktadir..."<< endl;
                    
                    break;
                }
                else  
                {
                    a=c;
                    tempc=c;
                    c=(a+b)/2;
                    hatakontroldegeri=(b-a)/pow(2,Index);
                    if (hatakontroldegeri>hatadegeri)
                    {
                       
                    }
                    else
                    {
                        
                        cout << "Hata degerine ulasildigi icin fonksiyon sonlandirilmistir." << endl;
                        cout << "Kokumuz ise : " << tempc << " olmustur" << endl;
                        break;
                    }
                }
                cout<< " " <<Index << "\t"<< a << "\t\t"<< b << "\t\t" << c << "\t\t"<< hatakontroldegeri <<endl;
  
                }
                
            
            
        }
        else if((fonksiyona*fonksiyonb)==0)
        {
            cout << "Girilen degerler icin f(a)*f(b)=0 oldugundan dolayi Kokumuz ya" << a << " yada " << b << "'dir." << endl;
        }
        else
        {
            cout << "Girmis oldugunuz degerler icin bu aralikta kok degeri bulunmamaktadir." << endl;

        }
           return a,b,hatakontroldegeri; 
    }
