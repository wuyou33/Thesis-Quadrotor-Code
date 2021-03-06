/* Include files */

#include <stddef.h>
#include "blas.h"
#include "QRsim_sfun.h"
#include "c26_QRsim.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "QRsim_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c26_debug_family_names[7] = { "nargin", "nargout", "R", "Rc",
  "Omega", "Omegac", "eOmega" };

/* Function Declarations */
static void initialize_c26_QRsim(SFc26_QRsimInstanceStruct *chartInstance);
static void initialize_params_c26_QRsim(SFc26_QRsimInstanceStruct *chartInstance);
static void enable_c26_QRsim(SFc26_QRsimInstanceStruct *chartInstance);
static void disable_c26_QRsim(SFc26_QRsimInstanceStruct *chartInstance);
static void c26_update_debugger_state_c26_QRsim(SFc26_QRsimInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c26_QRsim(SFc26_QRsimInstanceStruct
  *chartInstance);
static void set_sim_state_c26_QRsim(SFc26_QRsimInstanceStruct *chartInstance,
  const mxArray *c26_st);
static void finalize_c26_QRsim(SFc26_QRsimInstanceStruct *chartInstance);
static void sf_c26_QRsim(SFc26_QRsimInstanceStruct *chartInstance);
static void c26_chartstep_c26_QRsim(SFc26_QRsimInstanceStruct *chartInstance);
static void initSimStructsc26_QRsim(SFc26_QRsimInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c26_machineNumber, uint32_T
  c26_chartNumber);
static const mxArray *c26_sf_marshallOut(void *chartInstanceVoid, void
  *c26_inData);
static void c26_emlrt_marshallIn(SFc26_QRsimInstanceStruct *chartInstance, const
  mxArray *c26_eOmega, const char_T *c26_identifier, real_T c26_y[3]);
static void c26_b_emlrt_marshallIn(SFc26_QRsimInstanceStruct *chartInstance,
  const mxArray *c26_u, const emlrtMsgIdentifier *c26_parentId, real_T c26_y[3]);
static void c26_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c26_mxArrayInData, const char_T *c26_varName, void *c26_outData);
static const mxArray *c26_b_sf_marshallOut(void *chartInstanceVoid, void
  *c26_inData);
static const mxArray *c26_c_sf_marshallOut(void *chartInstanceVoid, void
  *c26_inData);
static const mxArray *c26_d_sf_marshallOut(void *chartInstanceVoid, void
  *c26_inData);
static real_T c26_c_emlrt_marshallIn(SFc26_QRsimInstanceStruct *chartInstance,
  const mxArray *c26_u, const emlrtMsgIdentifier *c26_parentId);
static void c26_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c26_mxArrayInData, const char_T *c26_varName, void *c26_outData);
static void c26_info_helper(const mxArray **c26_info);
static const mxArray *c26_emlrt_marshallOut(char * c26_u);
static const mxArray *c26_b_emlrt_marshallOut(uint32_T c26_u);
static void c26_eml_scalar_eg(SFc26_QRsimInstanceStruct *chartInstance);
static void c26_b_eml_scalar_eg(SFc26_QRsimInstanceStruct *chartInstance);
static const mxArray *c26_e_sf_marshallOut(void *chartInstanceVoid, void
  *c26_inData);
static int32_T c26_d_emlrt_marshallIn(SFc26_QRsimInstanceStruct *chartInstance,
  const mxArray *c26_u, const emlrtMsgIdentifier *c26_parentId);
static void c26_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c26_mxArrayInData, const char_T *c26_varName, void *c26_outData);
static uint8_T c26_e_emlrt_marshallIn(SFc26_QRsimInstanceStruct *chartInstance,
  const mxArray *c26_b_is_active_c26_QRsim, const char_T *c26_identifier);
static uint8_T c26_f_emlrt_marshallIn(SFc26_QRsimInstanceStruct *chartInstance,
  const mxArray *c26_u, const emlrtMsgIdentifier *c26_parentId);
static void init_dsm_address_info(SFc26_QRsimInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c26_QRsim(SFc26_QRsimInstanceStruct *chartInstance)
{
  chartInstance->c26_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c26_is_active_c26_QRsim = 0U;
}

static void initialize_params_c26_QRsim(SFc26_QRsimInstanceStruct *chartInstance)
{
}

static void enable_c26_QRsim(SFc26_QRsimInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c26_QRsim(SFc26_QRsimInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c26_update_debugger_state_c26_QRsim(SFc26_QRsimInstanceStruct
  *chartInstance)
{
}

static const mxArray *get_sim_state_c26_QRsim(SFc26_QRsimInstanceStruct
  *chartInstance)
{
  const mxArray *c26_st;
  const mxArray *c26_y = NULL;
  int32_T c26_i0;
  real_T c26_u[3];
  const mxArray *c26_b_y = NULL;
  uint8_T c26_hoistedGlobal;
  uint8_T c26_b_u;
  const mxArray *c26_c_y = NULL;
  real_T (*c26_eOmega)[3];
  c26_eOmega = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c26_st = NULL;
  c26_st = NULL;
  c26_y = NULL;
  sf_mex_assign(&c26_y, sf_mex_createcellarray(2), FALSE);
  for (c26_i0 = 0; c26_i0 < 3; c26_i0++) {
    c26_u[c26_i0] = (*c26_eOmega)[c26_i0];
  }

  c26_b_y = NULL;
  sf_mex_assign(&c26_b_y, sf_mex_create("y", c26_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_setcell(c26_y, 0, c26_b_y);
  c26_hoistedGlobal = chartInstance->c26_is_active_c26_QRsim;
  c26_b_u = c26_hoistedGlobal;
  c26_c_y = NULL;
  sf_mex_assign(&c26_c_y, sf_mex_create("y", &c26_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c26_y, 1, c26_c_y);
  sf_mex_assign(&c26_st, c26_y, FALSE);
  return c26_st;
}

static void set_sim_state_c26_QRsim(SFc26_QRsimInstanceStruct *chartInstance,
  const mxArray *c26_st)
{
  const mxArray *c26_u;
  real_T c26_dv0[3];
  int32_T c26_i1;
  real_T (*c26_eOmega)[3];
  c26_eOmega = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c26_doneDoubleBufferReInit = TRUE;
  c26_u = sf_mex_dup(c26_st);
  c26_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c26_u, 0)),
                       "eOmega", c26_dv0);
  for (c26_i1 = 0; c26_i1 < 3; c26_i1++) {
    (*c26_eOmega)[c26_i1] = c26_dv0[c26_i1];
  }

  chartInstance->c26_is_active_c26_QRsim = c26_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c26_u, 1)), "is_active_c26_QRsim");
  sf_mex_destroy(&c26_u);
  c26_update_debugger_state_c26_QRsim(chartInstance);
  sf_mex_destroy(&c26_st);
}

static void finalize_c26_QRsim(SFc26_QRsimInstanceStruct *chartInstance)
{
}

static void sf_c26_QRsim(SFc26_QRsimInstanceStruct *chartInstance)
{
  int32_T c26_i2;
  int32_T c26_i3;
  int32_T c26_i4;
  int32_T c26_i5;
  int32_T c26_i6;
  real_T (*c26_Omegac)[3];
  real_T (*c26_Omega)[3];
  real_T (*c26_eOmega)[3];
  real_T (*c26_Rc)[9];
  real_T (*c26_R)[9];
  c26_Omegac = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 3);
  c26_Omega = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 2);
  c26_eOmega = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c26_Rc = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 1);
  c26_R = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 14U, chartInstance->c26_sfEvent);
  for (c26_i2 = 0; c26_i2 < 9; c26_i2++) {
    _SFD_DATA_RANGE_CHECK((*c26_R)[c26_i2], 0U);
  }

  for (c26_i3 = 0; c26_i3 < 9; c26_i3++) {
    _SFD_DATA_RANGE_CHECK((*c26_Rc)[c26_i3], 1U);
  }

  for (c26_i4 = 0; c26_i4 < 3; c26_i4++) {
    _SFD_DATA_RANGE_CHECK((*c26_eOmega)[c26_i4], 2U);
  }

  for (c26_i5 = 0; c26_i5 < 3; c26_i5++) {
    _SFD_DATA_RANGE_CHECK((*c26_Omega)[c26_i5], 3U);
  }

  for (c26_i6 = 0; c26_i6 < 3; c26_i6++) {
    _SFD_DATA_RANGE_CHECK((*c26_Omegac)[c26_i6], 4U);
  }

  chartInstance->c26_sfEvent = CALL_EVENT;
  c26_chartstep_c26_QRsim(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_QRsimMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c26_chartstep_c26_QRsim(SFc26_QRsimInstanceStruct *chartInstance)
{
  int32_T c26_i7;
  real_T c26_R[9];
  int32_T c26_i8;
  real_T c26_Rc[9];
  int32_T c26_i9;
  real_T c26_Omega[3];
  int32_T c26_i10;
  real_T c26_Omegac[3];
  uint32_T c26_debug_family_var_map[7];
  real_T c26_nargin = 4.0;
  real_T c26_nargout = 1.0;
  real_T c26_eOmega[3];
  int32_T c26_i11;
  int32_T c26_i12;
  int32_T c26_i13;
  int32_T c26_i14;
  real_T c26_a[9];
  int32_T c26_i15;
  real_T c26_b[9];
  int32_T c26_i16;
  int32_T c26_i17;
  int32_T c26_i18;
  real_T c26_y[9];
  int32_T c26_i19;
  int32_T c26_i20;
  int32_T c26_i21;
  real_T c26_b_b[3];
  int32_T c26_i22;
  real_T c26_b_y[3];
  int32_T c26_i23;
  int32_T c26_i24;
  int32_T c26_i25;
  int32_T c26_i26;
  real_T (*c26_b_eOmega)[3];
  real_T (*c26_b_Omegac)[3];
  real_T (*c26_b_Omega)[3];
  real_T (*c26_b_Rc)[9];
  real_T (*c26_b_R)[9];
  c26_b_Omegac = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 3);
  c26_b_Omega = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 2);
  c26_b_eOmega = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c26_b_Rc = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 1);
  c26_b_R = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 14U, chartInstance->c26_sfEvent);
  for (c26_i7 = 0; c26_i7 < 9; c26_i7++) {
    c26_R[c26_i7] = (*c26_b_R)[c26_i7];
  }

  for (c26_i8 = 0; c26_i8 < 9; c26_i8++) {
    c26_Rc[c26_i8] = (*c26_b_Rc)[c26_i8];
  }

  for (c26_i9 = 0; c26_i9 < 3; c26_i9++) {
    c26_Omega[c26_i9] = (*c26_b_Omega)[c26_i9];
  }

  for (c26_i10 = 0; c26_i10 < 3; c26_i10++) {
    c26_Omegac[c26_i10] = (*c26_b_Omegac)[c26_i10];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 7U, 7U, c26_debug_family_names,
    c26_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c26_nargin, 0U, c26_d_sf_marshallOut,
    c26_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c26_nargout, 1U, c26_d_sf_marshallOut,
    c26_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c26_R, 2U, c26_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c26_Rc, 3U, c26_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c26_Omega, 4U, c26_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c26_Omegac, 5U, c26_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c26_eOmega, 6U, c26_sf_marshallOut,
    c26_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c26_sfEvent, 4);
  c26_i11 = 0;
  for (c26_i12 = 0; c26_i12 < 3; c26_i12++) {
    c26_i13 = 0;
    for (c26_i14 = 0; c26_i14 < 3; c26_i14++) {
      c26_a[c26_i14 + c26_i11] = c26_R[c26_i13 + c26_i12];
      c26_i13 += 3;
    }

    c26_i11 += 3;
  }

  for (c26_i15 = 0; c26_i15 < 9; c26_i15++) {
    c26_b[c26_i15] = c26_Rc[c26_i15];
  }

  c26_eml_scalar_eg(chartInstance);
  c26_eml_scalar_eg(chartInstance);
  for (c26_i16 = 0; c26_i16 < 3; c26_i16++) {
    c26_i17 = 0;
    for (c26_i18 = 0; c26_i18 < 3; c26_i18++) {
      c26_y[c26_i17 + c26_i16] = 0.0;
      c26_i19 = 0;
      for (c26_i20 = 0; c26_i20 < 3; c26_i20++) {
        c26_y[c26_i17 + c26_i16] += c26_a[c26_i19 + c26_i16] * c26_b[c26_i20 +
          c26_i17];
        c26_i19 += 3;
      }

      c26_i17 += 3;
    }
  }

  for (c26_i21 = 0; c26_i21 < 3; c26_i21++) {
    c26_b_b[c26_i21] = c26_Omegac[c26_i21];
  }

  c26_b_eml_scalar_eg(chartInstance);
  c26_b_eml_scalar_eg(chartInstance);
  for (c26_i22 = 0; c26_i22 < 3; c26_i22++) {
    c26_b_y[c26_i22] = 0.0;
    c26_i23 = 0;
    for (c26_i24 = 0; c26_i24 < 3; c26_i24++) {
      c26_b_y[c26_i22] += c26_y[c26_i23 + c26_i22] * c26_b_b[c26_i24];
      c26_i23 += 3;
    }
  }

  for (c26_i25 = 0; c26_i25 < 3; c26_i25++) {
    c26_eOmega[c26_i25] = c26_Omega[c26_i25] - c26_b_y[c26_i25];
  }

  _SFD_EML_CALL(0U, chartInstance->c26_sfEvent, -4);
  _SFD_SYMBOL_SCOPE_POP();
  for (c26_i26 = 0; c26_i26 < 3; c26_i26++) {
    (*c26_b_eOmega)[c26_i26] = c26_eOmega[c26_i26];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 14U, chartInstance->c26_sfEvent);
}

static void initSimStructsc26_QRsim(SFc26_QRsimInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c26_machineNumber, uint32_T
  c26_chartNumber)
{
}

static const mxArray *c26_sf_marshallOut(void *chartInstanceVoid, void
  *c26_inData)
{
  const mxArray *c26_mxArrayOutData = NULL;
  int32_T c26_i27;
  real_T c26_b_inData[3];
  int32_T c26_i28;
  real_T c26_u[3];
  const mxArray *c26_y = NULL;
  SFc26_QRsimInstanceStruct *chartInstance;
  chartInstance = (SFc26_QRsimInstanceStruct *)chartInstanceVoid;
  c26_mxArrayOutData = NULL;
  for (c26_i27 = 0; c26_i27 < 3; c26_i27++) {
    c26_b_inData[c26_i27] = (*(real_T (*)[3])c26_inData)[c26_i27];
  }

  for (c26_i28 = 0; c26_i28 < 3; c26_i28++) {
    c26_u[c26_i28] = c26_b_inData[c26_i28];
  }

  c26_y = NULL;
  sf_mex_assign(&c26_y, sf_mex_create("y", c26_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_assign(&c26_mxArrayOutData, c26_y, FALSE);
  return c26_mxArrayOutData;
}

static void c26_emlrt_marshallIn(SFc26_QRsimInstanceStruct *chartInstance, const
  mxArray *c26_eOmega, const char_T *c26_identifier, real_T c26_y[3])
{
  emlrtMsgIdentifier c26_thisId;
  c26_thisId.fIdentifier = c26_identifier;
  c26_thisId.fParent = NULL;
  c26_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c26_eOmega), &c26_thisId,
    c26_y);
  sf_mex_destroy(&c26_eOmega);
}

static void c26_b_emlrt_marshallIn(SFc26_QRsimInstanceStruct *chartInstance,
  const mxArray *c26_u, const emlrtMsgIdentifier *c26_parentId, real_T c26_y[3])
{
  real_T c26_dv1[3];
  int32_T c26_i29;
  sf_mex_import(c26_parentId, sf_mex_dup(c26_u), c26_dv1, 1, 0, 0U, 1, 0U, 1, 3);
  for (c26_i29 = 0; c26_i29 < 3; c26_i29++) {
    c26_y[c26_i29] = c26_dv1[c26_i29];
  }

  sf_mex_destroy(&c26_u);
}

static void c26_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c26_mxArrayInData, const char_T *c26_varName, void *c26_outData)
{
  const mxArray *c26_eOmega;
  const char_T *c26_identifier;
  emlrtMsgIdentifier c26_thisId;
  real_T c26_y[3];
  int32_T c26_i30;
  SFc26_QRsimInstanceStruct *chartInstance;
  chartInstance = (SFc26_QRsimInstanceStruct *)chartInstanceVoid;
  c26_eOmega = sf_mex_dup(c26_mxArrayInData);
  c26_identifier = c26_varName;
  c26_thisId.fIdentifier = c26_identifier;
  c26_thisId.fParent = NULL;
  c26_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c26_eOmega), &c26_thisId,
    c26_y);
  sf_mex_destroy(&c26_eOmega);
  for (c26_i30 = 0; c26_i30 < 3; c26_i30++) {
    (*(real_T (*)[3])c26_outData)[c26_i30] = c26_y[c26_i30];
  }

  sf_mex_destroy(&c26_mxArrayInData);
}

static const mxArray *c26_b_sf_marshallOut(void *chartInstanceVoid, void
  *c26_inData)
{
  const mxArray *c26_mxArrayOutData = NULL;
  int32_T c26_i31;
  real_T c26_b_inData[3];
  int32_T c26_i32;
  real_T c26_u[3];
  const mxArray *c26_y = NULL;
  SFc26_QRsimInstanceStruct *chartInstance;
  chartInstance = (SFc26_QRsimInstanceStruct *)chartInstanceVoid;
  c26_mxArrayOutData = NULL;
  for (c26_i31 = 0; c26_i31 < 3; c26_i31++) {
    c26_b_inData[c26_i31] = (*(real_T (*)[3])c26_inData)[c26_i31];
  }

  for (c26_i32 = 0; c26_i32 < 3; c26_i32++) {
    c26_u[c26_i32] = c26_b_inData[c26_i32];
  }

  c26_y = NULL;
  sf_mex_assign(&c26_y, sf_mex_create("y", c26_u, 0, 0U, 1U, 0U, 2, 3, 1), FALSE);
  sf_mex_assign(&c26_mxArrayOutData, c26_y, FALSE);
  return c26_mxArrayOutData;
}

static const mxArray *c26_c_sf_marshallOut(void *chartInstanceVoid, void
  *c26_inData)
{
  const mxArray *c26_mxArrayOutData = NULL;
  int32_T c26_i33;
  int32_T c26_i34;
  int32_T c26_i35;
  real_T c26_b_inData[9];
  int32_T c26_i36;
  int32_T c26_i37;
  int32_T c26_i38;
  real_T c26_u[9];
  const mxArray *c26_y = NULL;
  SFc26_QRsimInstanceStruct *chartInstance;
  chartInstance = (SFc26_QRsimInstanceStruct *)chartInstanceVoid;
  c26_mxArrayOutData = NULL;
  c26_i33 = 0;
  for (c26_i34 = 0; c26_i34 < 3; c26_i34++) {
    for (c26_i35 = 0; c26_i35 < 3; c26_i35++) {
      c26_b_inData[c26_i35 + c26_i33] = (*(real_T (*)[9])c26_inData)[c26_i35 +
        c26_i33];
    }

    c26_i33 += 3;
  }

  c26_i36 = 0;
  for (c26_i37 = 0; c26_i37 < 3; c26_i37++) {
    for (c26_i38 = 0; c26_i38 < 3; c26_i38++) {
      c26_u[c26_i38 + c26_i36] = c26_b_inData[c26_i38 + c26_i36];
    }

    c26_i36 += 3;
  }

  c26_y = NULL;
  sf_mex_assign(&c26_y, sf_mex_create("y", c26_u, 0, 0U, 1U, 0U, 2, 3, 3), FALSE);
  sf_mex_assign(&c26_mxArrayOutData, c26_y, FALSE);
  return c26_mxArrayOutData;
}

static const mxArray *c26_d_sf_marshallOut(void *chartInstanceVoid, void
  *c26_inData)
{
  const mxArray *c26_mxArrayOutData = NULL;
  real_T c26_u;
  const mxArray *c26_y = NULL;
  SFc26_QRsimInstanceStruct *chartInstance;
  chartInstance = (SFc26_QRsimInstanceStruct *)chartInstanceVoid;
  c26_mxArrayOutData = NULL;
  c26_u = *(real_T *)c26_inData;
  c26_y = NULL;
  sf_mex_assign(&c26_y, sf_mex_create("y", &c26_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c26_mxArrayOutData, c26_y, FALSE);
  return c26_mxArrayOutData;
}

static real_T c26_c_emlrt_marshallIn(SFc26_QRsimInstanceStruct *chartInstance,
  const mxArray *c26_u, const emlrtMsgIdentifier *c26_parentId)
{
  real_T c26_y;
  real_T c26_d0;
  sf_mex_import(c26_parentId, sf_mex_dup(c26_u), &c26_d0, 1, 0, 0U, 0, 0U, 0);
  c26_y = c26_d0;
  sf_mex_destroy(&c26_u);
  return c26_y;
}

static void c26_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c26_mxArrayInData, const char_T *c26_varName, void *c26_outData)
{
  const mxArray *c26_nargout;
  const char_T *c26_identifier;
  emlrtMsgIdentifier c26_thisId;
  real_T c26_y;
  SFc26_QRsimInstanceStruct *chartInstance;
  chartInstance = (SFc26_QRsimInstanceStruct *)chartInstanceVoid;
  c26_nargout = sf_mex_dup(c26_mxArrayInData);
  c26_identifier = c26_varName;
  c26_thisId.fIdentifier = c26_identifier;
  c26_thisId.fParent = NULL;
  c26_y = c26_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c26_nargout),
    &c26_thisId);
  sf_mex_destroy(&c26_nargout);
  *(real_T *)c26_outData = c26_y;
  sf_mex_destroy(&c26_mxArrayInData);
}

const mxArray *sf_c26_QRsim_get_eml_resolved_functions_info(void)
{
  const mxArray *c26_nameCaptureInfo = NULL;
  c26_nameCaptureInfo = NULL;
  sf_mex_assign(&c26_nameCaptureInfo, sf_mex_createstruct("structure", 2, 10, 1),
                FALSE);
  c26_info_helper(&c26_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c26_nameCaptureInfo);
  return c26_nameCaptureInfo;
}

static void c26_info_helper(const mxArray **c26_info)
{
  const mxArray *c26_rhs0 = NULL;
  const mxArray *c26_lhs0 = NULL;
  const mxArray *c26_rhs1 = NULL;
  const mxArray *c26_lhs1 = NULL;
  const mxArray *c26_rhs2 = NULL;
  const mxArray *c26_lhs2 = NULL;
  const mxArray *c26_rhs3 = NULL;
  const mxArray *c26_lhs3 = NULL;
  const mxArray *c26_rhs4 = NULL;
  const mxArray *c26_lhs4 = NULL;
  const mxArray *c26_rhs5 = NULL;
  const mxArray *c26_lhs5 = NULL;
  const mxArray *c26_rhs6 = NULL;
  const mxArray *c26_lhs6 = NULL;
  const mxArray *c26_rhs7 = NULL;
  const mxArray *c26_lhs7 = NULL;
  const mxArray *c26_rhs8 = NULL;
  const mxArray *c26_lhs8 = NULL;
  const mxArray *c26_rhs9 = NULL;
  const mxArray *c26_lhs9 = NULL;
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("mtimes"), "name", "name", 0);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1363713878U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c26_rhs0, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c26_lhs0, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m!common_checks"),
                  "context", "context", 1);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 1);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c26_rhs1, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c26_lhs1, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "context",
                  "context", 2);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 2);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1323170578U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c26_rhs2, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c26_lhs2, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 3);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 3);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1286818796U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c26_rhs3, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c26_lhs3, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_xgemm"), "name", "name",
                  4);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1363713870U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c26_rhs4, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c26_lhs4, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_blas_inline"), "name",
                  "name", 5);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1299076768U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c26_rhs5, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c26_lhs5, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m!below_threshold"),
                  "context", "context", 6);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("mtimes"), "name", "name", 6);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "resolved",
                  "resolved", 6);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1363713878U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c26_rhs6, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c26_lhs6, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs6), "lhs", "lhs",
                  6);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m"),
                  "context", "context", 7);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 7);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1323170578U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c26_rhs7, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c26_lhs7, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs7), "rhs", "rhs",
                  7);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs7), "lhs", "lhs",
                  7);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m"),
                  "context", "context", 8);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 8);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 8);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1286818796U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c26_rhs8, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c26_lhs8, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs8), "rhs", "rhs",
                  8);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs8), "lhs", "lhs",
                  8);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m"),
                  "context", "context", 9);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_refblas_xgemm"), "name",
                  "name", 9);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1360282350U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c26_rhs9, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c26_lhs9, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs9), "rhs", "rhs",
                  9);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs9), "lhs", "lhs",
                  9);
  sf_mex_destroy(&c26_rhs0);
  sf_mex_destroy(&c26_lhs0);
  sf_mex_destroy(&c26_rhs1);
  sf_mex_destroy(&c26_lhs1);
  sf_mex_destroy(&c26_rhs2);
  sf_mex_destroy(&c26_lhs2);
  sf_mex_destroy(&c26_rhs3);
  sf_mex_destroy(&c26_lhs3);
  sf_mex_destroy(&c26_rhs4);
  sf_mex_destroy(&c26_lhs4);
  sf_mex_destroy(&c26_rhs5);
  sf_mex_destroy(&c26_lhs5);
  sf_mex_destroy(&c26_rhs6);
  sf_mex_destroy(&c26_lhs6);
  sf_mex_destroy(&c26_rhs7);
  sf_mex_destroy(&c26_lhs7);
  sf_mex_destroy(&c26_rhs8);
  sf_mex_destroy(&c26_lhs8);
  sf_mex_destroy(&c26_rhs9);
  sf_mex_destroy(&c26_lhs9);
}

static const mxArray *c26_emlrt_marshallOut(char * c26_u)
{
  const mxArray *c26_y = NULL;
  c26_y = NULL;
  sf_mex_assign(&c26_y, sf_mex_create("y", c26_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c26_u)), FALSE);
  return c26_y;
}

static const mxArray *c26_b_emlrt_marshallOut(uint32_T c26_u)
{
  const mxArray *c26_y = NULL;
  c26_y = NULL;
  sf_mex_assign(&c26_y, sf_mex_create("y", &c26_u, 7, 0U, 0U, 0U, 0), FALSE);
  return c26_y;
}

static void c26_eml_scalar_eg(SFc26_QRsimInstanceStruct *chartInstance)
{
}

static void c26_b_eml_scalar_eg(SFc26_QRsimInstanceStruct *chartInstance)
{
}

static const mxArray *c26_e_sf_marshallOut(void *chartInstanceVoid, void
  *c26_inData)
{
  const mxArray *c26_mxArrayOutData = NULL;
  int32_T c26_u;
  const mxArray *c26_y = NULL;
  SFc26_QRsimInstanceStruct *chartInstance;
  chartInstance = (SFc26_QRsimInstanceStruct *)chartInstanceVoid;
  c26_mxArrayOutData = NULL;
  c26_u = *(int32_T *)c26_inData;
  c26_y = NULL;
  sf_mex_assign(&c26_y, sf_mex_create("y", &c26_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c26_mxArrayOutData, c26_y, FALSE);
  return c26_mxArrayOutData;
}

static int32_T c26_d_emlrt_marshallIn(SFc26_QRsimInstanceStruct *chartInstance,
  const mxArray *c26_u, const emlrtMsgIdentifier *c26_parentId)
{
  int32_T c26_y;
  int32_T c26_i39;
  sf_mex_import(c26_parentId, sf_mex_dup(c26_u), &c26_i39, 1, 6, 0U, 0, 0U, 0);
  c26_y = c26_i39;
  sf_mex_destroy(&c26_u);
  return c26_y;
}

static void c26_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c26_mxArrayInData, const char_T *c26_varName, void *c26_outData)
{
  const mxArray *c26_b_sfEvent;
  const char_T *c26_identifier;
  emlrtMsgIdentifier c26_thisId;
  int32_T c26_y;
  SFc26_QRsimInstanceStruct *chartInstance;
  chartInstance = (SFc26_QRsimInstanceStruct *)chartInstanceVoid;
  c26_b_sfEvent = sf_mex_dup(c26_mxArrayInData);
  c26_identifier = c26_varName;
  c26_thisId.fIdentifier = c26_identifier;
  c26_thisId.fParent = NULL;
  c26_y = c26_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c26_b_sfEvent),
    &c26_thisId);
  sf_mex_destroy(&c26_b_sfEvent);
  *(int32_T *)c26_outData = c26_y;
  sf_mex_destroy(&c26_mxArrayInData);
}

static uint8_T c26_e_emlrt_marshallIn(SFc26_QRsimInstanceStruct *chartInstance,
  const mxArray *c26_b_is_active_c26_QRsim, const char_T *c26_identifier)
{
  uint8_T c26_y;
  emlrtMsgIdentifier c26_thisId;
  c26_thisId.fIdentifier = c26_identifier;
  c26_thisId.fParent = NULL;
  c26_y = c26_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c26_b_is_active_c26_QRsim), &c26_thisId);
  sf_mex_destroy(&c26_b_is_active_c26_QRsim);
  return c26_y;
}

static uint8_T c26_f_emlrt_marshallIn(SFc26_QRsimInstanceStruct *chartInstance,
  const mxArray *c26_u, const emlrtMsgIdentifier *c26_parentId)
{
  uint8_T c26_y;
  uint8_T c26_u0;
  sf_mex_import(c26_parentId, sf_mex_dup(c26_u), &c26_u0, 1, 3, 0U, 0, 0U, 0);
  c26_y = c26_u0;
  sf_mex_destroy(&c26_u);
  return c26_y;
}

static void init_dsm_address_info(SFc26_QRsimInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

void sf_c26_QRsim_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3522763969U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1439774683U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(4041730355U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3418927475U);
}

mxArray *sf_c26_QRsim_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("rSaPyzSv2TQVl2ExleYRXB");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,4,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(3);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(3);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(1);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c26_QRsim_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c26_QRsim_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c26_QRsim(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[9],T\"eOmega\",},{M[8],M[0],T\"is_active_c26_QRsim\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c26_QRsim_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc26_QRsimInstanceStruct *chartInstance;
    chartInstance = (SFc26_QRsimInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _QRsimMachineNumber_,
           26,
           1,
           1,
           5,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           ssGetPath(S),
           (void *)S);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          init_script_number_translation(_QRsimMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_QRsimMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _QRsimMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"R");
          _SFD_SET_DATA_PROPS(1,1,1,0,"Rc");
          _SFD_SET_DATA_PROPS(2,2,0,1,"eOmega");
          _SFD_SET_DATA_PROPS(3,1,1,0,"Omega");
          _SFD_SET_DATA_PROPS(4,1,1,0,"Omegac");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,101);

        {
          unsigned int dimVector[2];
          dimVector[0]= 3;
          dimVector[1]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c26_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 3;
          dimVector[1]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c26_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c26_sf_marshallOut,(MexInFcnForType)
            c26_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 3;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c26_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 3;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c26_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          real_T (*c26_R)[9];
          real_T (*c26_Rc)[9];
          real_T (*c26_eOmega)[3];
          real_T (*c26_Omega)[3];
          real_T (*c26_Omegac)[3];
          c26_Omegac = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 3);
          c26_Omega = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 2);
          c26_eOmega = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
          c26_Rc = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 1);
          c26_R = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c26_R);
          _SFD_SET_DATA_VALUE_PTR(1U, *c26_Rc);
          _SFD_SET_DATA_VALUE_PTR(2U, *c26_eOmega);
          _SFD_SET_DATA_VALUE_PTR(3U, *c26_Omega);
          _SFD_SET_DATA_VALUE_PTR(4U, *c26_Omegac);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _QRsimMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "nVARRS0Y25NNuFHSQMNhEG";
}

static void sf_opaque_initialize_c26_QRsim(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc26_QRsimInstanceStruct*) chartInstanceVar)->S,
    0);
  initialize_params_c26_QRsim((SFc26_QRsimInstanceStruct*) chartInstanceVar);
  initialize_c26_QRsim((SFc26_QRsimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c26_QRsim(void *chartInstanceVar)
{
  enable_c26_QRsim((SFc26_QRsimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c26_QRsim(void *chartInstanceVar)
{
  disable_c26_QRsim((SFc26_QRsimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c26_QRsim(void *chartInstanceVar)
{
  sf_c26_QRsim((SFc26_QRsimInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c26_QRsim(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c26_QRsim((SFc26_QRsimInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c26_QRsim();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_raw2high'.\n");
  }

  return plhs[0];
}

extern void sf_internal_set_sim_state_c26_QRsim(SimStruct* S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c26_QRsim();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c26_QRsim((SFc26_QRsimInstanceStruct*)chartInfo->chartInstance,
    mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c26_QRsim(SimStruct* S)
{
  return sf_internal_get_sim_state_c26_QRsim(S);
}

static void sf_opaque_set_sim_state_c26_QRsim(SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c26_QRsim(S, st);
}

static void sf_opaque_terminate_c26_QRsim(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc26_QRsimInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_QRsim_optimization_info();
    }

    finalize_c26_QRsim((SFc26_QRsimInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc26_QRsim((SFc26_QRsimInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c26_QRsim(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c26_QRsim((SFc26_QRsimInstanceStruct*)(((ChartInfoStruct *)
      ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c26_QRsim(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_QRsim_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      26);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,26,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,26,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,26);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,26,4);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,26,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 4; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,26);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(154564544U));
  ssSetChecksum1(S,(2051090316U));
  ssSetChecksum2(S,(1114333268U));
  ssSetChecksum3(S,(3217006477U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c26_QRsim(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c26_QRsim(SimStruct *S)
{
  SFc26_QRsimInstanceStruct *chartInstance;
  chartInstance = (SFc26_QRsimInstanceStruct *)utMalloc(sizeof
    (SFc26_QRsimInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc26_QRsimInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c26_QRsim;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c26_QRsim;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c26_QRsim;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c26_QRsim;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c26_QRsim;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c26_QRsim;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c26_QRsim;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c26_QRsim;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c26_QRsim;
  chartInstance->chartInfo.mdlStart = mdlStart_c26_QRsim;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c26_QRsim;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->S = S;
  ssSetUserData(S,(void *)(&(chartInstance->chartInfo)));/* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
  chart_debug_initialization(S,1);
}

void c26_QRsim_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c26_QRsim(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c26_QRsim(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c26_QRsim(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c26_QRsim_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
