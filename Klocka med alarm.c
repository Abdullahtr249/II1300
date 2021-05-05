


/**** Namn: ABDULLAH TRABULSIAH.
      Personnummer: 199901030651.
      E-postadress: abdtra@kth.se & abdullahtr249@gmail.com
                                                            ****/


#include <stdio.h>
/*Deklarerar en funktion som kommer att bearbeta uppdateringen av tid.*/
int Updated_time(int present_time);

/*Deklarerar en funktion som skriver ut "alarm!" vid den utsatta alarm-tiden.*/
void alarm();

int main()
{
    /*Användaren matar in aktuell tid samt alarm-tid.*/
    int present_time;
    int time_for_alarm;
    
    printf("Enter present time in the following form HHMMSS: \n");
    scanf("%d",&present_time);
    
    printf("Enter time for alarm in the following form HHMMSS: \n");
    scanf("%d", &time_for_alarm);
    
    
    
    /** Skapar en while-loop där programmet bearbetar de inmatade uppgifterna. **/
    while (present_time != time_for_alarm)
    {
        int s;
        int m;
        int h;
        
        /* En formel som plockar ut tiden i timmar, minuter och sekunder från talet som användaren matade in, alltså talet (HHMMSS). */
        s=present_time%100;
        m=(present_time%10000)/100;
        h=present_time/10000;
         
         
        /* Följande if-statments finns till för att få tiden utskriven snyggt som t.ex. 12:20:47. */
        if (h < 10) {
            printf("0%d:", h);
        } else {
            printf("%d:", h);
        }
        
        if (m < 10) {
            printf("0%d:", m);
        } else {
            printf("%d:", m);
        }
        
        if (s < 10) {
            printf("0%d\n", s);
        } else {
            printf("%d\n", s);
        }
        
        /* Anropar funktionen Updated_time. */         
        present_time = Updated_time(present_time);
    }
    
    /* Anropar funktionen alarm. */
    alarm();
    
    return 0;
}


int Updated_time(int present_time)
{
    int s;
    int m;
    int h;
    int new_time;
    
    /* En formel som plockar ut tiden i timmar, minuter och sekunder från talet som användaren matade in, alltså talet (HHMMSS). */
    s = present_time%100;
    m = (present_time%10000)/100;
    h = present_time/10000;
    s = s + 1;
    
    
    /* Följande if-statments finns för att programmet ska räkna med att det finns 24 timmar i ett dygn, 
    60 timmar i en timme och 60 sekunder i en minut. */
    if(s == 60)
    {
      s = 0;
      m = m + 1;
       
        if(m == 60)
        {
         m = 0;
         h = h + 1;
            
            if(h == 24)
            {
              h = 0;
            }
        }
    }
    
    /* Tiden skrivs om efter bearbetning till formen HHMMSS för att skickas tillbaka till funktionen main som "new_time".*/
    new_time = (h*10000)+(m*100)+s;
   
    return new_time;
}


void alarm ()
{
    printf("ALARM!");
}

