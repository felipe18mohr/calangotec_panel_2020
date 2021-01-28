#include <Gyroscope.hpp>

Gyroscope::Gyroscope(double ang1, double ang2) : 
  mpu6050(Wire) {
  
  last_state = 'c';
  ang = ang1;
  cent_ang = ang2;
  left_count = 0;
  right_count = 0;

  Wire.begin();
  mpu6050.begin();
  mpu6050.calcGyroOffsets();
  
}


void Gyroscope::steeringWheelTurning() {
  mpu6050.update();
  yaw = mpu6050.getAngleZ();

  if (yaw < -ang){ //Se o volante está virado para direita
    if (last_state != 'r'){  //Se não estava ANTES virado
      right_count++; //Incrementa o contador de giros da direita
      last_state = 'r'; //Define o last_state da próxima iteração
    }
  }

  else if (yaw > ang){ //Se o volante está virado para esquerd
    if (last_state != 'l'){  //Se não estava ANTES virado
      left_count++;  //Incrementa o contador de giros da esquerda
      last_state = 'l';  //Define o last_state da próxima iteração
    }
  }

  else if (-cent_ang < yaw < cent_ang) 
    last_state = 'c';  //Volante na posição central   
}
