#include "BenderVersio_2dinsp.h"

namespace BenderVersio_2dinsp {

/*******************************************************************************************************************
Cycling '74 License for Max-Generated Code for Export
Copyright (c) 2016 Cycling '74
The code that Max generates automatically and that end users are capable of exporting and using, and any
  associated documentation files (the “Software”) is a work of authorship for which Cycling '74 is the author
  and owner for copyright purposes.  A license is hereby granted, free of charge, to any person obtaining a
  copy of the Software (“Licensee”) to use, copy, modify, merge, publish, and distribute copies of the Software,
  and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
The Software is licensed to Licensee only for non-commercial use. Users who wish to make commercial use of the
  Software must contact the copyright owner to determine if a license for commercial use is available, and the
  terms and conditions for same, which may include fees or royalties. For commercial use, please send inquiries
  to licensing (at) cycling74.com.  The determination of whether a use is commercial use or non-commercial use is based
  upon the use, not the user. The Software may be used by individuals, institutions, governments, corporations, or
  other business whether for-profit or non-profit so long as the use itself is not a commercialization of the
  materials or a use that generates or is intended to generate income, revenue, sales or profit.
The above copyright notice and this license shall be included in all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO
  THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. IN NO EVENT SHALL
  THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
  CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
  DEALINGS IN THE SOFTWARE.
*******************************************************************************************************************/

// global noise generator
Noise noise;
static const int GENLIB_LOOPCOUNT_BAIL = 100000;


// The State struct contains all the state and procedures for the gendsp kernel
typedef struct State {
	CommonState __commonstate;
	Data m_pitchloop_11;
	Phasor __m_phasor_26;
	int __exception;
	int vectorsize;
	t_sample m_ctrl_15;
	t_sample m_ctrl_14;
	t_sample m_ctrl_13;
	t_sample m_ctrl_12;
	t_sample m_ctrl_16;
	t_sample m_ctrl_18;
	t_sample m_button_17;
	t_sample __m_carry_21;
	t_sample __m_count_19;
	t_sample samplerate;
	t_sample m_history_1;
	t_sample m_sw_9;
	t_sample m_history_4;
	t_sample m_history_3;
	t_sample m_history_2;
	t_sample samples_to_seconds;
	t_sample m_history_5;
	t_sample m_sw_7;
	t_sample m_history_6;
	t_sample m_gate_8;
	t_sample m_ctrl_10;
	// re-initialize all member variables;
	inline void reset(t_param __sr, int __vs) {
		__exception = 0;
		vectorsize = __vs;
		samplerate = __sr;
		m_history_1 = ((int)0);
		m_history_2 = ((int)0);
		m_history_3 = ((int)0);
		m_history_4 = ((int)0);
		m_history_5 = ((int)0);
		m_history_6 = ((int)0);
		m_sw_7 = ((int)0);
		m_gate_8 = ((int)0);
		m_sw_9 = ((int)0);
		m_ctrl_10 = ((int)0);
		m_pitchloop_11.reset("pitchloop", ((int)48000), ((int)2));
		m_ctrl_12 = ((int)0);
		m_ctrl_13 = ((int)0);
		m_ctrl_14 = ((int)0);
		m_ctrl_15 = ((int)0);
		m_ctrl_16 = ((int)0);
		m_button_17 = ((int)0);
		m_ctrl_18 = ((int)0);
		__m_count_19 = 0;
		__m_carry_21 = 0;
		samples_to_seconds = (1 / samplerate);
		__m_phasor_26.reset(0);
		genlib_reset_complete(this);
		
	};
	// the signal processing routine;
	inline int perform(t_sample ** __ins, t_sample ** __outs, int __n) {
		vectorsize = __n;
		const t_sample * __in1 = __ins[0];
		const t_sample * __in2 = __ins[1];
		t_sample * __out1 = __outs[0];
		t_sample * __out2 = __outs[1];
		t_sample * __out3 = __outs[2];
		t_sample * __out4 = __outs[3];
		t_sample * __out5 = __outs[4];
		t_sample * __out6 = __outs[5];
		t_sample * __out7 = __outs[6];
		t_sample * __out8 = __outs[7];
		t_sample * __out9 = __outs[8];
		if (__exception) {
			return __exception;
			
		} else if (( (__in1 == 0) || (__in2 == 0) || (__out1 == 0) || (__out2 == 0) || (__out3 == 0) || (__out4 == 0) || (__out5 == 0) || (__out6 == 0) || (__out7 == 0) || (__out8 == 0) || (__out9 == 0) )) {
			__exception = GENLIB_ERR_NULL_BUFFER;
			return __exception;
			
		};
		int pitchloop_dim = m_pitchloop_11.dim;
		int pitchloop_channels = m_pitchloop_11.channels;
		int pitchloop_dim_4304 = pitchloop_dim;
		bool chan_ignore_23 = ((((int)1) < 0) || (((int)1) >= pitchloop_channels));
		samples_to_seconds = (1 / samplerate);
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			const t_sample in2 = (*(__in2++));
			t_sample out4 = ((int)0);
			t_sample out6 = ((int)0);
			t_sample out2 = ((int)0);
			t_sample out5 = ((int)0);
			t_sample out3 = ((int)0);
			t_sample out7 = ((int)0);
			t_sample out9 = ((int)0);
			__m_count_19 = (((int)0) ? 0 : (fixdenorm(__m_count_19 + ((int)1))));
			int carry_20 = 0;
			if ((((int)0) != 0)) {
				__m_count_19 = 0;
				__m_carry_21 = 0;
				
			} else if (((pitchloop_dim_4304 > 0) && (__m_count_19 >= pitchloop_dim_4304))) {
				int wraps_22 = (__m_count_19 / pitchloop_dim_4304);
				__m_carry_21 = (__m_carry_21 + wraps_22);
				__m_count_19 = (__m_count_19 - (wraps_22 * pitchloop_dim_4304));
				carry_20 = 1;
				
			};
			int counter_3197 = __m_count_19;
			int counter_3198 = carry_20;
			int counter_3199 = __m_carry_21;
			int index_wrap_24 = ((counter_3197 < 0) ? ((pitchloop_dim - 1) + ((counter_3197 + 1) % pitchloop_dim)) : (counter_3197 % pitchloop_dim));
			if ((!chan_ignore_23)) {
				m_pitchloop_11.write(in2, index_wrap_24, ((int)1));
				
			};
			int index_wrap_25 = ((counter_3197 < 0) ? ((pitchloop_dim - 1) + ((counter_3197 + 1) % pitchloop_dim)) : (counter_3197 % pitchloop_dim));
			m_pitchloop_11.write(in1, index_wrap_25, 0);
			t_sample mix_4443 = (m_history_6 + (((t_sample)0.0019634941468452) * (m_ctrl_18 - m_history_6)));
			t_sample mix_1947 = mix_4443;
			t_sample mix_4444 = (m_history_5 + (((t_sample)0.0019634941468452) * (mix_1947 - m_history_5)));
			t_sample mix_1945 = mix_4444;
			t_sample mix_4445 = (m_history_4 + (((t_sample)0.0019634941468452) * (mix_1945 - m_history_4)));
			t_sample mix_1943 = mix_4445;
			t_sample gen_1959 = mix_1943;
			t_sample history_1948_next_1950 = fixdenorm(mix_1947);
			t_sample history_1946_next_1951 = fixdenorm(mix_1945);
			t_sample history_1944_next_1952 = fixdenorm(mix_1943);
			t_sample mix_4446 = (m_history_3 + (((t_sample)0.0019634941468452) * (m_ctrl_10 - m_history_3)));
			t_sample mix_4418 = mix_4446;
			t_sample mix_4447 = (m_history_2 + (((t_sample)0.0019634941468452) * (mix_4418 - m_history_2)));
			t_sample mix_4424 = mix_4447;
			t_sample mix_4448 = (m_history_1 + (((t_sample)0.0019634941468452) * (mix_4424 - m_history_1)));
			t_sample mix_4421 = mix_4448;
			t_sample gen_1958 = mix_4421;
			t_sample history_1948_next_4423 = fixdenorm(mix_4418);
			t_sample history_1946_next_4419 = fixdenorm(mix_4424);
			t_sample history_1944_next_4422 = fixdenorm(mix_4421);
			t_sample rsub_2983 = (((int)1) - gen_1958);
			t_sample sub_4452 = (rsub_2983 - ((t_sample)0.0001));
			t_sample scale_4449 = ((safepow((sub_4452 * ((t_sample)1.000200040008)), ((int)1)) * ((t_sample)1.75)) + ((t_sample)0.25));
			t_sample out8 = scale_4449;
			t_sample rdiv_2984 = safediv(((int)1), scale_4449);
			t_sample phasor_2986 = __m_phasor_26(rdiv_2984, samples_to_seconds);
			t_sample mul_3048 = (phasor_2986 * ((int)2));
			t_sample sub_3047 = (mul_3048 - ((int)1));
			t_sample cos_3046 = cos(sub_3047);
			t_sample sub_3045 = (cos_3046 - ((t_sample)0.5));
			t_sample mul_3044 = (sub_3045 * ((int)10));
			t_sample clamp_3043 = ((mul_3044 <= ((int)0)) ? ((int)0) : ((mul_3044 >= ((int)1)) ? ((int)1) : mul_3044));
			t_sample fold_3050 = fold(phasor_2986, ((int)0), ((int)1));
			double sample_index_27 = (fold_3050 * (pitchloop_dim - 1));
			int index_trunc_28 = fixnan(floor(sample_index_27));
			double index_fract_29 = (sample_index_27 - index_trunc_28);
			int index_trunc_30 = (index_trunc_28 - 1);
			int index_trunc_31 = (index_trunc_28 + 1);
			int index_trunc_32 = (index_trunc_28 + 2);
			bool index_ignore_33 = ((index_trunc_30 >= pitchloop_dim) || (index_trunc_30 < 0));
			bool index_ignore_34 = ((index_trunc_28 >= pitchloop_dim) || (index_trunc_28 < 0));
			bool index_ignore_35 = ((index_trunc_31 >= pitchloop_dim) || (index_trunc_31 < 0));
			bool index_ignore_36 = ((index_trunc_32 >= pitchloop_dim) || (index_trunc_32 < 0));
			// phase pitchloop channel 1;
			double read_pitchloop_37 = (index_ignore_33 ? 0 : m_pitchloop_11.read(index_trunc_30, 0));
			double read_pitchloop_38 = (index_ignore_34 ? 0 : m_pitchloop_11.read(index_trunc_28, 0));
			double read_pitchloop_39 = (index_ignore_35 ? 0 : m_pitchloop_11.read(index_trunc_31, 0));
			double read_pitchloop_40 = (index_ignore_36 ? 0 : m_pitchloop_11.read(index_trunc_32, 0));
			double readinterp_41 = spline_interp(index_fract_29, read_pitchloop_37, read_pitchloop_38, read_pitchloop_39, read_pitchloop_40);
			t_sample sample_pitchloop_3056 = readinterp_41;
			t_sample index_pitchloop_3057 = sample_index_27;
			t_sample mul_3041 = (sample_pitchloop_3056 * clamp_3043);
			t_sample mix_4453 = (in1 + (gen_1959 * (mul_3041 - in1)));
			t_sample out1 = mix_4453;
			m_history_6 = history_1948_next_1950;
			m_history_4 = history_1944_next_1952;
			m_history_5 = history_1946_next_1951;
			m_history_3 = history_1948_next_4423;
			m_history_1 = history_1944_next_4422;
			m_history_2 = history_1946_next_4419;
			// assign results to output buffer;
			(*(__out1++)) = out1;
			(*(__out2++)) = out2;
			(*(__out3++)) = out3;
			(*(__out4++)) = out4;
			(*(__out5++)) = out5;
			(*(__out6++)) = out6;
			(*(__out7++)) = out7;
			(*(__out8++)) = out8;
			(*(__out9++)) = out9;
			
		};
		return __exception;
		
	};
	inline void set_sw2(t_param _value) {
		m_sw_7 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_gate(t_param _value) {
		m_gate_8 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw1(t_param _value) {
		m_sw_9 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_ctrl5(t_param _value) {
		m_ctrl_10 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_pitchloop(void * _value) {
		m_pitchloop_11.setbuffer(_value);
	};
	inline void set_ctrl7(t_param _value) {
		m_ctrl_12 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_ctrl3(t_param _value) {
		m_ctrl_13 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_ctrl6(t_param _value) {
		m_ctrl_14 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_ctrl2(t_param _value) {
		m_ctrl_15 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_ctrl4(t_param _value) {
		m_ctrl_16 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_button(t_param _value) {
		m_button_17 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_ctrl1(t_param _value) {
		m_ctrl_18 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	
} State;


///
///	Configuration for the genlib API
///

/// Number of signal inputs and outputs

int gen_kernel_numins = 2;
int gen_kernel_numouts = 9;

int num_inputs() { return gen_kernel_numins; }
int num_outputs() { return gen_kernel_numouts; }
int num_params() { return 12; }

/// Assistive lables for the signal inputs and outputs

const char *gen_kernel_innames[] = { "in1", "in2" };
const char *gen_kernel_outnames[] = { "out1", "out2", "led1", "led2", "led3", "led4", "out7", "out8", "out9" };

/// Invoke the signal process of a State object

int perform(CommonState *cself, t_sample **ins, long numins, t_sample **outs, long numouts, long n) {
	State* self = (State *)cself;
	return self->perform(ins, outs, n);
}

/// Reset all parameters and stateful operators of a State object

void reset(CommonState *cself) {
	State* self = (State *)cself;
	self->reset(cself->sr, cself->vs);
}

/// Set a parameter of a State object

void setparameter(CommonState *cself, long index, t_param value, void *ref) {
	State *self = (State *)cself;
	switch (index) {
		case 0: self->set_button(value); break;
		case 1: self->set_ctrl1(value); break;
		case 2: self->set_ctrl2(value); break;
		case 3: self->set_ctrl3(value); break;
		case 4: self->set_ctrl4(value); break;
		case 5: self->set_ctrl5(value); break;
		case 6: self->set_ctrl6(value); break;
		case 7: self->set_ctrl7(value); break;
		case 8: self->set_gate(value); break;
		case 9: self->set_pitchloop(ref); break;
		case 10: self->set_sw1(value); break;
		case 11: self->set_sw2(value); break;
		
		default: break;
	}
}

/// Get the value of a parameter of a State object

void getparameter(CommonState *cself, long index, t_param *value) {
	State *self = (State *)cself;
	switch (index) {
		case 0: *value = self->m_button_17; break;
		case 1: *value = self->m_ctrl_18; break;
		case 2: *value = self->m_ctrl_15; break;
		case 3: *value = self->m_ctrl_13; break;
		case 4: *value = self->m_ctrl_16; break;
		case 5: *value = self->m_ctrl_10; break;
		case 6: *value = self->m_ctrl_14; break;
		case 7: *value = self->m_ctrl_12; break;
		case 8: *value = self->m_gate_8; break;
		
		case 10: *value = self->m_sw_9; break;
		case 11: *value = self->m_sw_7; break;
		
		default: break;
	}
}

/// Get the name of a parameter of a State object

const char *getparametername(CommonState *cself, long index) {
	if (index >= 0 && index < cself->numparams) {
		return cself->params[index].name;
	}
	return 0;
}

/// Get the minimum value of a parameter of a State object

t_param getparametermin(CommonState *cself, long index) {
	if (index >= 0 && index < cself->numparams) {
		return cself->params[index].outputmin;
	}
	return 0;
}

/// Get the maximum value of a parameter of a State object

t_param getparametermax(CommonState *cself, long index) {
	if (index >= 0 && index < cself->numparams) {
		return cself->params[index].outputmax;
	}
	return 0;
}

/// Get parameter of a State object has a minimum and maximum value

char getparameterhasminmax(CommonState *cself, long index) {
	if (index >= 0 && index < cself->numparams) {
		return cself->params[index].hasminmax;
	}
	return 0;
}

/// Get the units of a parameter of a State object

const char *getparameterunits(CommonState *cself, long index) {
	if (index >= 0 && index < cself->numparams) {
		return cself->params[index].units;
	}
	return 0;
}

/// Get the size of the state of all parameters of a State object

size_t getstatesize(CommonState *cself) {
	return genlib_getstatesize(cself, &getparameter);
}

/// Get the state of all parameters of a State object

short getstate(CommonState *cself, char *state) {
	return genlib_getstate(cself, state, &getparameter);
}

/// set the state of all parameters of a State object

short setstate(CommonState *cself, const char *state) {
	return genlib_setstate(cself, state, &setparameter);
}

/// Allocate and configure a new State object and it's internal CommonState:

void *create(t_param sr, long vs) {
	State *self = new State;
	self->reset(sr, vs);
	ParamInfo *pi;
	self->__commonstate.inputnames = gen_kernel_innames;
	self->__commonstate.outputnames = gen_kernel_outnames;
	self->__commonstate.numins = gen_kernel_numins;
	self->__commonstate.numouts = gen_kernel_numouts;
	self->__commonstate.sr = sr;
	self->__commonstate.vs = vs;
	self->__commonstate.params = (ParamInfo *)genlib_sysmem_newptr(12 * sizeof(ParamInfo));
	self->__commonstate.numparams = 12;
	// initialize parameter 0 ("m_button_17")
	pi = self->__commonstate.params + 0;
	pi->name = "button";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_button_17;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 1 ("m_ctrl_18")
	pi = self->__commonstate.params + 1;
	pi->name = "ctrl1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_ctrl_18;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_ctrl_15")
	pi = self->__commonstate.params + 2;
	pi->name = "ctrl2";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_ctrl_15;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 3 ("m_ctrl_13")
	pi = self->__commonstate.params + 3;
	pi->name = "ctrl3";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_ctrl_13;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 4 ("m_ctrl_16")
	pi = self->__commonstate.params + 4;
	pi->name = "ctrl4";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_ctrl_16;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 5 ("m_ctrl_10")
	pi = self->__commonstate.params + 5;
	pi->name = "ctrl5";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_ctrl_10;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 6 ("m_ctrl_14")
	pi = self->__commonstate.params + 6;
	pi->name = "ctrl6";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_ctrl_14;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 7 ("m_ctrl_12")
	pi = self->__commonstate.params + 7;
	pi->name = "ctrl7";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_ctrl_12;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 8 ("m_gate_8")
	pi = self->__commonstate.params + 8;
	pi->name = "gate";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_gate_8;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 9 ("m_pitchloop_11")
	pi = self->__commonstate.params + 9;
	pi->name = "pitchloop";
	pi->paramtype = GENLIB_PARAMTYPE_SYM;
	pi->defaultvalue = 0.;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = false;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 10 ("m_sw_9")
	pi = self->__commonstate.params + 10;
	pi->name = "sw1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_9;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 11 ("m_sw_7")
	pi = self->__commonstate.params + 11;
	pi->name = "sw2";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_7;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	
	return self;
}

/// Release all resources and memory used by a State object:

void destroy(CommonState *cself) {
	State *self = (State *)cself;
	genlib_sysmem_freeptr(cself->params);
		
	delete self;
}


} // BenderVersio_2dinsp::
