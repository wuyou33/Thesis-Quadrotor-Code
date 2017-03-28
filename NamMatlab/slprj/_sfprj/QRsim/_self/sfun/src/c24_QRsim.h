#ifndef __c24_QRsim_h__
#define __c24_QRsim_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc24_QRsimInstanceStruct
#define typedef_SFc24_QRsimInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c24_sfEvent;
  boolean_T c24_isStable;
  boolean_T c24_doneDoubleBufferReInit;
  uint8_T c24_is_active_c24_QRsim;
} SFc24_QRsimInstanceStruct;

#endif                                 /*typedef_SFc24_QRsimInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c24_QRsim_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c24_QRsim_get_check_sum(mxArray *plhs[]);
extern void c24_QRsim_method_dispatcher(SimStruct *S, int_T method, void *data);

#endif
