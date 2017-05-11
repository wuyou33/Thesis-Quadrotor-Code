/* Include files */

#include <stddef.h>
#include "blas.h"
#include "QRLsim_sfun.h"
#include "c13_QRLsim.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "QRLsim_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c13_debug_family_names[7] = { "a", "b", "c", "nargin",
  "nargout", "A", "fcnhat" };

/* Function Declarations */
static void initialize_c13_QRLsim(SFc13_QRLsimInstanceStruct *chartInstance);
static void initialize_params_c13_QRLsim(SFc13_QRLsimInstanceStruct
  *chartInstance);
static void enable_c13_QRLsim(SFc13_QRLsimInstanceStruct *chartInstance);
static void disable_c13_QRLsim(SFc13_QRLsimInstanceStruct *chartInstance);
static void c13_update_debugger_state_c13_QRLsim(SFc13_QRLsimInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c13_QRLsim(SFc13_QRLsimInstanceStruct
  *chartInstance);
static void set_sim_state_c13_QRLsim(SFc13_QRLsimInstanceStruct *chartInstance,
  const mxArray *c13_st);
static void finalize_c13_QRLsim(SFc13_QRLsimInstanceStruct *chartInstance);
static void sf_c13_QRLsim(SFc13_QRLsimInstanceStruct *chartInstance);
static void initSimStructsc13_QRLsim(SFc13_QRLsimInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c13_machineNumber, uint32_T
  c13_chartNumber);
static const mxArray *c13_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData);
static void c13_emlrt_marshallIn(SFc13_QRLsimInstanceStruct *chartInstance,
  const mxArray *c13_fcnhat, const char_T *c13_identifier, real_T c13_y[9]);
static void c13_b_emlrt_marshallIn(SFc13_QRLsimInstanceStruct *chartInstance,
  const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId, real_T c13_y[9]);
static void c13_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData);
static const mxArray *c13_b_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData);
static const mxArray *c13_c_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData);
static real_T c13_c_emlrt_marshallIn(SFc13_QRLsimInstanceStruct *chartInstance,
  const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId);
static void c13_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData);
static const mxArray *c13_d_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData);
static int32_T c13_d_emlrt_marshallIn(SFc13_QRLsimInstanceStruct *chartInstance,
  const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId);
static void c13_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData);
static uint8_T c13_e_emlrt_marshallIn(SFc13_QRLsimInstanceStruct *chartInstance,
  const mxArray *c13_b_is_active_c13_QRLsim, const char_T *c13_identifier);
static uint8_T c13_f_emlrt_marshallIn(SFc13_QRLsimInstanceStruct *chartInstance,
  const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId);
static void init_dsm_address_info(SFc13_QRLsimInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c13_QRLsim(SFc13_QRLsimInstanceStruct *chartInstance)
{
  chartInstance->c13_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c13_is_active_c13_QRLsim = 0U;
}

static void initialize_params_c13_QRLsim(SFc13_QRLsimInstanceStruct
  *chartInstance)
{
}

static void enable_c13_QRLsim(SFc13_QRLsimInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c13_QRLsim(SFc13_QRLsimInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c13_update_debugger_state_c13_QRLsim(SFc13_QRLsimInstanceStruct
  *chartInstance)
{
}

static const mxArray *get_sim_state_c13_QRLsim(SFc13_QRLsimInstanceStruct
  *chartInstance)
{
  const mxArray *c13_st;
  const mxArray *c13_y = NULL;
  int32_T c13_i0;
  real_T c13_u[9];
  const mxArray *c13_b_y = NULL;
  uint8_T c13_hoistedGlobal;
  uint8_T c13_b_u;
  const mxArray *c13_c_y = NULL;
  real_T (*c13_fcnhat)[9];
  c13_fcnhat = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  c13_st = NULL;
  c13_st = NULL;
  c13_y = NULL;
  sf_mex_assign(&c13_y, sf_mex_createcellarray(2), FALSE);
  for (c13_i0 = 0; c13_i0 < 9; c13_i0++) {
    c13_u[c13_i0] = (*c13_fcnhat)[c13_i0];
  }

  c13_b_y = NULL;
  sf_mex_assign(&c13_b_y, sf_mex_create("y", c13_u, 0, 0U, 1U, 0U, 2, 3, 3),
                FALSE);
  sf_mex_setcell(c13_y, 0, c13_b_y);
  c13_hoistedGlobal = chartInstance->c13_is_active_c13_QRLsim;
  c13_b_u = c13_hoistedGlobal;
  c13_c_y = NULL;
  sf_mex_assign(&c13_c_y, sf_mex_create("y", &c13_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c13_y, 1, c13_c_y);
  sf_mex_assign(&c13_st, c13_y, FALSE);
  return c13_st;
}

static void set_sim_state_c13_QRLsim(SFc13_QRLsimInstanceStruct *chartInstance,
  const mxArray *c13_st)
{
  const mxArray *c13_u;
  real_T c13_dv0[9];
  int32_T c13_i1;
  real_T (*c13_fcnhat)[9];
  c13_fcnhat = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c13_doneDoubleBufferReInit = TRUE;
  c13_u = sf_mex_dup(c13_st);
  c13_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c13_u, 0)),
                       "fcnhat", c13_dv0);
  for (c13_i1 = 0; c13_i1 < 9; c13_i1++) {
    (*c13_fcnhat)[c13_i1] = c13_dv0[c13_i1];
  }

  chartInstance->c13_is_active_c13_QRLsim = c13_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c13_u, 1)), "is_active_c13_QRLsim");
  sf_mex_destroy(&c13_u);
  c13_update_debugger_state_c13_QRLsim(chartInstance);
  sf_mex_destroy(&c13_st);
}

static void finalize_c13_QRLsim(SFc13_QRLsimInstanceStruct *chartInstance)
{
}

static void sf_c13_QRLsim(SFc13_QRLsimInstanceStruct *chartInstance)
{
  int32_T c13_i2;
  int32_T c13_i3;
  int32_T c13_i4;
  real_T c13_A[3];
  uint32_T c13_debug_family_var_map[7];
  real_T c13_a;
  real_T c13_b;
  real_T c13_c;
  real_T c13_nargin = 1.0;
  real_T c13_nargout = 1.0;
  real_T c13_fcnhat[9];
  int32_T c13_i5;
  real_T (*c13_b_fcnhat)[9];
  real_T (*c13_b_A)[3];
  c13_b_fcnhat = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  c13_b_A = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 2U, chartInstance->c13_sfEvent);
  for (c13_i2 = 0; c13_i2 < 3; c13_i2++) {
    _SFD_DATA_RANGE_CHECK((*c13_b_A)[c13_i2], 0U);
  }

  for (c13_i3 = 0; c13_i3 < 9; c13_i3++) {
    _SFD_DATA_RANGE_CHECK((*c13_b_fcnhat)[c13_i3], 1U);
  }

  chartInstance->c13_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 2U, chartInstance->c13_sfEvent);
  for (c13_i4 = 0; c13_i4 < 3; c13_i4++) {
    c13_A[c13_i4] = (*c13_b_A)[c13_i4];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 7U, 7U, c13_debug_family_names,
    c13_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_a, 0U, c13_c_sf_marshallOut,
    c13_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_b, 1U, c13_c_sf_marshallOut,
    c13_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_c, 2U, c13_c_sf_marshallOut,
    c13_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_nargin, 3U, c13_c_sf_marshallOut,
    c13_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_nargout, 4U, c13_c_sf_marshallOut,
    c13_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c13_A, 5U, c13_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c13_fcnhat, 6U, c13_sf_marshallOut,
    c13_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 3);
  c13_a = c13_A[0];
  _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 4);
  c13_b = c13_A[1];
  _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 5);
  c13_c = c13_A[2];
  _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 6);
  c13_fcnhat[0] = 0.0;
  c13_fcnhat[3] = -c13_c;
  c13_fcnhat[6] = c13_b;
  c13_fcnhat[1] = c13_c;
  c13_fcnhat[4] = 0.0;
  c13_fcnhat[7] = -c13_a;
  c13_fcnhat[2] = -c13_b;
  c13_fcnhat[5] = c13_a;
  c13_fcnhat[8] = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, -6);
  _SFD_SYMBOL_SCOPE_POP();
  for (c13_i5 = 0; c13_i5 < 9; c13_i5++) {
    (*c13_b_fcnhat)[c13_i5] = c13_fcnhat[c13_i5];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c13_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_QRLsimMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc13_QRLsim(SFc13_QRLsimInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c13_machineNumber, uint32_T
  c13_chartNumber)
{
}

static const mxArray *c13_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData)
{
  const mxArray *c13_mxArrayOutData = NULL;
  int32_T c13_i6;
  int32_T c13_i7;
  int32_T c13_i8;
  real_T c13_b_inData[9];
  int32_T c13_i9;
  int32_T c13_i10;
  int32_T c13_i11;
  real_T c13_u[9];
  const mxArray *c13_y = NULL;
  SFc13_QRLsimInstanceStruct *chartInstance;
  chartInstance = (SFc13_QRLsimInstanceStruct *)chartInstanceVoid;
  c13_mxArrayOutData = NULL;
  c13_i6 = 0;
  for (c13_i7 = 0; c13_i7 < 3; c13_i7++) {
    for (c13_i8 = 0; c13_i8 < 3; c13_i8++) {
      c13_b_inData[c13_i8 + c13_i6] = (*(real_T (*)[9])c13_inData)[c13_i8 +
        c13_i6];
    }

    c13_i6 += 3;
  }

  c13_i9 = 0;
  for (c13_i10 = 0; c13_i10 < 3; c13_i10++) {
    for (c13_i11 = 0; c13_i11 < 3; c13_i11++) {
      c13_u[c13_i11 + c13_i9] = c13_b_inData[c13_i11 + c13_i9];
    }

    c13_i9 += 3;
  }

  c13_y = NULL;
  sf_mex_assign(&c13_y, sf_mex_create("y", c13_u, 0, 0U, 1U, 0U, 2, 3, 3), FALSE);
  sf_mex_assign(&c13_mxArrayOutData, c13_y, FALSE);
  return c13_mxArrayOutData;
}

static void c13_emlrt_marshallIn(SFc13_QRLsimInstanceStruct *chartInstance,
  const mxArray *c13_fcnhat, const char_T *c13_identifier, real_T c13_y[9])
{
  emlrtMsgIdentifier c13_thisId;
  c13_thisId.fIdentifier = c13_identifier;
  c13_thisId.fParent = NULL;
  c13_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c13_fcnhat), &c13_thisId,
    c13_y);
  sf_mex_destroy(&c13_fcnhat);
}

static void c13_b_emlrt_marshallIn(SFc13_QRLsimInstanceStruct *chartInstance,
  const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId, real_T c13_y[9])
{
  real_T c13_dv1[9];
  int32_T c13_i12;
  sf_mex_import(c13_parentId, sf_mex_dup(c13_u), c13_dv1, 1, 0, 0U, 1, 0U, 2, 3,
                3);
  for (c13_i12 = 0; c13_i12 < 9; c13_i12++) {
    c13_y[c13_i12] = c13_dv1[c13_i12];
  }

  sf_mex_destroy(&c13_u);
}

static void c13_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData)
{
  const mxArray *c13_fcnhat;
  const char_T *c13_identifier;
  emlrtMsgIdentifier c13_thisId;
  real_T c13_y[9];
  int32_T c13_i13;
  int32_T c13_i14;
  int32_T c13_i15;
  SFc13_QRLsimInstanceStruct *chartInstance;
  chartInstance = (SFc13_QRLsimInstanceStruct *)chartInstanceVoid;
  c13_fcnhat = sf_mex_dup(c13_mxArrayInData);
  c13_identifier = c13_varName;
  c13_thisId.fIdentifier = c13_identifier;
  c13_thisId.fParent = NULL;
  c13_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c13_fcnhat), &c13_thisId,
    c13_y);
  sf_mex_destroy(&c13_fcnhat);
  c13_i13 = 0;
  for (c13_i14 = 0; c13_i14 < 3; c13_i14++) {
    for (c13_i15 = 0; c13_i15 < 3; c13_i15++) {
      (*(real_T (*)[9])c13_outData)[c13_i15 + c13_i13] = c13_y[c13_i15 + c13_i13];
    }

    c13_i13 += 3;
  }

  sf_mex_destroy(&c13_mxArrayInData);
}

static const mxArray *c13_b_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData)
{
  const mxArray *c13_mxArrayOutData = NULL;
  int32_T c13_i16;
  real_T c13_b_inData[3];
  int32_T c13_i17;
  real_T c13_u[3];
  const mxArray *c13_y = NULL;
  SFc13_QRLsimInstanceStruct *chartInstance;
  chartInstance = (SFc13_QRLsimInstanceStruct *)chartInstanceVoid;
  c13_mxArrayOutData = NULL;
  for (c13_i16 = 0; c13_i16 < 3; c13_i16++) {
    c13_b_inData[c13_i16] = (*(real_T (*)[3])c13_inData)[c13_i16];
  }

  for (c13_i17 = 0; c13_i17 < 3; c13_i17++) {
    c13_u[c13_i17] = c13_b_inData[c13_i17];
  }

  c13_y = NULL;
  sf_mex_assign(&c13_y, sf_mex_create("y", c13_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_assign(&c13_mxArrayOutData, c13_y, FALSE);
  return c13_mxArrayOutData;
}

static const mxArray *c13_c_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData)
{
  const mxArray *c13_mxArrayOutData = NULL;
  real_T c13_u;
  const mxArray *c13_y = NULL;
  SFc13_QRLsimInstanceStruct *chartInstance;
  chartInstance = (SFc13_QRLsimInstanceStruct *)chartInstanceVoid;
  c13_mxArrayOutData = NULL;
  c13_u = *(real_T *)c13_inData;
  c13_y = NULL;
  sf_mex_assign(&c13_y, sf_mex_create("y", &c13_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c13_mxArrayOutData, c13_y, FALSE);
  return c13_mxArrayOutData;
}

static real_T c13_c_emlrt_marshallIn(SFc13_QRLsimInstanceStruct *chartInstance,
  const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId)
{
  real_T c13_y;
  real_T c13_d0;
  sf_mex_import(c13_parentId, sf_mex_dup(c13_u), &c13_d0, 1, 0, 0U, 0, 0U, 0);
  c13_y = c13_d0;
  sf_mex_destroy(&c13_u);
  return c13_y;
}

static void c13_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData)
{
  const mxArray *c13_nargout;
  const char_T *c13_identifier;
  emlrtMsgIdentifier c13_thisId;
  real_T c13_y;
  SFc13_QRLsimInstanceStruct *chartInstance;
  chartInstance = (SFc13_QRLsimInstanceStruct *)chartInstanceVoid;
  c13_nargout = sf_mex_dup(c13_mxArrayInData);
  c13_identifier = c13_varName;
  c13_thisId.fIdentifier = c13_identifier;
  c13_thisId.fParent = NULL;
  c13_y = c13_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c13_nargout),
    &c13_thisId);
  sf_mex_destroy(&c13_nargout);
  *(real_T *)c13_outData = c13_y;
  sf_mex_destroy(&c13_mxArrayInData);
}

const mxArray *sf_c13_QRLsim_get_eml_resolved_functions_info(void)
{
  const mxArray *c13_nameCaptureInfo = NULL;
  c13_nameCaptureInfo = NULL;
  sf_mex_assign(&c13_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), FALSE);
  return c13_nameCaptureInfo;
}

static const mxArray *c13_d_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData)
{
  const mxArray *c13_mxArrayOutData = NULL;
  int32_T c13_u;
  const mxArray *c13_y = NULL;
  SFc13_QRLsimInstanceStruct *chartInstance;
  chartInstance = (SFc13_QRLsimInstanceStruct *)chartInstanceVoid;
  c13_mxArrayOutData = NULL;
  c13_u = *(int32_T *)c13_inData;
  c13_y = NULL;
  sf_mex_assign(&c13_y, sf_mex_create("y", &c13_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c13_mxArrayOutData, c13_y, FALSE);
  return c13_mxArrayOutData;
}

static int32_T c13_d_emlrt_marshallIn(SFc13_QRLsimInstanceStruct *chartInstance,
  const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId)
{
  int32_T c13_y;
  int32_T c13_i18;
  sf_mex_import(c13_parentId, sf_mex_dup(c13_u), &c13_i18, 1, 6, 0U, 0, 0U, 0);
  c13_y = c13_i18;
  sf_mex_destroy(&c13_u);
  return c13_y;
}

static void c13_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData)
{
  const mxArray *c13_b_sfEvent;
  const char_T *c13_identifier;
  emlrtMsgIdentifier c13_thisId;
  int32_T c13_y;
  SFc13_QRLsimInstanceStruct *chartInstance;
  chartInstance = (SFc13_QRLsimInstanceStruct *)chartInstanceVoid;
  c13_b_sfEvent = sf_mex_dup(c13_mxArrayInData);
  c13_identifier = c13_varName;
  c13_thisId.fIdentifier = c13_identifier;
  c13_thisId.fParent = NULL;
  c13_y = c13_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c13_b_sfEvent),
    &c13_thisId);
  sf_mex_destroy(&c13_b_sfEvent);
  *(int32_T *)c13_outData = c13_y;
  sf_mex_destroy(&c13_mxArrayInData);
}

static uint8_T c13_e_emlrt_marshallIn(SFc13_QRLsimInstanceStruct *chartInstance,
  const mxArray *c13_b_is_active_c13_QRLsim, const char_T *c13_identifier)
{
  uint8_T c13_y;
  emlrtMsgIdentifier c13_thisId;
  c13_thisId.fIdentifier = c13_identifier;
  c13_thisId.fParent = NULL;
  c13_y = c13_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c13_b_is_active_c13_QRLsim), &c13_thisId);
  sf_mex_destroy(&c13_b_is_active_c13_QRLsim);
  return c13_y;
}

static uint8_T c13_f_emlrt_marshallIn(SFc13_QRLsimInstanceStruct *chartInstance,
  const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId)
{
  uint8_T c13_y;
  uint8_T c13_u0;
  sf_mex_import(c13_parentId, sf_mex_dup(c13_u), &c13_u0, 1, 3, 0U, 0, 0U, 0);
  c13_y = c13_u0;
  sf_mex_destroy(&c13_u);
  return c13_y;
}

static void init_dsm_address_info(SFc13_QRLsimInstanceStruct *chartInstance)
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

void sf_c13_QRLsim_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3807765864U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1174610868U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2994303691U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1289166042U);
}

mxArray *sf_c13_QRLsim_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("KJW0a06Qzm6uXFKwTBut6");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c13_QRLsim_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c13_QRLsim_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c13_QRLsim(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"fcnhat\",},{M[8],M[0],T\"is_active_c13_QRLsim\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c13_QRLsim_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc13_QRLsimInstanceStruct *chartInstance;
    chartInstance = (SFc13_QRLsimInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _QRLsimMachineNumber_,
           13,
           1,
           1,
           2,
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
          init_script_number_translation(_QRLsimMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_QRLsimMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _QRLsimMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"A");
          _SFD_SET_DATA_PROPS(1,2,0,1,"fcnhat");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,112);

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c13_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 3;
          dimVector[1]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c13_sf_marshallOut,(MexInFcnForType)
            c13_sf_marshallIn);
        }

        {
          real_T (*c13_A)[3];
          real_T (*c13_fcnhat)[9];
          c13_fcnhat = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
          c13_A = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c13_A);
          _SFD_SET_DATA_VALUE_PTR(1U, *c13_fcnhat);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _QRLsimMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "P5D4fG9U0m1Ji5BX3Zagy";
}

static void sf_opaque_initialize_c13_QRLsim(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc13_QRLsimInstanceStruct*) chartInstanceVar)->S,
    0);
  initialize_params_c13_QRLsim((SFc13_QRLsimInstanceStruct*) chartInstanceVar);
  initialize_c13_QRLsim((SFc13_QRLsimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c13_QRLsim(void *chartInstanceVar)
{
  enable_c13_QRLsim((SFc13_QRLsimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c13_QRLsim(void *chartInstanceVar)
{
  disable_c13_QRLsim((SFc13_QRLsimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c13_QRLsim(void *chartInstanceVar)
{
  sf_c13_QRLsim((SFc13_QRLsimInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c13_QRLsim(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c13_QRLsim((SFc13_QRLsimInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c13_QRLsim();/* state var info */
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

extern void sf_internal_set_sim_state_c13_QRLsim(SimStruct* S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c13_QRLsim();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c13_QRLsim((SFc13_QRLsimInstanceStruct*)chartInfo->chartInstance,
    mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c13_QRLsim(SimStruct* S)
{
  return sf_internal_get_sim_state_c13_QRLsim(S);
}

static void sf_opaque_set_sim_state_c13_QRLsim(SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c13_QRLsim(S, st);
}

static void sf_opaque_terminate_c13_QRLsim(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc13_QRLsimInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_QRLsim_optimization_info();
    }

    finalize_c13_QRLsim((SFc13_QRLsimInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc13_QRLsim((SFc13_QRLsimInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c13_QRLsim(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c13_QRLsim((SFc13_QRLsimInstanceStruct*)(((ChartInfoStruct
      *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c13_QRLsim(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_QRLsim_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      13);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,13,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,13,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,13);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,13,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,13,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 1; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,13);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3132994832U));
  ssSetChecksum1(S,(2059985210U));
  ssSetChecksum2(S,(1358826366U));
  ssSetChecksum3(S,(2247393333U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c13_QRLsim(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c13_QRLsim(SimStruct *S)
{
  SFc13_QRLsimInstanceStruct *chartInstance;
  chartInstance = (SFc13_QRLsimInstanceStruct *)utMalloc(sizeof
    (SFc13_QRLsimInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc13_QRLsimInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c13_QRLsim;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c13_QRLsim;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c13_QRLsim;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c13_QRLsim;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c13_QRLsim;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c13_QRLsim;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c13_QRLsim;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c13_QRLsim;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c13_QRLsim;
  chartInstance->chartInfo.mdlStart = mdlStart_c13_QRLsim;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c13_QRLsim;
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

void c13_QRLsim_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c13_QRLsim(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c13_QRLsim(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c13_QRLsim(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c13_QRLsim_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
