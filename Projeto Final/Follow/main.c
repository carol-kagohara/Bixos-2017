#include "sensors.h"
#include "motors.h"
#include "timer.h"

int tempo, marcaesquerda, marcadireita, sensor_0, sensor_1, sensor_2, sensor_3, sensor_4, sensor_5, sensor_6, encoder1, encoder2;

marcadireita = 0;

int main() {
	for (;;) {

        tempo = get_tick();
        if (tempo >= 1000)
        {
            sensor_6 = getLineSensor(6);
            sensor_0 = getLineSensor(0);

            \* Comando para ultrapassar a primeira linha branca do lado direito
                Consideramos que o sensor 6 lê apenas a marca do lado direito *\
            while ( sensor_6 > 500 && sensor_0 < 500 && marcadireita == 0)
            {
                motors (255,255);
                sensor_6 = getLineSensor(6);
                sensor_0 = getLineSensor(0);
            }
            \* Consideramos que a distância entre o sensor 2 e o sensor 4 é maior do que a linha *\
            sensor_2 = getLineSensor(2);
            sensor_3 = getLineSensor(3);
            sensor_4 = getLineSensor(4);
            marcadireita = 1;
            
            \* Comando para andar em linha reta *\
            while ( sensor_2 < 500 && sensor_3 > 500 && sensor_4 < 500 && sensor_0 < 500 && sensor_6 < 500) 
            {
                motors (255,255);
                sensor_2 = getLineSensor(2);
                sensor_3 = getLineSensor(3);
                sensor_4 = getLineSensor(4);
                sensor_0 = getLineSensor(0);
                sensor_6 = getLineSensor(6);
            }
            \* Comando para correção caso saia fora da curva *\
            while (sensor_2 > 500) 
            {
                motors (240,255);
                sensor_2 = getLineSensor(2);
                sensor_3 = getLineSensor(3);
                sensor_4 = getLineSensor(4);
                sensor_0 = getLineSensor(0);
                sensor_6 = getLineSensor(6);
                while (sensor_3 < 500)
                {
                    motors (200, 255);
                    sensor_2 = getLineSensor(2);
                    sensor_3 = getLineSensor(3);
                    sensor_4 = getLineSensor(4);
                    sensor_0 = getLineSensor(0);
                    sensor_6 = getLineSensor(6);
                }
            }

            while (sensor_4 > 500) 
            {
                motors (255,240);
                sensor_2 = getLineSensor(2);
                sensor_3 = getLineSensor(3);
                sensor_4 = getLineSensor(4);
                sensor_0 = getLineSensor(0);
                sensor_6 = getLineSensor(6);
                while (sensor_3 < 500)
                {
                    motors (255, 200);
                    sensor_2 = getLineSensor(2);
                    sensor_3 = getLineSensor(3);
                    sensor_4 = getLineSensor(4);
                    sensor_0 = getLineSensor(0);
                    sensor_6 = getLineSensor(6);
                }
            }


            \* Consideramos que o sensor 0 lerá apenas a marca da esquerda
                O robô entrará em um modo de curva com velocidade reduzida*\
            if ( sensor_0 > 500 && sensor_6 < 500)
                marcaesquerda = 1;

            while (marcaesquerda == 1)
            {
                \*redução de velocidade na zona de curvas*\
                while (sensor_2 < 500 && sensor_3 > 500 && sensor_4 < 500 && marcaesquerda == 1)
                {
                    motors (175, 175)
                    sensor_2 = getLineSensor(2);
                    sensor_3 = getLineSensor(3);
                    sensor_4 = getLineSensor(4);
                    sensor_0 = getLineSensor(0);
                    if (sensor_0 > 500)
                        marcaesquerda = 0
                }
                while(sensor_2 > 500 && marcaesquerda == 1)
                {
                    motors(100,200);
                    sensor_2 = getLineSensor(2);
                    sensor_0 = getLineSensor(0);
                    if (sensor_0 > 500)
                        marcaesquerda = 0;
                }
                while(sensor_4 > 500 && marcaesquerda == 1)
                {
                    motors(200,100);
                    sensor_4 = getLineSensor(4);
                    sensor_0 = getLineSensor(0);
                    if (sensor_0 > 500)
                        marcaesquerda = 0
                }
            }

            \* Comando de parada *\
            sensor_6 = getLineSensor(6);
            if (sensor_6 > 500 && sensor_0 < 500)
            {
                encoder1 = getEncoder (ENCODER_L);
                encoder2 = 0;
                while
                {
                    if (encoder2 < encoder1 + 350)
                {
                    encoder2 = getEncoder(ENCODER_L);
                    motors(255,255);
                }
                    else
                    {
                        motors (0,0);
                        for (;;) {}
                    }
            }
	}
    }
}
}
