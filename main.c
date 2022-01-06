#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


struct praceuczestnika{
char praca[100];
float ocena;
struct lista *nxt;
};
struct uczestnik{
int id;
int kod;
char daneOsobowe[50];
int wiek;
char email[50];
//char opiekun[40];
};
struct uczestnik_np{
int id;
int kod;
char daneOsobowe[50];
int wiek;
char email[50];
char opiekun[50];
};
const char* uczestnik_format = "%d\t%d\t%s\t%d\t%s\n";
const char* uczestnik_np_format = "%d\t%d\t%s\t%d\t%s\t%s\n";

void dodajuczestnika(){
    srand(time(0));
    struct uczestnik u;
    struct uczestnik_np u_np;
    int wiek;


    FILE *plik;
    plik=fopen("uczestnicy.txt","a");
    if(plik==NULL)printf("blad");
    FILE *plik_czytaj;
    plik_czytaj=fopen("uczestnicy.txt","r");

    FILE *plik_np;
    plik_np=fopen("uczestnicy niepelnoletni.txt","a");
    if(plik_np==NULL)printf("blad");
    FILE *plik_np_czytaj;
    plik_np_czytaj=fopen("uczestnicy niepelnoletni.txt","r");



    printf("Prosze o podanie dokladnych danych. W pozniejszym etapie nie bedzie mozliwoœci ich edycji.\nPodaj wiek uczestnika.\n");
     scanf("%d", &wiek);

      if(wiek<18){
    //ustawianie numerów i hasla
       u_np.id=0;
       while(fscanf(plik_np_czytaj,uczestnik_np_format,&u_np.id,&u_np.kod,u_np.daneOsobowe,&u_np.wiek,u_np.email,u_np.opiekun)!=EOF){
        continue;
        }

        u_np.id++;
        u_np.kod=1000+rand()%(9000);

    u_np.wiek=wiek;
    printf("Podaj imie i nazwisko uczestnika.\n");
    fflush(stdin);
    fgets(u_np.daneOsobowe,40,stdin);
    u_np.daneOsobowe[strlen(u_np.daneOsobowe)-1]= 0;

    printf("Podaj imie i nazwisko opiekuna prawnego.\n");
    fflush(stdin);
    fgets(u_np.opiekun,40,stdin);
    u_np.opiekun[strlen(u_np.opiekun)-1]= 0;

    printf("Podaj kontaktowy adres e-mail.\n");
    fflush(stdin);
    fgets(u_np.email,40,stdin);
    u_np.email[strlen(u_np.email)-1]=0;


        fprintf(plik_np,uczestnik_np_format,u_np.id,u_np.kod,u_np.daneOsobowe,u_np.wiek,u_np.email,u_np.opiekun);

        printf("Pomyslnie dodano uczestnika: %s\n Numer uczestnika: %d\t Haslo:%d\n Numer i haslo beda potrzebne do dodania prac na konkurs.\n",u_np.daneOsobowe,u_np.id,u_np.kod);
    }

    else if(wiek>=18){
        u.id=0;
       while(fscanf(plik_czytaj,uczestnik_format,&u.id,&u.kod,u.daneOsobowe,&u.wiek,u.email)!=EOF){
        continue;
        }
        u.id++;
        u.kod=1000+rand()%(9000);
        printf("\n\n%d\t%d\n",u.id,u.kod);

    u.wiek=wiek;
    printf("Podaj imie i nazwisko uczestnika.\n");
    fflush(stdin);
    fgets(u.daneOsobowe,40,stdin);
    u.daneOsobowe[strlen(u.daneOsobowe)-1]= 0;

    printf("Podaj kontaktowy adres e-mail.\n");
    fflush(stdin);
    fgets(u.email,40,stdin);
    u.email[strlen(u.email)-1]=0;

        fprintf(plik,uczestnik_format,u.id,u.kod,u.daneOsobowe,u.wiek,u.email);

        printf("Pomyslnie dodano uczestnika: %s\n Numer uczestnika: %d\t Haslo:%d\n Numer i haslo beda potrzebne do dodania prac na konkurs.\n",u.daneOsobowe,u.id,u.kod);


    }
fclose(plik);fclose(plik_czytaj);fclose(plik_np);fclose(plik_np_czytaj);
return 0;


}


void dodawanieprac(){
    FILE *plik_czytaj;
    struct uczestnik u;
    struct uczestnik_np u_np;
    int wiek,id,kod,np,poprawny=0;
    start:
printf("Podaj swoj wiek\n");
scanf("%d", &wiek);

if(wiek>=18){
    plik_czytaj=fopen("uczestnicy.txt","r");
    if(plik_czytaj==NULL){printf("Blad. Sprobuj ponownie pozniej.\n");
    return;}
}
if (wiek<18){
    plik_czytaj=fopen("uczestnicy niepelnoletni.txt","r");
    if(plik_czytaj==NULL){printf("Blad. Sprobuj ponownie pozniej.\n");
    return;}
}
printf("Podaj swoj numer uczestnika\n");
scanf ("%d", &id);
printf("Podaj haslo");
scanf ("%d", &kod);
if(wiek>=18){
    while(fscanf(plik_czytaj,uczestnik_format,&u.id,&u.kod,u.daneOsobowe,&u.wiek,u.email)!=EOF){
        if(u.id==id && u.kod==kod)poprawny=1;

    } if(poprawny!=1){
        printf("Niepoprawne dane. Sprobuj ponownie");
        goto start;}

}

if (wiek<18){
    while(fscanf(plik_czytaj,uczestnik_np_format,&u_np.id,&u_np.kod,u_np.daneOsobowe,&u_np.wiek,u_np.email,u_np.opiekun)!=EOF){
        if(u_np.id==id && u_np.kod==kod)poprawny=1;

    } if(poprawny!=1){
        printf("Niepoprawne dane. Sprobuj ponownie");
    goto start;}

    printf("udalo sie");

}

}
void ocenianie(){
printf("ocena");
}
void admin(){
printf("admin");
}

int main(){
    int operacja;
    menu:
printf("(1)Zapis na konkurs\n(2)Dodawanie prac\n(3)Tryb Jury\n(0)Tryb administracyjny\n");
scanf("%d", &operacja);
if(operacja!=0&&operacja!=1&&operacja!=2&&operacja!=3){
    printf("sprobuj ponownie");
}
if(operacja==1){
    dodajuczestnika();
}
if(operacja==2){
    dodawanieprac();
}
if(operacja==3){
    ocenianie();

}
if(operacja==0){
    admin();
}
goto menu;


return 0;
}
