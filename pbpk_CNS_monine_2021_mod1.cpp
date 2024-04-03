Model file:  pbpk_cns_monine_2021_mod1.cpp 
$PARAM @annotated
TVKLT1  :  0.6942  	: CSF transfer up from lumbar to thoracic regions (h-1)
TVKTC1  :  5.464    : CSF transfer up from thoracic to cervical regions (h-1)
TVKCP1  :  0.09471  : CSF transfer up from cervical to proximal brain regions (h-1)
TVKPD1  :  0.03722  : CSF transfer up from proximal brain to distal brain regions (h-1)

TVKTL1  :  0.1386   : CSF transfer down from thoracic to lumbar regions (h-1)
TVKCT1  :  2.366	: CSF transfer down from cervical to thoracic regions (h-1)
TVKPC1  :  0.05027  : CSF transfer down from proximal brain to cervical regions (h-1)
TVKDP1  :  2.6e-7   : CSF transfer down from distal brain to proximal brain regions (h-1)

TVKL12  :  1.6e-3   : transfer from lumbar CSF to spinal cord tissue (h-1)
TVKT12  :  3.3e-3   : transfer from thoracic CSF to spinal cord tissue (h-1)
TVKC12  :  6.1e-4   : transfer from cervical CSF to spinal cord tissue (h-1)

TVKL21  :  6.8e-4   : transfer from spinal cord tissue back to lumbar CSF (h-1)
TVKT21  :  8.3e-4   : transfer from spinal cord tissue back to thoracic CSF (h-1)
TVKC21  :  7.2e-4   : transfer from spinal cord tissue back to cervical CSF (h-1)

TVKP13  :  2.3e-4   : transfer from proximal brain CSF to pons tissue (h-1)
TVKB13  :  2.5e-3   : transfer from proximal brain CSF to cerebellum tissue (h-1)
TVKH13  :  4.1e-4   : transfer from proximal brain CSF to hippocampus tissue (h-1)
TVKX13  :  2.9e-3   : transfer from distal brain CSF to cortex tissue (h-1)

TVKP31  :  7.5e-4   : transfer from pons tissue back to proximal brain CSF (h-1)
TVKB31  :  6.3e-3   : transfer from cerebellum tissue back to proximal brain CSF (h-1)
TVKH31  :  7.2e-4   : transfer from hippocampus tissue back to proximal brain CSF (h-1)
TVKX31  :  1.5e-3   : transfer from cortex tissue back to distal brain CSF (h-1)

TVKS14 	:  0.2428   : transfer from spinal CSF to blood (h-1)
TVKB14 	:  2.3e-3   : transfer from cranial CSF to blood (h-1)
TVKDEG 	:  5.9e-6   : CNS tissue metabolism (h-1)

TVK45 	:  0.9821   : transfer from plasma to liver (h-1)
TVK54 	:  9.5e-12   : transfer from liver to plasma (h-1)
TVK46 	:  0.4189   : transfer from plasma to kidney (h-1)
TVK64  	:  4.9e-7   : transfer from kidney to plasma (h-1)

TVK40  	:  3.1e-4   : transfer from cortex tissue back to distal brain CSF (h-1)
TVK50  	:  3.1e-3   : transfer from cortex tissue back to distal brain CSF (h-1)
TVK60  	:  2.0e-3   : transfer from cortex tissue back to distal brain CSF (h-1)

TVVL1   :  2   		: volume of lumbar CSF (mL)
TVVT1   :  3  		: volume of thoracic CSF (mL)
TVVC1   :  2.5   	: volume of cervical CSF (mL)
TVVP1   :  4.5 		: volume of proximal brain CSF (mL)
TVVD1   :  3	   	: volume of distal brain CSF (mL)

TVVL2   :  1.5		: volume of lumbar spinal cord tissue (g)
TVVT2   :  2.5		: volume of thoracic spinal cord tissue (g)
TVVC2   :  2 		: volume of cervical spinal cord tissue (g)
TVVP3   :  1.5  	: volume of pons tissue (g)
TVVB3   :  8	  	: volume of cerebellum tissue (g)
TVVH3   :  1.5  	: volume of hippocampus tissue (g)
TVVX3   :  54	   	: volume of cortex tissue (g)

TVVA4   :  224  	: volume of plasma (mL)
TVVA5   :  150  	: volume of liver tissue (g)
TVVA6   :  25		: volume of kidney tissue (g)


$CMT @annotated
L1  : Lumbar CSF 
L2  : Lumbar Spinal Cord Tissue
T1  : Thoracic CSF
T2  : Thoracic Spinal Cord Tissue
C1  : Cervical CSF 
C2  : Cervical Spinal Cord Tissue 
P1  : Proximal brain CSF
P3  : Pons Tissue
B3  : Cerebellum Tissue
H3  : Hippocampus Tissue
D1  : Distal brain CSF
X3  : Cortex Tissue
A4  : Plasma
A5  : Liver
A6  : Kidney
 
 
$OMEGA @name @annotated 
ETA_KLT1  :  0   : CSF transfer up from lumbar to thoracic regions (IIV)
ETA_KTC1  :  0   : CSF transfer up from thoracic to cervical regions (IIV)
ETA_KCP1  :  0   : CSF transfer up from cervical to proximal brain regions (IIV)
ETA_KPD1  :  0   : CSF transfer up from proximal brain to distal brain regions (IIV)

ETA_KTL1  :  0   : CSF transfer down from thoracic to lumbar regions (IIV)
ETA_KCT1  :  0	  : CSF transfer down from cervical to thoracic regions (IIV)
ETA_KPC1  :  0   : CSF transfer down from proximal brain to cervical regions (IIV)
ETA_KDP1  :  0   : CSF transfer down from distal brain to proximal brain regions (IIV)

ETA_KL12  :  0   : transfer from lumbar CSF to spinal cord tissue (IIV)
ETA_KT12  :  0   : transfer from thoracic CSF to spinal cord tissue (IIV)
ETA_KC12  :  0   : transfer from cervical CSF to spinal cord tissue (IIV)

ETA_KL21  :  0   : transfer from spinal cord tissue back to lumbar CSF (IIV)
ETA_KT21  :  0   : transfer from spinal cord tissue back to thoracic CSF (IIV)
ETA_KC21  :  0   : transfer from spinal cord tissue back to cervical CSF (IIV)

ETA_KP13  :  0   : transfer from proximal brain CSF to pons tissue (IIV)
ETA_KB13  :  0   : transfer from proximal brain CSF to cerebellum tissue (IIV)
ETA_KH13  :  0   : transfer from proximal brain CSF to hippocampus tissue (IIV)
ETA_KX13  :  0   : transfer from distal brain CSF to cortex tissue (IIV)

ETA_KP31  :  0   : transfer from pons tissue back to proximal brain CSF (IIV)
ETA_KB31  :  0   : transfer from cerebellum tissue back to proximal brain CSF (IIV)
ETA_KH31  :  0   : transfer from hippocampus tissue back to proximal brain CSF (IIV)
ETA_KX31  :  0   : transfer from cortex tissue back to distal brain CSF (IIV)

ETA_KS14  :  0   : transfer from spinal CSF to blood (IIV)
ETA_KB14  :  0   : transfer from cranial CSF to blood (IIV)
ETA_KDEG  :  0   : CNS tissue metabolism (IIV)

ETA_K45   :  0   : transfer from plasma to liver (IIV)
ETA_K54   :  0   : transfer from liver to plasma (IIV)
ETA_K46   :  0   : transfer from plasma to kidney (IIV)
ETA_K64   :  0   : transfer from kidney to plasma (IIV)

ETA_K40   :  0   : transfer from cortex tissue back to distal brain CSF (IIV)
ETA_K50   :  0   : transfer from cortex tissue back to distal brain CSF (IIV)
ETA_K60   :  0   : transfer from cortex tissue back to distal brain CSF (IIV)

ETA_VL1   :  0   : volume of lumbar CSF (IIV)
ETA_VT1   :  0   : volume of thoracic CSF (IIV)
ETA_VC1   :  0   : volume of cervical CSF (IIV)
ETA_VP1   :  0   : volume of proximal brain CSF (IIV)
ETA_VD1   :  0	  : volume of distal brain CSF (IIV)

ETA_VL2   :  0   : volume of lumbar spinal cord tissue (IIV)
ETA_VT2   :  0   : volume of thoracic spinal cord tissue (IIV)
ETA_VC2   :  0   : volume of cervical spinal cord tissue (IIV)
ETA_VP3   :  0   : volume of pons tissue (IIV)
ETA_VB3   :  0   : volume of cerebellum tissue (IIV)
ETA_VH3   :  0   : volume of hippocampus tissue (IIV)
ETA_VX3   :  0	 : volume of cortex tissue (IIV)

ETA_VA4   :  0   : volume of plasma (IIV)
ETA_VA5   :  0   : volume of liver tissue (IIV)
ETA_VA6   :  0	 : volume of kidney tissue (IIV)


$MAIN
double KLT1 = TVKLT1*exp(ETA_KLT1);  
double KTC1 = TVKTC1*exp(ETA_KTC1);
double KCP1 = TVKCP1*exp(ETA_KCP1);
double KPD1 = TVKPD1*exp(ETA_KPD1); 

double KTL1 = TVKTL1*exp(ETA_KTL1);  
double KCT1 = TVKCT1*exp(ETA_KCT1);
double KPC1 = TVKPC1*exp(ETA_KPC1);
double KDP1 = TVKDP1*exp(ETA_KDP1);

double KL12 = TVKL12*exp(ETA_KL12);
double KT12 = TVKT12*exp(ETA_KT12);
double KC12 = TVKC12*exp(ETA_KC12);

double KL21 = TVKL21*exp(ETA_KL21);
double KT21 = TVKT21*exp(ETA_KT21);
double KC21 = TVKC21*exp(ETA_KC21);

double KP13 = TVKP13*exp(ETA_KP13);
double KB13 = TVKB13*exp(ETA_KB13);
double KH13 = TVKH13*exp(ETA_KH13);
double KX13 = TVKX13*exp(ETA_KX13);

double KP31 = TVKP31*exp(ETA_KP31);
double KB31 = TVKB31*exp(ETA_KB31);
double KH31 = TVKH31*exp(ETA_KH31);
double KX31 = TVKX31*exp(ETA_KX31);

double KS14 = TVKS14*exp(ETA_KS14);
double KB14 = TVKB14*exp(ETA_KB14);
double KDEG = TVKDEG*exp(ETA_KDEG);

double K45 = TVK45*exp(ETA_K45);
double K54 = TVK54*exp(ETA_K54);
double K46 = TVK46*exp(ETA_K46);
double K64 = TVK64*exp(ETA_K64);

double K40 = TVK40*exp(ETA_K40);
double K50 = TVK50*exp(ETA_K50);
double K60 = TVK60*exp(ETA_K60);

double VL1 = TVVL1*exp(ETA_VL1);
double VT1 = TVVT1*exp(ETA_VT1);
double VC1 = TVVC1*exp(ETA_VC1);
double VP1 = TVVP1*exp(ETA_VP1);
double VD1 = TVVD1*exp(ETA_VD1);

double VL2 = TVVL2*exp(ETA_VL2);
double VT2 = TVVT2*exp(ETA_VT2);
double VC2 = TVVC2*exp(ETA_VC2);
double VP3 = TVVP3*exp(ETA_VP3);
double VB3 = TVVB3*exp(ETA_VB3);
double VH3 = TVVH3*exp(ETA_VH3);
double VX3 = TVVX3*exp(ETA_VX3);

double VA4 = TVVA4*exp(ETA_VA4);
double VA5 = TVVA5*exp(ETA_VA5);
double VA6 = TVVA6*exp(ETA_VA6);


$GLOBAL
#define CL1 (L1/VL1)
#define CL2 (L2/VL2)
#define CT1 (T1/VT1)
#define CT2 (T2/VT2)
#define CC1 (C1/VC1)
#define CC2 (C2/VC2)
#define CP1 (P1/VP1)
#define CP3 (P3/VP3)
#define CB3 (B3/VB3)
#define CH3 (H3/VH3)
#define CD1 (D1/VD1)
#define CX3 (X3/VX3)
#define CA4 (A4/VA4)
#define CA5 (A5/VA5)
#define CA6 (A6/VA6)

$SIGMA @annotated
LOG_ADD_L1  : 0  : Log Additive Residual Error (Lumbar CSF)
LOG_ADD_L2  : 0  : Log Additive Residual Error (Lumbar Spinal Cord)
LOG_ADD_T1  : 0  : Log Additive Residual Error (Thoracic CSF)
LOG_ADD_T2  : 0  : Log Additive Residual Error (Thoracic Spinal Cord)
LOG_ADD_C1  : 0  : Log Additive Residual Error (Cervical CSF)
LOG_ADD_C2  : 0  : Log Additive Residual Error (Cervical Spinal Cord)
LOG_ADD_P1  : 0  : Log Additive Residual Error (Proximal Brain CSF)
LOG_ADD_P3  : 0  : Log Additive Residual Error (Pons Tissue)
LOG_ADD_B3  : 0  : Log Additive Residual Error (Cerebellum Tissue)
LOG_ADD_H3  : 0  : Log Additive Residual Error (Hippocampus Tissue)
LOG_ADD_D1  : 0  : Log Additive Residual Error (Distal Brain CSF)
LOG_ADD_X3  : 0  : Log Additive Residual Error (Cortex Tissue)
LOG_ADD_A4  : 0  : Log Additive Residual Error (Plasma)
LOG_ADD_A5  : 0  : Log Additive Residual Error (Liver Tissue)
LOG_ADD_A6  : 0  : Log Additive Residual Error (Kidney Tissue)

$ODE
dxdt_L1 = -(KS14 + KL12 + KLT1)*L1 + KL21*L2 + KTL1*T1;
dxdt_L2 = KL12*L1 - KL21*L2 - KDEG*L2;

dxdt_T1 = -(KS14 + KT12 + KTC1 + KTL1)*T1 + KLT1*L1 + KT21*T2 + KCT1*C1;
dxdt_T2 = KT12*T1 - KT21*T2 - KDEG*T2;

dxdt_C1 = -(KS14 + KC12 + KCP1 + KCT1)*C1 + KTC1*T1 + KC21*C2 + KPC1*P1;
dxdt_C2 = KC12*C1 - KC21*C2 - KDEG*C2;

dxdt_P1 = -(KB14 + KP13 + KB13 + KH13 + KPC1 + KPD1)*P1 + KDP1*D1 + KCP1*C1 + KP31*P3 + KB31*B3 + KH31*H3;
dxdt_P3 = KP13*P1 - KP31*P3 - KDEG*P3;
dxdt_B3 = KB13*P1 - KB31*B3 - KDEG*B3;
dxdt_H3 = KH13*P1 - KH31*H3 - KDEG*H3;

dxdt_D1 = -(KB13 + KX13 + KDP1)*D1 + KPD1*P1 + KX31*X3;
dxdt_X3 = KX13*D1 - KX31*X3 - KDEG*X3;

dxdt_A4 = KS14*(L1 + T1 + C1) + KB13*(P1 + D1) - K40*A4 - K45*A4 + K54*A5 - K46*A4 + K64*A6;
dxdt_A5 = K45*A4 - K54*A5 - K50*A5;
dxdt_A6 = K46*A4 - K64*A6 - K60*A6;

  
$TABLE
capture LumbarCSF_mL = CL1; 
capture LumbarCord_g = CL2; 
capture ThoracicCSF_mL = CT1; 
capture ThoracicCord_g = CT2; 
capture CervicalCSF_mL = CC1; 
capture CervicalCord_g = CC2; 
capture ProxBrainCSF_mL = CP1;
capture Pons_g = CP3; 
capture Cerebellum_g = CB3;
capture Hippocampus_g = CH3;
capture DistBrainCSF_mL = CD1;
capture Cortex_g = CX3;
capture Plasma_mL = CA4;
capture Liver_g = CA5;
capture Kidney_g = CA6;
