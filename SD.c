#define dir_PCA 0x80
#define PCA RD0_bit
#define PCA_D TRISD0_bit

#define buzzer RD1_bit
#define buzzer_D TRISD1_bit

#define RTC_E 0xD0
#define RTC_L 0xD1

#define espacio "\r\n"

sbit Soft_I2C_Scl           at Rc1_bit;
sbit Soft_I2C_Sda           at Rc2_bit;
sbit Soft_I2C_Scl_Direction at TRISc1_bit;
sbit Soft_I2C_Sda_Direction at TRISc2_bit;

// MMC module connections
sbit Mmc_Chip_Select at RC0_bit;
sbit Mmc_Chip_Select_Direction at TRISC0_bit;


unsigned short hab;
unsigned short count[15]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

char c1[]="cama1.txt";
char c2[]="cama2.txt";
char c3[]="cama3.txt";
char c4[]="cama4.txt";
char c5[]="cama5.txt";
char c6[]="cama6.txt";
char c7[]="cama7.txt";
char c8[]="cama8.txt";
char c9[]="cama9.txt";
char c10[]="cama10.txt";
char c11[]="cama11.txt";
char c12[]="cama12.txt";
char c13[]="cama13.txt";
char c14[]="cama14.txt";
char c15[]="cama15.txt";
unsigned short *cama[15]={c1,c2,c3,c4,c5,c6,c7,
                          c8,c9,c10,c11,c12,c13,c14,c15};

unsigned short seg,min,hora,dia,mes,year;

void Fat_send(unsigned short c){
// declamos variables para enviar a la SD
char Scama[4];
char Sseg[4];
char Smin[4];
char Shora[4];
char Sdia[4];
char Smes[4];
char Syear[4];
// convertimos los datos a string
ByteToStr(c,Scama);
ByteToStr(seg,Sseg);
ByteToStr(min,Smin);
ByteToStr(hora,Shora);
ByteToStr(dia,Sdia);
ByteToStr(mes,Smes);
ByteToStr(year,Syear);
//arreglos esteticos en la fecha
Smes[0]='/';
Smes[3]='/';
Syear[0]=Syear[1];
Syear[1]=Syear[2];
if (Sdia[1]==' ') Sdia[1]='0';
if (Smes[1]==' ') Smes[1]='0';
if (Syear[0]==' ') Syear[0]='0';
//arreglos esteticos en la hora
Smin[0]=':';
Smin[3]=':';
Sseg[0]=Sseg[1];
Sseg[1]=Sseg[2];
if (Shora[1]==' ') Shora[1]='0';
if (Smin[1]==' ') Smin[1]='0';
if (Sseg[0]==' ') Sseg[0]='0';
//empezamos rutina para enviar informacion a SD
SPI1_Init_Advanced(_SPI_MASTER_OSC_DIV64, _SPI_DATA_SAMPLE_MIDDLE, _SPI_CLK_IDLE_LOW, _SPI_LOW_2_HIGH);
  if (Mmc_Fat_Init() == 0){
  SPI1_Init_Advanced(_SPI_MASTER_OSC_DIV4, _SPI_DATA_SAMPLE_MIDDLE, _SPI_CLK_IDLE_LOW, _SPI_LOW_2_HIGH);
  if(!Mmc_Fat_Exists(cama[c-1])){
    if(c>9){
      Mmc_Fat_Assign(cama[c-1], 0x80);
      Mmc_Fat_Append();
      Mmc_Fat_Write("CAMA:",5);
      Mmc_Fat_Write(Scama,3);
      Mmc_Fat_Write("\r\nFECHA DE REGISTRO:",20);
      Mmc_Fat_Write(Sdia,3);
      Mmc_Fat_Write(Smes,4);
      Mmc_Fat_Write(Syear,2);;
      Mmc_Fat_Write("\r\nHORA DE REGISTRO:",19);
      Mmc_Fat_Write(Shora,3);
      Mmc_Fat_Write(Smin,4);
      Mmc_Fat_Write(Sseg,2);
      Mmc_Fat_Write("\r\nNOMBRE: \r\n",12);
      Mmc_Fat_Write("SIN NOMBRE\r\n\r\n",14);
      Mmc_Fat_Write("OBSERVACIONES: \r\n",17);
      Mmc_Fat_Write("\r\n***LLAMADO REGISTRADO***\r\n",28);
      Mmc_Fat_Write("FECHA:",6);
      Mmc_Fat_Write(Sdia,3);
      Mmc_Fat_Write(Smes,4);
      Mmc_Fat_Write(Syear,2);;
      Mmc_Fat_Write("\r\nHORA:",7);
      Mmc_Fat_Write(Shora,3);
      Mmc_Fat_Write(Smin,4);
      Mmc_Fat_Write(Sseg,2);
      Mmc_Fat_Write(espacio,2);
      Mmc_Fat_Write(espacio,2);
      Mmc_Fat_Close();
      }
    else{
      Scama[1]=Scama[2];
      Mmc_Fat_Assign(cama[c-1], 0x80);
      Mmc_Fat_Append();
      Mmc_Fat_Write("CAMA:",5);
      Mmc_Fat_Write(Scama,2);
      Mmc_Fat_Write("\r\nFECHA DE REGISTRO:",20);
      Mmc_Fat_Write(Sdia,3);
      Mmc_Fat_Write(Smes,4);
      Mmc_Fat_Write(Syear,2);;
      Mmc_Fat_Write("\r\nHORA DE REGISTRO:",19);
      Mmc_Fat_Write(Shora,3);
      Mmc_Fat_Write(Smin,4);
      Mmc_Fat_Write(Sseg,2);
      Mmc_Fat_Write("\r\nNOMBRE: \r\n",12);
      Mmc_Fat_Write("SIN NOMBRE\r\n\r\n",14);
      Mmc_Fat_Write("OBSERVACIONES: \r\n",17);
      Mmc_Fat_Write("\r\n***LLAMADO REGISTRADO***\r\n",28);
      Mmc_Fat_Write("FECHA:",6);
      Mmc_Fat_Write(Sdia,3);
      Mmc_Fat_Write(Smes,4);
      Mmc_Fat_Write(Syear,2);;
      Mmc_Fat_Write("\r\nHORA:",7);
      Mmc_Fat_Write(Shora,3);
      Mmc_Fat_Write(Smin,4);
      Mmc_Fat_Write(Sseg,2);
      Mmc_Fat_Write(espacio,2);
      Mmc_Fat_Write(espacio,2);
      Mmc_Fat_Close();
    }
  }
  
  else {
      Mmc_Fat_Assign(cama[c-1], 0x80);
      Mmc_Fat_Append();
      Mmc_Fat_Write("\r\n***LLAMADO REGISTRADO***\r\n",28);
      Mmc_Fat_Write("FECHA:",6);
      Mmc_Fat_Write(Sdia,3);
      Mmc_Fat_Write(Smes,4);
      Mmc_Fat_Write(Syear,2);;
      Mmc_Fat_Write("\r\nHORA:",7);
      Mmc_Fat_Write(Shora,3);
      Mmc_Fat_Write(Smin,4);
      Mmc_Fat_Write(Sseg,2);
      Mmc_Fat_Write(espacio,2);
      Mmc_Fat_Write(espacio,2);
      Mmc_Fat_Close();
  }
}
}
void atendido(unsigned short c){
// declamos variables para enviar a la SD
char Scama[4];
char Sseg[4];
char Smin[4];
char Shora[4];
char Sdia[4];
char Smes[4];
char Syear[4];
// convertimos los datos a string
ByteToStr(c,Scama);
ByteToStr(seg,Sseg);
ByteToStr(min,Smin);
ByteToStr(hora,Shora);
ByteToStr(dia,Sdia);
ByteToStr(mes,Smes);
ByteToStr(year,Syear);
//arreglos esteticos en la fecha
Smes[0]='/';
Smes[3]='/';
Syear[0]=Syear[1];
Syear[1]=Syear[2];
if (Sdia[1]==' ') Sdia[1]='0';
if (Smes[1]==' ') Smes[1]='0';
if (Syear[0]==' ') Syear[0]='0';
//arreglos esteticos en la hora
Smin[0]=':';
Smin[3]=':';
Sseg[0]=Sseg[1];
Sseg[1]=Sseg[2];
if (Shora[1]==' ') Shora[1]='0';
if (Smin[1]==' ') Smin[1]='0';
if (Sseg[0]==' ') Sseg[0]='0';
//empezamos rutina para enviar informacion a SD
SPI1_Init_Advanced(_SPI_MASTER_OSC_DIV64, _SPI_DATA_SAMPLE_MIDDLE, _SPI_CLK_IDLE_LOW, _SPI_LOW_2_HIGH);
  if (Mmc_Fat_Init() == 0){
  SPI1_Init_Advanced(_SPI_MASTER_OSC_DIV4, _SPI_DATA_SAMPLE_MIDDLE, _SPI_CLK_IDLE_LOW, _SPI_LOW_2_HIGH);
        Mmc_Fat_Assign(cama[c-1], 0x80);
      Mmc_Fat_Append();
      Mmc_Fat_Write("---ATENDIDO---\r\n",16);
      Mmc_Fat_Write("FECHA:",6);
      Mmc_Fat_Write(Sdia,3);
      Mmc_Fat_Write(Smes,4);
      Mmc_Fat_Write(Syear,2);;
      Mmc_Fat_Write("\r\nHORA:",7);
      Mmc_Fat_Write(Shora,3);
      Mmc_Fat_Write(Smin,4);
      Mmc_Fat_Write(Sseg,2);
      Mmc_Fat_Write(espacio,2);
      Mmc_Fat_Write("\r\nMOTIVO: \r\n",12);
      Mmc_Fat_Write("-\r\n",3);
      Mmc_Fat_Write(espacio,2);
      Mmc_Fat_Close();
      }
}

void PCAon(unsigned short led){
  if (led==0)return;
  Soft_I2C_Init();
  Soft_I2C_Start();
  Soft_I2C_Write(dir_PCA); // address
  Soft_I2C_Write((led*4)+6); // LED0 register
  Soft_I2C_Write(0x00); // LSB 0
  Soft_I2C_Write(0x00); // MSB 0
  Soft_I2C_Write(0xff);  // LSB 4095
  Soft_I2C_Write(0x0f); // MSB 4095
  Soft_I2C_Stop();
  UART_Write(led);
}

void PCAoff(unsigned short led){
  Soft_I2C_Init();
  Soft_I2C_Start();
  Soft_I2C_Write(dir_PCA); // address
  Soft_I2C_Write((led*4)+6); // LED0 register
  Soft_I2C_Write(0xff); // LSB 4095
  Soft_I2C_Write(0x0f); // MSB 4095
  Soft_I2C_Write(0x00);  // LSB 0
  Soft_I2C_Write(0x00); // MSB 0
  Soft_I2C_Stop();
  UART_Write(led+0x32);
}

void PCAinit(){
  Soft_I2C_Init();
  Soft_I2C_Start();
  Soft_I2C_Write(dir_PCA); //addres
  Soft_I2C_Write(0x00); //Registro_Mode 1
  Soft_I2C_Write(0x21); //Mode 1
  Soft_I2C_Write(0x15); //Mode 2
  Soft_I2C_Stop();
}

void RTCinit(){
  Soft_I2C_Init();
  Soft_I2C_Start();
  Soft_I2C_Write(RTC_E);
  Soft_I2C_Write(0x07);
  Soft_I2C_Write(0x00);
  Soft_I2C_Stop();
}


void RTC_date_W(unsigned short Hr, unsigned short Min, unsigned short Seg,
                unsigned short Dia, unsigned short Mes, unsigned short Year){
  //Variables para tramsmitir lo datos
  unsigned short n;
  unsigned short BCD[6];
  BCD[0]=Seg;
  BCD[1]=Min;
  BCD[2]=Hr;
  BCD[3]=0x01;
  BCD[4]=Dia;
  BCD[5]=Mes;
  BCD[6]=Year;
  //Empecamos transmision por I2C
  Soft_I2C_Init();
  Soft_I2C_Start();
  Soft_I2C_Write(RTC_E);
  Soft_I2C_Write(0x00);
  for (n=0;n<=6;n++){
  
    Soft_I2C_Write(BCD[n]);
    }
  Soft_I2C_Stop();
}

void RTC_date_R(){
  //comenzamos comunicacion
  Soft_I2C_Init();
  Soft_I2C_Start();
  Soft_I2C_Write(RTC_E);
  Soft_I2C_Write(0x00);
  Soft_I2C_Stop();
  Soft_I2C_Start();
  Soft_I2C_Write(RTC_L);
  //recibimos datos
  seg=Soft_I2C_Read(1);
  min=Soft_I2C_Read(1);
  hora=Soft_I2C_Read(1);
  Soft_I2C_Read(1);
  dia=Soft_I2C_Read(1);
  mes=Soft_I2C_Read(1);
  year=Soft_I2C_Read(0);
  Soft_I2C_Stop();
  //arreglamos datos
  seg=Bcd2Dec(seg);
  min=Bcd2Dec(min);
  hora=Bcd2Dec(hora);
  dia=Bcd2Dec(dia);
  mes=Bcd2Dec(mes);
  year=Bcd2Dec(year);
}

unsigned short isnull(){
  unsigned short j;
  unsigned short suma=0;
  for(j=0;j<15;j++){
   suma = count[j]+suma;
  }
  return suma;
}

void contar(unsigned short i){
  count[i-1]++;
  if(count[i-1]==1){
    RTC_date_R();
    Fat_send(i);
  }
  if (count[i-1]==3){
    PCAoff(i);
    RTC_date_R();
    atendido(i);
    count[i-1]=0;
  }
  if(isnull()==0){
    PCA=1;
    buzzer=0;
  }
}
//convierte 2 numeros binarios de 8 bits a uno solo pero en BCD de 8 bits
//n1 es el mas significativo, n2 el menos significativo
unsigned short BCD(unsigned short n1, unsigned short n2){
  n1-=48;
  n2-=48;
  return ((n1<<4)+n2);
}

void main(){
//configuramos los pines
TRISB=0xff;
PCA_D=0;
buzzer_D=0;
//Ponemos en un estado lo pines de salida
PCA=1;
buzzer=0;
//configuramos el RS232
UART1_Init(9600);
//inicializamos los controladores
PCAinit();
RTCinit();
//estructura principal
  while(1){
    if(PORTB=!0){
      PCA=0;
      buzzer=1;
      hab=PORTB;
      PCAon(hab);
      contar(hab);
      Delay_ms(250);
    }
    if(UART_Data_Ready() == 1){
      unsigned short h[14];
      short TX = UART_Read();
        switch (TX){
          case 'e':
          UART_Write(0);
          break;
          case 'f':
          UART_Read_Text(h, "OK", 14);
          RTC_date_W(BCD(h[0],H[1]),BCD(h[2],H[3]),BCD(h[4],H[5]),
                     BCD(h[6],H[7]),BCD(h[8],H[9]),BCD(h[10],H[11]));
          break;
        }
    }
  }
}