const int trigger_pin = 2;

const int echo_pin = 4;



unsigned long simdikizaman;

unsigned long oncekizaman = 0;



float sayac;

float sure;

float mesafe;

float hiz;



void setup() 

{

  pinMode(trigger_pin , OUTPUT);

  pinMode(echo_pin , INPUT);

  Serial.begin(9600);

}



void loop() 

{

  digitalWrite(trigger_pin , HIGH);

  delayMicroseconds(1000);

  digitalWrite(trigger_pin , LOW);

  sure = pulseIn(echo_pin , HIGH);

  mesafe = (sure/2) / 28.5;

  if (mesafe < 50)

  {

    program1();

  }

}

void program1()

{

  simdikizaman = millis();

  digitalWrite(trigger_pin , HIGH);

  delayMicroseconds(1000);

  digitalWrite(trigger_pin , LOW);

  sure = pulseIn(echo_pin , HIGH);

  mesafe = (sure/2) / 28.5;

  if (mesafe > 50)

  {

    sayac = simdikizaman - oncekizaman;

    sayac = sayac / 1000;

    oncekizaman = simdikizaman;

    hiz = 0.2 / sayac;

    Serial.println(hiz);

  }

}
