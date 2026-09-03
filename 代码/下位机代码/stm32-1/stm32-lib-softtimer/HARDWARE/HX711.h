#ifndef __HX711_H
#define __HX711_H

#include "sys.h"
#include "pin_define.h"

void yali_init(void);

void yali_Weight_calibration(void); //calibration the weight

int yali_Get_Weight(void);


#endif

