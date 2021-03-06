/* Include files */

#include <stddef.h>
#include "blas.h"
#include "QRsim_sfun.h"
#include "c22_QRsim.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "QRsim_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c22_debug_family_names[7] = { "nargin", "nargout", "b1d",
  "b3c", "b1c", "b2c", "Rc" };

/* Function Declarations */
static void initialize_c22_QRsim(SFc22_QRsimInstanceStruct *chartInstance);
static void initialize_params_c22_QRsim(SFc22_QRsimInstanceStruct *chartInstance);
static void enable_c22_QRsim(SFc22_QRsimInstanceStruct *chartInstance);
static void disable_c22_QRsim(SFc22_QRsimInstanceStruct *chartInstance);
static void c22_update_debugger_state_c22_QRsim(SFc22_QRsimInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c22_QRsim(SFc22_QRsimInstanceStruct
  *chartInstance);
static void set_sim_state_c22_QRsim(SFc22_QRsimInstanceStruct *chartInstance,
  const mxArray *c22_st);
static void finalize_c22_QRsim(SFc22_QRsimInstanceStruct *chartInstance);
static void sf_c22_QRsim(SFc22_QRsimInstanceStruct *chartInstance);
static void c22_chartstep_c22_QRsim(SFc22_QRsimInstanceStruct *chartInstance);
static void initSimStructsc22_QRsim(SFc22_QRsimInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c22_machineNumber, uint32_T
  c22_chartNumber);
static const mxArray *c22_sf_marshallOut(void *chartInstanceVoid, void
  *c22_inData);
static void c22_emlrt_marshallIn(SFc22_QRsimInstanceStruct *chartInstance, const
  mxArray *c22_Rc, const char_T *c22_identifier, real_T c22_y[9]);
static void c22_b_emlrt_marshallIn(SFc22_QRsimInstanceStruct *chartInstance,
  const mxArray *c22_u, const emlrtMsgIdentifier *c22_parentId, real_T c22_y[9]);
static void c22_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c22_mxArrayInData, const char_T *c22_varName, void *c22_outData);
static const mxArray *c22_b_sf_marshallOut(void *chartInstanceVoid, void
  *c22_inData);
static void c22_c_emlrt_marshallIn(SFc22_QRsimInstanceStruct *chartInstance,
  const mxArray *c22_b2c, const char_T *c22_identifier, real_T c22_y[3]);
static void c22_d_emlrt_marshallIn(SFc22_QRsimInstanceStruct *chartInstance,
  const mxArray *c22_u, const emlrtMsgIdentifier *c22_parentId, real_T c22_y[3]);
static void c22_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c22_mxArrayInData, const char_T *c22_varName, void *c22_outData);
static const mxArray *c22_c_sf_marshallOut(void *chartInstanceVoid, void
  *c22_inData);
static const mxArray *c22_d_sf_marshallOut(void *chartInstanceVoid, void
  *c22_inData);
static real_T c22_e_emlrt_marshallIn(SFc22_QRsimInstanceStruct *chartInstance,
  const mxArray *c22_u, const emlrtMsgIdentifier *c22_parentId);
static void c22_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c22_mxArrayInData, const char_T *c22_varName, void *c22_outData);
static void c22_info_helper(const mxArray **c22_info);
static const mxArray *c22_emlrt_marshallOut(char * c22_u);
static const mxArray *c22_b_emlrt_marshallOut(uint32_T c22_u);
static void c22_cross(SFc22_QRsimInstanceStruct *chartInstance, real_T c22_a[3],
                      real_T c22_b[3], real_T c22_c[3]);
static const mxArray *c22_e_sf_marshallOut(void *chartInstanceVoid, void
  *c22_inData);
static int32_T c22_f_emlrt_marshallIn(SFc22_QRsimInstanceStruct *chartInstance,
  const mxArray *c22_u, const emlrtMsgIdentifier *c22_parentId);
static void c22_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c22_mxArrayInData, const char_T *c22_varName, void *c22_outData);
static uint8_T c22_g_emlrt_marshallIn(SFc22_QRsimInstanceStruct *chartInstance,
  const mxArray *c22_b_is_active_c22_QRsim, const char_T *c22_identifier);
static uint8_T c22_h_emlrt_marshallIn(SFc22_QRsimInstanceStruct *chartInstance,
  const mxArray *c22_u, const emlrtMsgIdentifier *c22_parentId);
static void init_dsm_address_info(SFc22_QRsimInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c22_QRsim(SFc22_QRsimInstanceStruct *chartInstance)
{
  chartInstance->c22_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c22_is_active_c22_QRsim = 0U;
}

static void initialize_params_c22_QRsim(SFc22_QRsimInstanceStruct *chartInstance)
{
}

static void enable_c22_QRsim(SFc22_QRsimInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c22_QRsim(SFc22_QRsimInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c22_update_debugger_state_c22_QRsim(SFc22_QRsimInstanceStruct
  *chartInstance)
{
}

static const mxArray *get_sim_state_c22_QRsim(SFc22_QRsimInstanceStruct
  *chartInstance)
{
  const mxArray *c22_st;
  const mxArray *c22_y = NULL;
  int32_T c22_i0;
  real_T c22_u[9];
  const mxArray *c22_b_y = NULL;
  int32_T c22_i1;
  real_T c22_b_u[3];
  const mxArray *c22_c_y = NULL;
  int32_T c22_i2;
  real_T c22_c_u[3];
  const mxArray *c22_d_y = NULL;
  uint8_T c22_hoistedGlobal;
  uint8_T c22_d_u;
  const mxArray *c22_e_y = NULL;
  real_T (*c22_b2c)[3];
  real_T (*c22_b1c)[3];
  real_T (*c22_Rc)[9];
  c22_Rc = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 3);
  c22_b2c = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
  c22_b1c = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c22_st = NULL;
  c22_st = NULL;
  c22_y = NULL;
  sf_mex_assign(&c22_y, sf_mex_createcellarray(4), FALSE);
  for (c22_i0 = 0; c22_i0 < 9; c22_i0++) {
    c22_u[c22_i0] = (*c22_Rc)[c22_i0];
  }

  c22_b_y = NULL;
  sf_mex_assign(&c22_b_y, sf_mex_create("y", c22_u, 0, 0U, 1U, 0U, 2, 3, 3),
                FALSE);
  sf_mex_setcell(c22_y, 0, c22_b_y);
  for (c22_i1 = 0; c22_i1 < 3; c22_i1++) {
    c22_b_u[c22_i1] = (*c22_b1c)[c22_i1];
  }

  c22_c_y = NULL;
  sf_mex_assign(&c22_c_y, sf_mex_create("y", c22_b_u, 0, 0U, 1U, 0U, 1, 3),
                FALSE);
  sf_mex_setcell(c22_y, 1, c22_c_y);
  for (c22_i2 = 0; c22_i2 < 3; c22_i2++) {
    c22_c_u[c22_i2] = (*c22_b2c)[c22_i2];
  }

  c22_d_y = NULL;
  sf_mex_assign(&c22_d_y, sf_mex_create("y", c22_c_u, 0, 0U, 1U, 0U, 1, 3),
                FALSE);
  sf_mex_setcell(c22_y, 2, c22_d_y);
  c22_hoistedGlobal = chartInstance->c22_is_active_c22_QRsim;
  c22_d_u = c22_hoistedGlobal;
  c22_e_y = NULL;
  sf_mex_assign(&c22_e_y, sf_mex_create("y", &c22_d_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c22_y, 3, c22_e_y);
  sf_mex_assign(&c22_st, c22_y, FALSE);
  return c22_st;
}

static void set_sim_state_c22_QRsim(SFc22_QRsimInstanceStruct *chartInstance,
  const mxArray *c22_st)
{
  const mxArray *c22_u;
  real_T c22_dv0[9];
  int32_T c22_i3;
  real_T c22_dv1[3];
  int32_T c22_i4;
  real_T c22_dv2[3];
  int32_T c22_i5;
  real_T (*c22_Rc)[9];
  real_T (*c22_b1c)[3];
  real_T (*c22_b2c)[3];
  c22_Rc = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 3);
  c22_b2c = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
  c22_b1c = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c22_doneDoubleBufferReInit = TRUE;
  c22_u = sf_mex_dup(c22_st);
  c22_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c22_u, 0)), "Rc",
                       c22_dv0);
  for (c22_i3 = 0; c22_i3 < 9; c22_i3++) {
    (*c22_Rc)[c22_i3] = c22_dv0[c22_i3];
  }

  c22_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c22_u, 1)),
    "b1c", c22_dv1);
  for (c22_i4 = 0; c22_i4 < 3; c22_i4++) {
    (*c22_b1c)[c22_i4] = c22_dv1[c22_i4];
  }

  c22_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c22_u, 2)),
    "b2c", c22_dv2);
  for (c22_i5 = 0; c22_i5 < 3; c22_i5++) {
    (*c22_b2c)[c22_i5] = c22_dv2[c22_i5];
  }

  chartInstance->c22_is_active_c22_QRsim = c22_g_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c22_u, 3)), "is_active_c22_QRsim");
  sf_mex_destroy(&c22_u);
  c22_update_debugger_state_c22_QRsim(chartInstance);
  sf_mex_destroy(&c22_st);
}

static void finalize_c22_QRsim(SFc22_QRsimInstanceStruct *chartInstance)
{
}

static void sf_c22_QRsim(SFc22_QRsimInstanceStruct *chartInstance)
{
  int32_T c22_i6;
  int32_T c22_i7;
  int32_T c22_i8;
  int32_T c22_i9;
  int32_T c22_i10;
  real_T (*c22_b3c)[3];
  real_T (*c22_Rc)[9];
  real_T (*c22_b1d)[3];
  real_T (*c22_b2c)[3];
  real_T (*c22_b1c)[3];
  c22_b3c = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 1);
  c22_Rc = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 3);
  c22_b1d = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
  c22_b2c = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
  c22_b1c = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 13U, chartInstance->c22_sfEvent);
  for (c22_i6 = 0; c22_i6 < 3; c22_i6++) {
    _SFD_DATA_RANGE_CHECK((*c22_b1c)[c22_i6], 0U);
  }

  for (c22_i7 = 0; c22_i7 < 3; c22_i7++) {
    _SFD_DATA_RANGE_CHECK((*c22_b2c)[c22_i7], 1U);
  }

  for (c22_i8 = 0; c22_i8 < 3; c22_i8++) {
    _SFD_DATA_RANGE_CHECK((*c22_b1d)[c22_i8], 2U);
  }

  for (c22_i9 = 0; c22_i9 < 9; c22_i9++) {
    _SFD_DATA_RANGE_CHECK((*c22_Rc)[c22_i9], 3U);
  }

  for (c22_i10 = 0; c22_i10 < 3; c22_i10++) {
    _SFD_DATA_RANGE_CHECK((*c22_b3c)[c22_i10], 4U);
  }

  chartInstance->c22_sfEvent = CALL_EVENT;
  c22_chartstep_c22_QRsim(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_QRsimMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c22_chartstep_c22_QRsim(SFc22_QRsimInstanceStruct *chartInstance)
{
  int32_T c22_i11;
  real_T c22_b1d[3];
  int32_T c22_i12;
  real_T c22_b3c[3];
  uint32_T c22_debug_family_var_map[7];
  real_T c22_nargin = 2.0;
  real_T c22_nargout = 3.0;
  real_T c22_b1c[3];
  real_T c22_b2c[3];
  real_T c22_Rc[9];
  int32_T c22_i13;
  real_T c22_b_b3c[3];
  int32_T c22_i14;
  real_T c22_b_b1d[3];
  real_T c22_x[3];
  real_T c22_y;
  real_T c22_scale;
  int32_T c22_k;
  int32_T c22_b_k;
  real_T c22_b_x;
  real_T c22_c_x;
  real_T c22_absxk;
  real_T c22_t;
  int32_T c22_i15;
  real_T c22_c_b3c[3];
  int32_T c22_i16;
  real_T c22_c_b1d[3];
  real_T c22_B;
  real_T c22_b_y;
  real_T c22_c_y;
  int32_T c22_i17;
  int32_T c22_i18;
  real_T c22_d_b3c[3];
  int32_T c22_i19;
  real_T c22_d_x[3];
  int32_T c22_i20;
  int32_T c22_i21;
  real_T c22_e_b3c[3];
  int32_T c22_i22;
  real_T c22_b_b1c[3];
  real_T c22_dv3[3];
  int32_T c22_i23;
  int32_T c22_i24;
  int32_T c22_i25;
  int32_T c22_i26;
  int32_T c22_i27;
  int32_T c22_i28;
  int32_T c22_i29;
  real_T (*c22_c_b1c)[3];
  real_T (*c22_b_b2c)[3];
  real_T (*c22_b_Rc)[9];
  real_T (*c22_f_b3c)[3];
  real_T (*c22_d_b1d)[3];
  c22_f_b3c = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 1);
  c22_b_Rc = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 3);
  c22_d_b1d = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
  c22_b_b2c = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
  c22_c_b1c = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 13U, chartInstance->c22_sfEvent);
  for (c22_i11 = 0; c22_i11 < 3; c22_i11++) {
    c22_b1d[c22_i11] = (*c22_d_b1d)[c22_i11];
  }

  for (c22_i12 = 0; c22_i12 < 3; c22_i12++) {
    c22_b3c[c22_i12] = (*c22_f_b3c)[c22_i12];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 7U, 7U, c22_debug_family_names,
    c22_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c22_nargin, 0U, c22_d_sf_marshallOut,
    c22_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c22_nargout, 1U, c22_d_sf_marshallOut,
    c22_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c22_b1d, 2U, c22_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c22_b3c, 3U, c22_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c22_b1c, 4U, c22_b_sf_marshallOut,
    c22_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c22_b2c, 5U, c22_b_sf_marshallOut,
    c22_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c22_Rc, 6U, c22_sf_marshallOut,
    c22_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c22_sfEvent, 3);
  for (c22_i13 = 0; c22_i13 < 3; c22_i13++) {
    c22_b_b3c[c22_i13] = c22_b3c[c22_i13];
  }

  for (c22_i14 = 0; c22_i14 < 3; c22_i14++) {
    c22_b_b1d[c22_i14] = c22_b1d[c22_i14];
  }

  c22_cross(chartInstance, c22_b_b3c, c22_b_b1d, c22_x);
  c22_y = 0.0;
  c22_scale = 2.2250738585072014E-308;
  for (c22_k = 1; c22_k < 4; c22_k++) {
    c22_b_k = c22_k;
    c22_b_x = c22_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
      "", (real_T)c22_b_k), 1, 3, 1, 0) - 1];
    c22_c_x = c22_b_x;
    c22_absxk = muDoubleScalarAbs(c22_c_x);
    if (c22_absxk > c22_scale) {
      c22_t = c22_scale / c22_absxk;
      c22_y = 1.0 + c22_y * c22_t * c22_t;
      c22_scale = c22_absxk;
    } else {
      c22_t = c22_absxk / c22_scale;
      c22_y += c22_t * c22_t;
    }
  }

  c22_y = c22_scale * muDoubleScalarSqrt(c22_y);
  for (c22_i15 = 0; c22_i15 < 3; c22_i15++) {
    c22_c_b3c[c22_i15] = c22_b3c[c22_i15];
  }

  for (c22_i16 = 0; c22_i16 < 3; c22_i16++) {
    c22_c_b1d[c22_i16] = c22_b1d[c22_i16];
  }

  c22_cross(chartInstance, c22_c_b3c, c22_c_b1d, c22_x);
  c22_B = c22_y;
  c22_b_y = c22_B;
  c22_c_y = c22_b_y;
  for (c22_i17 = 0; c22_i17 < 3; c22_i17++) {
    c22_x[c22_i17] /= c22_c_y;
  }

  for (c22_i18 = 0; c22_i18 < 3; c22_i18++) {
    c22_d_b3c[c22_i18] = c22_b3c[c22_i18];
  }

  for (c22_i19 = 0; c22_i19 < 3; c22_i19++) {
    c22_d_x[c22_i19] = c22_x[c22_i19];
  }

  c22_cross(chartInstance, c22_d_b3c, c22_d_x, c22_x);
  for (c22_i20 = 0; c22_i20 < 3; c22_i20++) {
    c22_b1c[c22_i20] = -c22_x[c22_i20];
  }

  _SFD_EML_CALL(0U, chartInstance->c22_sfEvent, 5);
  for (c22_i21 = 0; c22_i21 < 3; c22_i21++) {
    c22_e_b3c[c22_i21] = c22_b3c[c22_i21];
  }

  for (c22_i22 = 0; c22_i22 < 3; c22_i22++) {
    c22_b_b1c[c22_i22] = c22_b1c[c22_i22];
  }

  c22_cross(chartInstance, c22_e_b3c, c22_b_b1c, c22_dv3);
  for (c22_i23 = 0; c22_i23 < 3; c22_i23++) {
    c22_b2c[c22_i23] = c22_dv3[c22_i23];
  }

  _SFD_EML_CALL(0U, chartInstance->c22_sfEvent, 6);
  for (c22_i24 = 0; c22_i24 < 3; c22_i24++) {
    c22_Rc[c22_i24] = c22_b1c[c22_i24];
  }

  for (c22_i25 = 0; c22_i25 < 3; c22_i25++) {
    c22_Rc[c22_i25 + 3] = c22_b2c[c22_i25];
  }

  for (c22_i26 = 0; c22_i26 < 3; c22_i26++) {
    c22_Rc[c22_i26 + 6] = c22_b3c[c22_i26];
  }

  _SFD_EML_CALL(0U, chartInstance->c22_sfEvent, -6);
  _SFD_SYMBOL_SCOPE_POP();
  for (c22_i27 = 0; c22_i27 < 3; c22_i27++) {
    (*c22_c_b1c)[c22_i27] = c22_b1c[c22_i27];
  }

  for (c22_i28 = 0; c22_i28 < 3; c22_i28++) {
    (*c22_b_b2c)[c22_i28] = c22_b2c[c22_i28];
  }

  for (c22_i29 = 0; c22_i29 < 9; c22_i29++) {
    (*c22_b_Rc)[c22_i29] = c22_Rc[c22_i29];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 13U, chartInstance->c22_sfEvent);
}

static void initSimStructsc22_QRsim(SFc22_QRsimInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c22_machineNumber, uint32_T
  c22_chartNumber)
{
}

static const mxArray *c22_sf_marshallOut(void *chartInstanceVoid, void
  *c22_inData)
{
  const mxArray *c22_mxArrayOutData = NULL;
  int32_T c22_i30;
  int32_T c22_i31;
  int32_T c22_i32;
  real_T c22_b_inData[9];
  int32_T c22_i33;
  int32_T c22_i34;
  int32_T c22_i35;
  real_T c22_u[9];
  const mxArray *c22_y = NULL;
  SFc22_QRsimInstanceStruct *chartInstance;
  chartInstance = (SFc22_QRsimInstanceStruct *)chartInstanceVoid;
  c22_mxArrayOutData = NULL;
  c22_i30 = 0;
  for (c22_i31 = 0; c22_i31 < 3; c22_i31++) {
    for (c22_i32 = 0; c22_i32 < 3; c22_i32++) {
      c22_b_inData[c22_i32 + c22_i30] = (*(real_T (*)[9])c22_inData)[c22_i32 +
        c22_i30];
    }

    c22_i30 += 3;
  }

  c22_i33 = 0;
  for (c22_i34 = 0; c22_i34 < 3; c22_i34++) {
    for (c22_i35 = 0; c22_i35 < 3; c22_i35++) {
      c22_u[c22_i35 + c22_i33] = c22_b_inData[c22_i35 + c22_i33];
    }

    c22_i33 += 3;
  }

  c22_y = NULL;
  sf_mex_assign(&c22_y, sf_mex_create("y", c22_u, 0, 0U, 1U, 0U, 2, 3, 3), FALSE);
  sf_mex_assign(&c22_mxArrayOutData, c22_y, FALSE);
  return c22_mxArrayOutData;
}

static void c22_emlrt_marshallIn(SFc22_QRsimInstanceStruct *chartInstance, const
  mxArray *c22_Rc, const char_T *c22_identifier, real_T c22_y[9])
{
  emlrtMsgIdentifier c22_thisId;
  c22_thisId.fIdentifier = c22_identifier;
  c22_thisId.fParent = NULL;
  c22_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c22_Rc), &c22_thisId, c22_y);
  sf_mex_destroy(&c22_Rc);
}

static void c22_b_emlrt_marshallIn(SFc22_QRsimInstanceStruct *chartInstance,
  const mxArray *c22_u, const emlrtMsgIdentifier *c22_parentId, real_T c22_y[9])
{
  real_T c22_dv4[9];
  int32_T c22_i36;
  sf_mex_import(c22_parentId, sf_mex_dup(c22_u), c22_dv4, 1, 0, 0U, 1, 0U, 2, 3,
                3);
  for (c22_i36 = 0; c22_i36 < 9; c22_i36++) {
    c22_y[c22_i36] = c22_dv4[c22_i36];
  }

  sf_mex_destroy(&c22_u);
}

static void c22_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c22_mxArrayInData, const char_T *c22_varName, void *c22_outData)
{
  const mxArray *c22_Rc;
  const char_T *c22_identifier;
  emlrtMsgIdentifier c22_thisId;
  real_T c22_y[9];
  int32_T c22_i37;
  int32_T c22_i38;
  int32_T c22_i39;
  SFc22_QRsimInstanceStruct *chartInstance;
  chartInstance = (SFc22_QRsimInstanceStruct *)chartInstanceVoid;
  c22_Rc = sf_mex_dup(c22_mxArrayInData);
  c22_identifier = c22_varName;
  c22_thisId.fIdentifier = c22_identifier;
  c22_thisId.fParent = NULL;
  c22_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c22_Rc), &c22_thisId, c22_y);
  sf_mex_destroy(&c22_Rc);
  c22_i37 = 0;
  for (c22_i38 = 0; c22_i38 < 3; c22_i38++) {
    for (c22_i39 = 0; c22_i39 < 3; c22_i39++) {
      (*(real_T (*)[9])c22_outData)[c22_i39 + c22_i37] = c22_y[c22_i39 + c22_i37];
    }

    c22_i37 += 3;
  }

  sf_mex_destroy(&c22_mxArrayInData);
}

static const mxArray *c22_b_sf_marshallOut(void *chartInstanceVoid, void
  *c22_inData)
{
  const mxArray *c22_mxArrayOutData = NULL;
  int32_T c22_i40;
  real_T c22_b_inData[3];
  int32_T c22_i41;
  real_T c22_u[3];
  const mxArray *c22_y = NULL;
  SFc22_QRsimInstanceStruct *chartInstance;
  chartInstance = (SFc22_QRsimInstanceStruct *)chartInstanceVoid;
  c22_mxArrayOutData = NULL;
  for (c22_i40 = 0; c22_i40 < 3; c22_i40++) {
    c22_b_inData[c22_i40] = (*(real_T (*)[3])c22_inData)[c22_i40];
  }

  for (c22_i41 = 0; c22_i41 < 3; c22_i41++) {
    c22_u[c22_i41] = c22_b_inData[c22_i41];
  }

  c22_y = NULL;
  sf_mex_assign(&c22_y, sf_mex_create("y", c22_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_assign(&c22_mxArrayOutData, c22_y, FALSE);
  return c22_mxArrayOutData;
}

static void c22_c_emlrt_marshallIn(SFc22_QRsimInstanceStruct *chartInstance,
  const mxArray *c22_b2c, const char_T *c22_identifier, real_T c22_y[3])
{
  emlrtMsgIdentifier c22_thisId;
  c22_thisId.fIdentifier = c22_identifier;
  c22_thisId.fParent = NULL;
  c22_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c22_b2c), &c22_thisId, c22_y);
  sf_mex_destroy(&c22_b2c);
}

static void c22_d_emlrt_marshallIn(SFc22_QRsimInstanceStruct *chartInstance,
  const mxArray *c22_u, const emlrtMsgIdentifier *c22_parentId, real_T c22_y[3])
{
  real_T c22_dv5[3];
  int32_T c22_i42;
  sf_mex_import(c22_parentId, sf_mex_dup(c22_u), c22_dv5, 1, 0, 0U, 1, 0U, 1, 3);
  for (c22_i42 = 0; c22_i42 < 3; c22_i42++) {
    c22_y[c22_i42] = c22_dv5[c22_i42];
  }

  sf_mex_destroy(&c22_u);
}

static void c22_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c22_mxArrayInData, const char_T *c22_varName, void *c22_outData)
{
  const mxArray *c22_b2c;
  const char_T *c22_identifier;
  emlrtMsgIdentifier c22_thisId;
  real_T c22_y[3];
  int32_T c22_i43;
  SFc22_QRsimInstanceStruct *chartInstance;
  chartInstance = (SFc22_QRsimInstanceStruct *)chartInstanceVoid;
  c22_b2c = sf_mex_dup(c22_mxArrayInData);
  c22_identifier = c22_varName;
  c22_thisId.fIdentifier = c22_identifier;
  c22_thisId.fParent = NULL;
  c22_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c22_b2c), &c22_thisId, c22_y);
  sf_mex_destroy(&c22_b2c);
  for (c22_i43 = 0; c22_i43 < 3; c22_i43++) {
    (*(real_T (*)[3])c22_outData)[c22_i43] = c22_y[c22_i43];
  }

  sf_mex_destroy(&c22_mxArrayInData);
}

static const mxArray *c22_c_sf_marshallOut(void *chartInstanceVoid, void
  *c22_inData)
{
  const mxArray *c22_mxArrayOutData = NULL;
  int32_T c22_i44;
  real_T c22_b_inData[3];
  int32_T c22_i45;
  real_T c22_u[3];
  const mxArray *c22_y = NULL;
  SFc22_QRsimInstanceStruct *chartInstance;
  chartInstance = (SFc22_QRsimInstanceStruct *)chartInstanceVoid;
  c22_mxArrayOutData = NULL;
  for (c22_i44 = 0; c22_i44 < 3; c22_i44++) {
    c22_b_inData[c22_i44] = (*(real_T (*)[3])c22_inData)[c22_i44];
  }

  for (c22_i45 = 0; c22_i45 < 3; c22_i45++) {
    c22_u[c22_i45] = c22_b_inData[c22_i45];
  }

  c22_y = NULL;
  sf_mex_assign(&c22_y, sf_mex_create("y", c22_u, 0, 0U, 1U, 0U, 2, 3, 1), FALSE);
  sf_mex_assign(&c22_mxArrayOutData, c22_y, FALSE);
  return c22_mxArrayOutData;
}

static const mxArray *c22_d_sf_marshallOut(void *chartInstanceVoid, void
  *c22_inData)
{
  const mxArray *c22_mxArrayOutData = NULL;
  real_T c22_u;
  const mxArray *c22_y = NULL;
  SFc22_QRsimInstanceStruct *chartInstance;
  chartInstance = (SFc22_QRsimInstanceStruct *)chartInstanceVoid;
  c22_mxArrayOutData = NULL;
  c22_u = *(real_T *)c22_inData;
  c22_y = NULL;
  sf_mex_assign(&c22_y, sf_mex_create("y", &c22_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c22_mxArrayOutData, c22_y, FALSE);
  return c22_mxArrayOutData;
}

static real_T c22_e_emlrt_marshallIn(SFc22_QRsimInstanceStruct *chartInstance,
  const mxArray *c22_u, const emlrtMsgIdentifier *c22_parentId)
{
  real_T c22_y;
  real_T c22_d0;
  sf_mex_import(c22_parentId, sf_mex_dup(c22_u), &c22_d0, 1, 0, 0U, 0, 0U, 0);
  c22_y = c22_d0;
  sf_mex_destroy(&c22_u);
  return c22_y;
}

static void c22_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c22_mxArrayInData, const char_T *c22_varName, void *c22_outData)
{
  const mxArray *c22_nargout;
  const char_T *c22_identifier;
  emlrtMsgIdentifier c22_thisId;
  real_T c22_y;
  SFc22_QRsimInstanceStruct *chartInstance;
  chartInstance = (SFc22_QRsimInstanceStruct *)chartInstanceVoid;
  c22_nargout = sf_mex_dup(c22_mxArrayInData);
  c22_identifier = c22_varName;
  c22_thisId.fIdentifier = c22_identifier;
  c22_thisId.fParent = NULL;
  c22_y = c22_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c22_nargout),
    &c22_thisId);
  sf_mex_destroy(&c22_nargout);
  *(real_T *)c22_outData = c22_y;
  sf_mex_destroy(&c22_mxArrayInData);
}

const mxArray *sf_c22_QRsim_get_eml_resolved_functions_info(void)
{
  const mxArray *c22_nameCaptureInfo = NULL;
  c22_nameCaptureInfo = NULL;
  sf_mex_assign(&c22_nameCaptureInfo, sf_mex_createstruct("structure", 2, 30, 1),
                FALSE);
  c22_info_helper(&c22_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c22_nameCaptureInfo);
  return c22_nameCaptureInfo;
}

static void c22_info_helper(const mxArray **c22_info)
{
  const mxArray *c22_rhs0 = NULL;
  const mxArray *c22_lhs0 = NULL;
  const mxArray *c22_rhs1 = NULL;
  const mxArray *c22_lhs1 = NULL;
  const mxArray *c22_rhs2 = NULL;
  const mxArray *c22_lhs2 = NULL;
  const mxArray *c22_rhs3 = NULL;
  const mxArray *c22_lhs3 = NULL;
  const mxArray *c22_rhs4 = NULL;
  const mxArray *c22_lhs4 = NULL;
  const mxArray *c22_rhs5 = NULL;
  const mxArray *c22_lhs5 = NULL;
  const mxArray *c22_rhs6 = NULL;
  const mxArray *c22_lhs6 = NULL;
  const mxArray *c22_rhs7 = NULL;
  const mxArray *c22_lhs7 = NULL;
  const mxArray *c22_rhs8 = NULL;
  const mxArray *c22_lhs8 = NULL;
  const mxArray *c22_rhs9 = NULL;
  const mxArray *c22_lhs9 = NULL;
  const mxArray *c22_rhs10 = NULL;
  const mxArray *c22_lhs10 = NULL;
  const mxArray *c22_rhs11 = NULL;
  const mxArray *c22_lhs11 = NULL;
  const mxArray *c22_rhs12 = NULL;
  const mxArray *c22_lhs12 = NULL;
  const mxArray *c22_rhs13 = NULL;
  const mxArray *c22_lhs13 = NULL;
  const mxArray *c22_rhs14 = NULL;
  const mxArray *c22_lhs14 = NULL;
  const mxArray *c22_rhs15 = NULL;
  const mxArray *c22_lhs15 = NULL;
  const mxArray *c22_rhs16 = NULL;
  const mxArray *c22_lhs16 = NULL;
  const mxArray *c22_rhs17 = NULL;
  const mxArray *c22_lhs17 = NULL;
  const mxArray *c22_rhs18 = NULL;
  const mxArray *c22_lhs18 = NULL;
  const mxArray *c22_rhs19 = NULL;
  const mxArray *c22_lhs19 = NULL;
  const mxArray *c22_rhs20 = NULL;
  const mxArray *c22_lhs20 = NULL;
  const mxArray *c22_rhs21 = NULL;
  const mxArray *c22_lhs21 = NULL;
  const mxArray *c22_rhs22 = NULL;
  const mxArray *c22_lhs22 = NULL;
  const mxArray *c22_rhs23 = NULL;
  const mxArray *c22_lhs23 = NULL;
  const mxArray *c22_rhs24 = NULL;
  const mxArray *c22_lhs24 = NULL;
  const mxArray *c22_rhs25 = NULL;
  const mxArray *c22_lhs25 = NULL;
  const mxArray *c22_rhs26 = NULL;
  const mxArray *c22_lhs26 = NULL;
  const mxArray *c22_rhs27 = NULL;
  const mxArray *c22_lhs27 = NULL;
  const mxArray *c22_rhs28 = NULL;
  const mxArray *c22_lhs28 = NULL;
  const mxArray *c22_rhs29 = NULL;
  const mxArray *c22_lhs29 = NULL;
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut("cross"), "name", "name", 0);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/specfun/cross.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(1286818842U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c22_rhs0, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c22_lhs0, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/specfun/cross.m"), "context",
                  "context", 1);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut("mtimes"), "name", "name", 1);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "resolved",
                  "resolved", 1);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(1363713878U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c22_rhs1, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c22_lhs1, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m!common_checks"),
                  "context", "context", 2);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 2);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c22_rhs2, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c22_lhs2, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(""), "context", "context", 3);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut("norm"), "name", "name", 3);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m"), "resolved",
                  "resolved", 3);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(1363713868U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c22_rhs3, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c22_lhs3, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!genpnorm"),
                  "context", "context", 4);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 4);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(1323170578U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c22_rhs4, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c22_lhs4, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!genpnorm"),
                  "context", "context", 5);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 5);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c22_rhs5, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c22_lhs5, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!genpnorm"),
                  "context", "context", 6);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut("eml_xnrm2"), "name", "name",
                  6);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xnrm2.m"),
                  "resolved", "resolved", 6);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(1363713872U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c22_rhs6, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c22_lhs6, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_lhs6), "lhs", "lhs",
                  6);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xnrm2.m"), "context",
                  "context", 7);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut("eml_blas_inline"), "name",
                  "name", 7);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(1299076768U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c22_rhs7, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c22_lhs7, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_rhs7), "rhs", "rhs",
                  7);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_lhs7), "lhs", "lhs",
                  7);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xnrm2.m"),
                  "context", "context", 8);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 8);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(1323170578U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c22_rhs8, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c22_lhs8, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_rhs8), "rhs", "rhs",
                  8);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_lhs8), "lhs", "lhs",
                  8);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xnrm2.m"),
                  "context", "context", 9);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut("eml_refblas_xnrm2"), "name",
                  "name", 9);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(1299076784U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c22_rhs9, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c22_lhs9, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_rhs9), "rhs", "rhs",
                  9);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_lhs9), "lhs", "lhs",
                  9);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m"),
                  "context", "context", 10);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut("realmin"), "name", "name",
                  10);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m"), "resolved",
                  "resolved", 10);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(1307651242U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c22_rhs10, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c22_lhs10, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m"), "context",
                  "context", 11);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut("eml_realmin"), "name",
                  "name", 11);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmin.m"), "resolved",
                  "resolved", 11);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(1307651244U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c22_rhs11, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c22_lhs11, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmin.m"), "context",
                  "context", 12);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut("eml_float_model"), "name",
                  "name", 12);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m"),
                  "resolved", "resolved", 12);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(1326727996U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c22_rhs12, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c22_lhs12, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m"),
                  "context", "context", 13);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 13);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 13);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(1323170578U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c22_rhs13, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c22_lhs13, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m"),
                  "context", "context", 14);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut("eml_index_minus"), "name",
                  "name", 14);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m"),
                  "resolved", "resolved", 14);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(1286818778U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c22_rhs14, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c22_lhs14, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m"),
                  "context", "context", 15);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 15);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 15);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(1323170578U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c22_rhs15, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c22_lhs15, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m"),
                  "context", "context", 16);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut("eml_index_times"), "name",
                  "name", 16);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 16);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m"),
                  "resolved", "resolved", 16);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(1286818780U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c22_rhs16, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c22_lhs16, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m"),
                  "context", "context", 17);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 17);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 17);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(1323170578U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c22_rhs17, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c22_lhs17, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m"),
                  "context", "context", 18);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 18);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 18);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 18);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(1286818778U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c22_rhs18, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c22_lhs18, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"), "context",
                  "context", 19);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 19);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 19);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(1323170578U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c22_rhs19, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c22_lhs19, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_lhs19), "lhs", "lhs",
                  19);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m"),
                  "context", "context", 20);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 20);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 20);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 20);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(1346510340U), "fileTimeLo",
                  "fileTimeLo", 20);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 20);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 20);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 20);
  sf_mex_assign(&c22_rhs20, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c22_lhs20, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_rhs20), "rhs", "rhs",
                  20);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_lhs20), "lhs", "lhs",
                  20);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 21);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut("intmax"), "name", "name", 21);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 21);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 21);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(1362261882U), "fileTimeLo",
                  "fileTimeLo", 21);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 21);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 21);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 21);
  sf_mex_assign(&c22_rhs21, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c22_lhs21, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_rhs21), "rhs", "rhs",
                  21);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_lhs21), "lhs", "lhs",
                  21);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m"),
                  "context", "context", 22);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut("abs"), "name", "name", 22);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 22);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 22);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(1363713852U), "fileTimeLo",
                  "fileTimeLo", 22);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 22);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 22);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 22);
  sf_mex_assign(&c22_rhs22, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c22_lhs22, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_rhs22), "rhs", "rhs",
                  22);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_lhs22), "lhs", "lhs",
                  22);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 23);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 23);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 23);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 23);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
                  "fileTimeLo", 23);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 23);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 23);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 23);
  sf_mex_assign(&c22_rhs23, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c22_lhs23, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_rhs23), "rhs", "rhs",
                  23);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_lhs23), "lhs", "lhs",
                  23);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 24);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut("eml_scalar_abs"), "name",
                  "name", 24);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 24);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m"),
                  "resolved", "resolved", 24);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(1286818712U), "fileTimeLo",
                  "fileTimeLo", 24);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 24);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 24);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 24);
  sf_mex_assign(&c22_rhs24, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c22_lhs24, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_rhs24), "rhs", "rhs",
                  24);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_lhs24), "lhs", "lhs",
                  24);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(""), "context", "context", 25);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut("mrdivide"), "name", "name",
                  25);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 25);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 25);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(1373306508U), "fileTimeLo",
                  "fileTimeLo", 25);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 25);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(1319729966U), "mFileTimeLo",
                  "mFileTimeLo", 25);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 25);
  sf_mex_assign(&c22_rhs25, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c22_lhs25, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_rhs25), "rhs", "rhs",
                  25);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_lhs25), "lhs", "lhs",
                  25);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 26);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut("rdivide"), "name", "name",
                  26);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 26);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 26);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(1363713880U), "fileTimeLo",
                  "fileTimeLo", 26);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 26);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 26);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 26);
  sf_mex_assign(&c22_rhs26, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c22_lhs26, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_rhs26), "rhs", "rhs",
                  26);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_lhs26), "lhs", "lhs",
                  26);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 27);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 27);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 27);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 27);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
                  "fileTimeLo", 27);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 27);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 27);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 27);
  sf_mex_assign(&c22_rhs27, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c22_lhs27, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_rhs27), "rhs", "rhs",
                  27);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_lhs27), "lhs", "lhs",
                  27);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 28);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 28);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 28);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 28);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(1286818796U), "fileTimeLo",
                  "fileTimeLo", 28);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 28);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 28);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 28);
  sf_mex_assign(&c22_rhs28, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c22_lhs28, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_rhs28), "rhs", "rhs",
                  28);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_lhs28), "lhs", "lhs",
                  28);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 29);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut("eml_div"), "name", "name",
                  29);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 29);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 29);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(1363713866U), "fileTimeLo",
                  "fileTimeLo", 29);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 29);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 29);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 29);
  sf_mex_assign(&c22_rhs29, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c22_lhs29, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_rhs29), "rhs", "rhs",
                  29);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_lhs29), "lhs", "lhs",
                  29);
  sf_mex_destroy(&c22_rhs0);
  sf_mex_destroy(&c22_lhs0);
  sf_mex_destroy(&c22_rhs1);
  sf_mex_destroy(&c22_lhs1);
  sf_mex_destroy(&c22_rhs2);
  sf_mex_destroy(&c22_lhs2);
  sf_mex_destroy(&c22_rhs3);
  sf_mex_destroy(&c22_lhs3);
  sf_mex_destroy(&c22_rhs4);
  sf_mex_destroy(&c22_lhs4);
  sf_mex_destroy(&c22_rhs5);
  sf_mex_destroy(&c22_lhs5);
  sf_mex_destroy(&c22_rhs6);
  sf_mex_destroy(&c22_lhs6);
  sf_mex_destroy(&c22_rhs7);
  sf_mex_destroy(&c22_lhs7);
  sf_mex_destroy(&c22_rhs8);
  sf_mex_destroy(&c22_lhs8);
  sf_mex_destroy(&c22_rhs9);
  sf_mex_destroy(&c22_lhs9);
  sf_mex_destroy(&c22_rhs10);
  sf_mex_destroy(&c22_lhs10);
  sf_mex_destroy(&c22_rhs11);
  sf_mex_destroy(&c22_lhs11);
  sf_mex_destroy(&c22_rhs12);
  sf_mex_destroy(&c22_lhs12);
  sf_mex_destroy(&c22_rhs13);
  sf_mex_destroy(&c22_lhs13);
  sf_mex_destroy(&c22_rhs14);
  sf_mex_destroy(&c22_lhs14);
  sf_mex_destroy(&c22_rhs15);
  sf_mex_destroy(&c22_lhs15);
  sf_mex_destroy(&c22_rhs16);
  sf_mex_destroy(&c22_lhs16);
  sf_mex_destroy(&c22_rhs17);
  sf_mex_destroy(&c22_lhs17);
  sf_mex_destroy(&c22_rhs18);
  sf_mex_destroy(&c22_lhs18);
  sf_mex_destroy(&c22_rhs19);
  sf_mex_destroy(&c22_lhs19);
  sf_mex_destroy(&c22_rhs20);
  sf_mex_destroy(&c22_lhs20);
  sf_mex_destroy(&c22_rhs21);
  sf_mex_destroy(&c22_lhs21);
  sf_mex_destroy(&c22_rhs22);
  sf_mex_destroy(&c22_lhs22);
  sf_mex_destroy(&c22_rhs23);
  sf_mex_destroy(&c22_lhs23);
  sf_mex_destroy(&c22_rhs24);
  sf_mex_destroy(&c22_lhs24);
  sf_mex_destroy(&c22_rhs25);
  sf_mex_destroy(&c22_lhs25);
  sf_mex_destroy(&c22_rhs26);
  sf_mex_destroy(&c22_lhs26);
  sf_mex_destroy(&c22_rhs27);
  sf_mex_destroy(&c22_lhs27);
  sf_mex_destroy(&c22_rhs28);
  sf_mex_destroy(&c22_lhs28);
  sf_mex_destroy(&c22_rhs29);
  sf_mex_destroy(&c22_lhs29);
}

static const mxArray *c22_emlrt_marshallOut(char * c22_u)
{
  const mxArray *c22_y = NULL;
  c22_y = NULL;
  sf_mex_assign(&c22_y, sf_mex_create("y", c22_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c22_u)), FALSE);
  return c22_y;
}

static const mxArray *c22_b_emlrt_marshallOut(uint32_T c22_u)
{
  const mxArray *c22_y = NULL;
  c22_y = NULL;
  sf_mex_assign(&c22_y, sf_mex_create("y", &c22_u, 7, 0U, 0U, 0U, 0), FALSE);
  return c22_y;
}

static void c22_cross(SFc22_QRsimInstanceStruct *chartInstance, real_T c22_a[3],
                      real_T c22_b[3], real_T c22_c[3])
{
  real_T c22_b_a;
  real_T c22_b_b;
  real_T c22_y;
  real_T c22_c_a;
  real_T c22_c_b;
  real_T c22_b_y;
  real_T c22_c1;
  real_T c22_d_a;
  real_T c22_d_b;
  real_T c22_c_y;
  real_T c22_e_a;
  real_T c22_e_b;
  real_T c22_d_y;
  real_T c22_c2;
  real_T c22_f_a;
  real_T c22_f_b;
  real_T c22_e_y;
  real_T c22_g_a;
  real_T c22_g_b;
  real_T c22_f_y;
  real_T c22_c3;
  c22_b_a = c22_a[1];
  c22_b_b = c22_b[2];
  c22_y = c22_b_a * c22_b_b;
  c22_c_a = c22_a[2];
  c22_c_b = c22_b[1];
  c22_b_y = c22_c_a * c22_c_b;
  c22_c1 = c22_y - c22_b_y;
  c22_d_a = c22_a[2];
  c22_d_b = c22_b[0];
  c22_c_y = c22_d_a * c22_d_b;
  c22_e_a = c22_a[0];
  c22_e_b = c22_b[2];
  c22_d_y = c22_e_a * c22_e_b;
  c22_c2 = c22_c_y - c22_d_y;
  c22_f_a = c22_a[0];
  c22_f_b = c22_b[1];
  c22_e_y = c22_f_a * c22_f_b;
  c22_g_a = c22_a[1];
  c22_g_b = c22_b[0];
  c22_f_y = c22_g_a * c22_g_b;
  c22_c3 = c22_e_y - c22_f_y;
  c22_c[0] = c22_c1;
  c22_c[1] = c22_c2;
  c22_c[2] = c22_c3;
}

static const mxArray *c22_e_sf_marshallOut(void *chartInstanceVoid, void
  *c22_inData)
{
  const mxArray *c22_mxArrayOutData = NULL;
  int32_T c22_u;
  const mxArray *c22_y = NULL;
  SFc22_QRsimInstanceStruct *chartInstance;
  chartInstance = (SFc22_QRsimInstanceStruct *)chartInstanceVoid;
  c22_mxArrayOutData = NULL;
  c22_u = *(int32_T *)c22_inData;
  c22_y = NULL;
  sf_mex_assign(&c22_y, sf_mex_create("y", &c22_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c22_mxArrayOutData, c22_y, FALSE);
  return c22_mxArrayOutData;
}

static int32_T c22_f_emlrt_marshallIn(SFc22_QRsimInstanceStruct *chartInstance,
  const mxArray *c22_u, const emlrtMsgIdentifier *c22_parentId)
{
  int32_T c22_y;
  int32_T c22_i46;
  sf_mex_import(c22_parentId, sf_mex_dup(c22_u), &c22_i46, 1, 6, 0U, 0, 0U, 0);
  c22_y = c22_i46;
  sf_mex_destroy(&c22_u);
  return c22_y;
}

static void c22_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c22_mxArrayInData, const char_T *c22_varName, void *c22_outData)
{
  const mxArray *c22_b_sfEvent;
  const char_T *c22_identifier;
  emlrtMsgIdentifier c22_thisId;
  int32_T c22_y;
  SFc22_QRsimInstanceStruct *chartInstance;
  chartInstance = (SFc22_QRsimInstanceStruct *)chartInstanceVoid;
  c22_b_sfEvent = sf_mex_dup(c22_mxArrayInData);
  c22_identifier = c22_varName;
  c22_thisId.fIdentifier = c22_identifier;
  c22_thisId.fParent = NULL;
  c22_y = c22_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c22_b_sfEvent),
    &c22_thisId);
  sf_mex_destroy(&c22_b_sfEvent);
  *(int32_T *)c22_outData = c22_y;
  sf_mex_destroy(&c22_mxArrayInData);
}

static uint8_T c22_g_emlrt_marshallIn(SFc22_QRsimInstanceStruct *chartInstance,
  const mxArray *c22_b_is_active_c22_QRsim, const char_T *c22_identifier)
{
  uint8_T c22_y;
  emlrtMsgIdentifier c22_thisId;
  c22_thisId.fIdentifier = c22_identifier;
  c22_thisId.fParent = NULL;
  c22_y = c22_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c22_b_is_active_c22_QRsim), &c22_thisId);
  sf_mex_destroy(&c22_b_is_active_c22_QRsim);
  return c22_y;
}

static uint8_T c22_h_emlrt_marshallIn(SFc22_QRsimInstanceStruct *chartInstance,
  const mxArray *c22_u, const emlrtMsgIdentifier *c22_parentId)
{
  uint8_T c22_y;
  uint8_T c22_u0;
  sf_mex_import(c22_parentId, sf_mex_dup(c22_u), &c22_u0, 1, 3, 0U, 0, 0U, 0);
  c22_y = c22_u0;
  sf_mex_destroy(&c22_u);
  return c22_y;
}

static void init_dsm_address_info(SFc22_QRsimInstanceStruct *chartInstance)
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

void sf_c22_QRsim_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(901515992U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3103111389U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2568915097U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1374393204U);
}

mxArray *sf_c22_QRsim_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("umTfsP2JVkPamggh6ppIAB");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(1);
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
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(1);
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
      pr[1] = (double)(3);
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c22_QRsim_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c22_QRsim_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c22_QRsim(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x4'type','srcId','name','auxInfo'{{M[1],M[5],T\"Rc\",},{M[1],M[7],T\"b1c\",},{M[1],M[8],T\"b2c\",},{M[8],M[0],T\"is_active_c22_QRsim\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 4, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c22_QRsim_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc22_QRsimInstanceStruct *chartInstance;
    chartInstance = (SFc22_QRsimInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _QRsimMachineNumber_,
           22,
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
          _SFD_SET_DATA_PROPS(0,2,0,1,"b1c");
          _SFD_SET_DATA_PROPS(1,2,0,1,"b2c");
          _SFD_SET_DATA_PROPS(2,1,1,0,"b1d");
          _SFD_SET_DATA_PROPS(3,2,0,1,"Rc");
          _SFD_SET_DATA_PROPS(4,1,1,0,"b3c");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,183);

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c22_b_sf_marshallOut,(MexInFcnForType)
            c22_b_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c22_b_sf_marshallOut,(MexInFcnForType)
            c22_b_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 3;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c22_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 3;
          dimVector[1]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c22_sf_marshallOut,(MexInFcnForType)
            c22_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 3;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c22_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          real_T (*c22_b1c)[3];
          real_T (*c22_b2c)[3];
          real_T (*c22_b1d)[3];
          real_T (*c22_Rc)[9];
          real_T (*c22_b3c)[3];
          c22_b3c = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 1);
          c22_Rc = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 3);
          c22_b1d = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
          c22_b2c = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
          c22_b1c = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, *c22_b1c);
          _SFD_SET_DATA_VALUE_PTR(1U, *c22_b2c);
          _SFD_SET_DATA_VALUE_PTR(2U, *c22_b1d);
          _SFD_SET_DATA_VALUE_PTR(3U, *c22_Rc);
          _SFD_SET_DATA_VALUE_PTR(4U, *c22_b3c);
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
  return "daXPARzSBKqy9WBAGSnxV";
}

static void sf_opaque_initialize_c22_QRsim(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc22_QRsimInstanceStruct*) chartInstanceVar)->S,
    0);
  initialize_params_c22_QRsim((SFc22_QRsimInstanceStruct*) chartInstanceVar);
  initialize_c22_QRsim((SFc22_QRsimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c22_QRsim(void *chartInstanceVar)
{
  enable_c22_QRsim((SFc22_QRsimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c22_QRsim(void *chartInstanceVar)
{
  disable_c22_QRsim((SFc22_QRsimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c22_QRsim(void *chartInstanceVar)
{
  sf_c22_QRsim((SFc22_QRsimInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c22_QRsim(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c22_QRsim((SFc22_QRsimInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c22_QRsim();/* state var info */
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

extern void sf_internal_set_sim_state_c22_QRsim(SimStruct* S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c22_QRsim();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c22_QRsim((SFc22_QRsimInstanceStruct*)chartInfo->chartInstance,
    mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c22_QRsim(SimStruct* S)
{
  return sf_internal_get_sim_state_c22_QRsim(S);
}

static void sf_opaque_set_sim_state_c22_QRsim(SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c22_QRsim(S, st);
}

static void sf_opaque_terminate_c22_QRsim(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc22_QRsimInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_QRsim_optimization_info();
    }

    finalize_c22_QRsim((SFc22_QRsimInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc22_QRsim((SFc22_QRsimInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c22_QRsim(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c22_QRsim((SFc22_QRsimInstanceStruct*)(((ChartInfoStruct *)
      ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c22_QRsim(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_QRsim_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      22);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,22,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,22,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,22);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,22,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,22,3);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=3; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 2; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,22);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1654719549U));
  ssSetChecksum1(S,(478175356U));
  ssSetChecksum2(S,(645898560U));
  ssSetChecksum3(S,(363407361U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c22_QRsim(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c22_QRsim(SimStruct *S)
{
  SFc22_QRsimInstanceStruct *chartInstance;
  chartInstance = (SFc22_QRsimInstanceStruct *)utMalloc(sizeof
    (SFc22_QRsimInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc22_QRsimInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c22_QRsim;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c22_QRsim;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c22_QRsim;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c22_QRsim;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c22_QRsim;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c22_QRsim;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c22_QRsim;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c22_QRsim;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c22_QRsim;
  chartInstance->chartInfo.mdlStart = mdlStart_c22_QRsim;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c22_QRsim;
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

void c22_QRsim_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c22_QRsim(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c22_QRsim(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c22_QRsim(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c22_QRsim_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
