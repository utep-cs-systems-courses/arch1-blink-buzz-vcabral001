#ifndef buzzer_included

#define buzzer_included



#define C3  7634

#define CS3 7194

#define D3  6803

#define DS3 6410

#define E3  6061

#define F3  5714

#define FS3 5405

#define G3  5102

#define GS3 4808

#define A3  4545

#define AS3 4292

#define B3  4049

#define C4  3817

#define CS4 3610

#define D4  3788

#define DS4 3401

#define E4  3030

#define F4  2865

#define FS4 2703

#define G4  2551

#define GS4 2410

#define A4  2273

#define AS4 2146

#define B4  2024

#define C5  1912

#define CS5 1805

#define D5  1704

#define DS5 1608

#define E5  1517

#define F5  1433

#define FS5 1351

#define G5  1276

#define GS5 1203

#define A5  1136

#define AS5 1073

#define B5  1012

#define C6  855

#define CS6 902



// void delay_ms(unsigned int ms);

// void delay_us(unsigned int us);

// void beep(unsigned short note);



void buzzer_init();

void buzzer_advance_frequency();

void buzzer_set_period(short cycles);



#endif // included
