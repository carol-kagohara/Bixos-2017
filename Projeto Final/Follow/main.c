#include "sensors.h"
#include "motors.h"
#include "timer.h"

int tempo, curva, inicio, sensores[7], encoder_l, encoder_r, j, tempo2, sens[7], s[7], media;

inicio=0;
curva=0;

int main()
{
    while(tempo<1000){tempo = get_tick()}
    for (;;) {
        for (j = 0; i<7; i++)
        {
            sensores[j] = getLineSensor(j);
            if (sensores[j] > 800)
            {
                sens[j] = 1;
            }
            else
            {
                sens[j] = 0;
            }
        }
        encoder_l = getEncoder(ENCODER_L);
        encoder_r = getEncoder(ENCODER_R);
        if (sensores[6]>800)
        {
            if (inicio == 0)
            {
                tempo2 = get_tick();
                motors(255,255);
                while(tempo2<tempo+500){tempo2 = get_tick()}

/*meio segundo é o tempo para o robo passar a espessura da linha no inicio*/

                inicio +=1;
            }

            else
            {
                encoder1=encoder_l;
                while (encoder_l < encoder1 + 350){encoder_l = getEncoder(ENCODER_L)}
                motors(255,255);

/*350 seria a distancia teorica para o robo estar totalmente entre as 2 linhas direitas no fim*/

                for(;;)
            }
        }
        if (sensores[0]>800)
        {
            while(tempo2<tempo+500){tempo2 = get_tick()}
            motors(255,255);
            if (curva==0)
            {
                curva+=1;
                motors(200,200);
            }
        else
        {
            curva=0;
        }

/*meio segundo seria o tempo de passar a linha. tal if seria como um meio de ver se o robo esta em curva ou não, o que implica na sua reduçâo de velocidade.*/
/* 0 = nao esta em curva, 1= esta em curva*/ 

        }

/* calculo da media ponderada para usar o "método da proporcional" para fazer a curva e ajustar caso esteja fora do percurso*/

        media = 0;
        s[0] = sens[0]*0;
        s[1] = sens[1]*-2;
        s[2] = sens[2]*-1;
        s[3] = sens[3]*0;
        s[4] = sens[4]*1;
        s[5] = sens[5]*2;
        s[6] = sens[6]*0;

        for (j=0; i<7; i++)
        {

            media = media + s[j];
        }
        
        if (media == -1) {motors(210,255);}
        if (media == 1) {motors(255,210);}
        else {motors(255,255);}
        
        if (media < 0)
        {
            if (curva == 1)
            {
                motors(170,220);
            }
            else
            {
                motors(190,255);                
            }
        }

        if (media > 0)
        {
            if (curva == 1)
            {
                motors(220,170);
            }
            else
            {
                motors(255,190);
            }
        }

        if (media < -1)
        {
            if (curva==1)
            {
                motors(150,210);
            }
            else
            {
                motors(150,255);
            }
        } 

        if (media > 1)
        {
            if (curva==1)
            {
                motors(210,150);
            }
            else
            {
                motors(255,150);
            }
        }
    }
}
