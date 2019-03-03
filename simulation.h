#ifndef SIMULATION_H_
#define SIMULATION_H_

typedef struct
{
    int width;
    int height;
    int  screenMultiplier;
    int  screenMargin;
    uint32_t windowBackColor;
} simcfg_t;

simcfg_t* GUI_SimCfg(void);

void GUI_Setup(void *pset, void *flush, int w, int h);

void GUI_Process(void);

#endif
