#include "BenderVersio_2dbeta2.h"

namespace BenderVersio_2dbeta2 {

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
	Data m_loopR_30;
	Data m_loopM_36;
	Data m_loopL_33;
	Delta __m_delta_40;
	Phasor __m_phasor_143;
	Phasor __m_phasor_73;
	Phasor __m_phasor_57;
	Phasor __m_phasor_108;
	PlusEquals __m_pluseq_41;
	int __exception;
	int vectorsize;
	t_sample m_history_8;
	t_sample __m_count_43;
	t_sample __m_carry_45;
	t_sample m_history_2;
	t_sample m_history_3;
	t_sample __m_slide_37;
	t_sample m_history_4;
	t_sample __m_count_48;
	t_sample m_ctrl_34;
	t_sample m_gate_35;
	t_sample __m_carry_50;
	t_sample __m_count_53;
	t_sample __m_carry_55;
	t_sample __m_slide_70;
	t_sample samplerate;
	t_sample __m_slide_105;
	t_sample m_history_5;
	t_sample __m_slide_64;
	t_sample __m_slide_58;
	t_sample __m_slide_61;
	t_sample samples_to_seconds;
	t_sample m_history_1;
	t_sample m_history_7;
	t_sample m_ctrl_32;
	t_sample m_history_6;
	t_sample m_history_15;
	t_sample m_history_14;
	t_sample m_history_16;
	t_sample m_history_17;
	t_sample m_history_18;
	t_sample m_history_13;
	t_sample m_history_11;
	t_sample m_history_12;
	t_sample m_history_9;
	t_sample m_history_10;
	t_sample m_ctrl_31;
	t_sample m_history_19;
	t_sample m_history_21;
	t_sample __m_slide_140;
	t_sample m_button_28;
	t_sample m_sw_29;
	t_sample m_history_20;
	t_sample m_ctrl_26;
	t_sample m_ctrl_24;
	t_sample m_ctrl_25;
	t_sample m_history_22;
	t_sample m_sw_23;
	t_sample m_ctrl_27;
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
		m_history_7 = ((int)0);
		m_history_8 = ((int)0);
		m_history_9 = ((int)0);
		m_history_10 = ((int)0);
		m_history_11 = ((int)0);
		m_history_12 = ((int)0);
		m_history_13 = ((int)0);
		m_history_14 = ((int)0);
		m_history_15 = ((int)0);
		m_history_16 = ((int)0);
		m_history_17 = ((int)0);
		m_history_18 = ((int)0);
		m_history_19 = ((int)0);
		m_history_20 = ((int)0);
		m_history_21 = ((int)0);
		m_history_22 = ((int)0);
		m_sw_23 = ((int)0);
		m_ctrl_24 = ((int)0);
		m_ctrl_25 = ((int)0);
		m_ctrl_26 = ((int)0);
		m_ctrl_27 = ((int)0);
		m_button_28 = ((int)0);
		m_sw_29 = ((int)0);
		m_loopR_30.reset("loopR", ((int)192000), ((int)2));
		m_ctrl_31 = ((int)0);
		m_ctrl_32 = ((int)0);
		m_loopL_33.reset("loopL", ((int)192000), ((int)2));
		m_ctrl_34 = ((int)0);
		m_gate_35 = ((int)0);
		m_loopM_36.reset("loopM", ((int)192000), ((int)2));
		__m_slide_37 = 0;
		__m_delta_40.reset(0);
		__m_pluseq_41.reset(0);
		__m_count_43 = 0;
		__m_carry_45 = 0;
		__m_count_48 = 0;
		__m_carry_50 = 0;
		__m_count_53 = 0;
		__m_carry_55 = 0;
		samples_to_seconds = (1 / samplerate);
		__m_phasor_57.reset(0);
		__m_slide_58 = 0;
		__m_slide_61 = 0;
		__m_slide_64 = 0;
		__m_slide_70 = 0;
		__m_phasor_73.reset(0);
		__m_slide_105 = 0;
		__m_phasor_108.reset(0);
		__m_slide_140 = 0;
		__m_phasor_143.reset(0);
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
		t_sample * __out10 = __outs[9];
		if (__exception) {
			return __exception;
			
		} else if (( (__in1 == 0) || (__in2 == 0) || (__out1 == 0) || (__out2 == 0) || (__out3 == 0) || (__out4 == 0) || (__out5 == 0) || (__out6 == 0) || (__out7 == 0) || (__out8 == 0) || (__out9 == 0) || (__out10 == 0) )) {
			__exception = GENLIB_ERR_NULL_BUFFER;
			return __exception;
			
		};
		int loopM_dim = m_loopM_36.dim;
		int loopM_channels = m_loopM_36.channels;
		int loopM_dim_186 = loopM_dim;
		int loopL_dim = m_loopL_33.dim;
		int loopL_channels = m_loopL_33.channels;
		int loopL_dim_194 = loopL_dim;
		int loopR_dim = m_loopR_30.dim;
		int loopR_channels = m_loopR_30.channels;
		int loopR_dim_184 = loopR_dim;
		t_sample iup_38 = (1 / maximum(1, abs(((int)4000))));
		t_sample idown_39 = (1 / maximum(1, abs(((int)4000))));
		int or_263 = (m_gate_35 || m_button_28);
		int gt_54 = (or_263 > ((int)0));
		t_sample div_22 = (loopL_dim_194 * ((t_sample)0.25));
		t_sample div_24 = (loopM_dim_186 * ((t_sample)1));
		int mul_21 = (loopR_dim_184 * ((int)2));
		int choice_42 = ((int)2);
		t_sample selector_25 = ((choice_42 >= 3) ? mul_21 : ((choice_42 >= 2) ? div_24 : ((choice_42 >= 1) ? div_22 : 0)));
		int choice_47 = ((int)2);
		t_sample selector_27 = ((choice_47 >= 3) ? mul_21 : ((choice_47 >= 2) ? div_24 : ((choice_47 >= 1) ? div_22 : 0)));
		int choice_52 = ((int)2);
		t_sample selector_26 = ((choice_52 >= 3) ? mul_21 : ((choice_52 >= 2) ? div_24 : ((choice_52 >= 1) ? div_22 : 0)));
		int eq_226 = (m_sw_29 == ((int)0));
		samples_to_seconds = (1 / samplerate);
		t_sample iup_59 = (1 / maximum(1, abs(((int)4000))));
		t_sample idown_60 = (1 / maximum(1, abs(((int)4000))));
		t_sample iup_62 = (1 / maximum(1, abs(((int)4000))));
		t_sample idown_63 = (1 / maximum(1, abs(((int)4000))));
		t_sample iup_65 = (1 / maximum(1, abs(((int)4000))));
		t_sample idown_66 = (1 / maximum(1, abs(((int)4000))));
		int eq_230 = (m_sw_29 == ((t_sample)0.5));
		t_sample switch_229 = (eq_230 ? ((int)0) : m_sw_29);
		t_sample switch_227 = (eq_226 ? ((t_sample)0.5) : switch_229);
		t_sample sub_25294 = (switch_227 - ((int)0));
		t_sample scale_25291 = ((safepow((sub_25294 * ((t_sample)1)), ((int)1)) * ((int)2)) + ((int)1));
		t_sample choice_67 = int(scale_25291);
		t_sample choice_68 = int(scale_25291);
		t_sample choice_69 = int(scale_25291);
		int neq_28 = (scale_25291 != ((int)2));
		t_sample iup_71 = (1 / maximum(1, abs(((int)4000))));
		t_sample idown_72 = (1 / maximum(1, abs(((int)4000))));
		bool chan_ignore_99 = ((1 < 0) || (1 >= loopR_channels));
		t_sample iup_106 = (1 / maximum(1, abs(((int)4000))));
		t_sample idown_107 = (1 / maximum(1, abs(((int)4000))));
		bool chan_ignore_134 = ((1 < 0) || (1 >= loopL_channels));
		t_sample iup_141 = (1 / maximum(1, abs(((int)4000))));
		t_sample idown_142 = (1 / maximum(1, abs(((int)4000))));
		int min_159 = (-1);
		bool chan_ignore_170 = ((1 < 0) || (1 >= loopM_channels));
		int min_176 = (-1);
		int eq_220 = (m_sw_23 == ((int)0));
		int eq_224 = (m_sw_23 == ((t_sample)0.5));
		t_sample switch_223 = (eq_224 ? ((int)0) : m_sw_23);
		t_sample switch_221 = (eq_220 ? ((t_sample)0.5) : switch_223);
		t_sample sub_25337 = (switch_221 - ((int)0));
		t_sample scale_25334 = ((safepow((sub_25337 * ((t_sample)1)), ((int)1)) * ((int)2)) + ((int)1));
		t_sample choice_177 = int(scale_25334);
		int min_178 = (-1);
		int min_179 = (-1);
		bool chan_ignore_180 = ((((int)1) < 0) || (((int)1) >= loopL_channels));
		t_sample choice_183 = int(scale_25334);
		int min_184 = (-1);
		int min_185 = (-1);
		bool chan_ignore_186 = ((((int)1) < 0) || (((int)1) >= loopR_channels));
		t_sample choice_189 = int(scale_25334);
		int min_190 = (-1);
		int min_191 = (-1);
		bool chan_ignore_192 = ((((int)1) < 0) || (((int)1) >= loopM_channels));
		t_sample choice_195 = int(scale_25334);
		int min_196 = (-1);
		int min_197 = (-1);
		t_sample choice_200 = int(scale_25334);
		int min_201 = (-1);
		int min_202 = (-1);
		t_sample choice_205 = int(scale_25334);
		int min_206 = (-1);
		int min_207 = (-1);
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			const t_sample in2 = (*(__in2++));
			t_sample out8 = ((int)0);
			t_sample out7 = ((int)0);
			t_sample out9 = ((int)0);
			t_sample out10 = ((int)0);
			t_sample mix_25263 = (m_history_22 + (((t_sample)0.0042742627044161) * (m_ctrl_24 - m_history_22)));
			t_sample mix_235 = mix_25263;
			t_sample mix_25264 = (m_history_21 + (((t_sample)0.0042742627044161) * (mix_235 - m_history_21)));
			t_sample mix_233 = mix_25264;
			t_sample mix_25265 = (m_history_20 + (((t_sample)0.0042742627044161) * (mix_233 - m_history_20)));
			t_sample mix_231 = mix_25265;
			t_sample gen_241 = mix_231;
			t_sample history_236_next_238 = fixdenorm(mix_235);
			t_sample history_234_next_239 = fixdenorm(mix_233);
			t_sample history_232_next_240 = fixdenorm(mix_231);
			__m_slide_37 = fixdenorm((__m_slide_37 + (((gen_241 > __m_slide_37) ? iup_38 : idown_39) * (gen_241 - __m_slide_37))));
			t_sample slide_127 = __m_slide_37;
			int delta_259 = __m_delta_40(or_263);
			int gtep_258 = ((delta_259 >= ((int)1)) ? delta_259 : 0);
			t_sample plusequals_257 = __m_pluseq_41.post(gtep_258, m_history_19, 0);
			t_sample gen_262 = plusequals_257;
			int eq_255 = (plusequals_257 == ((int)2));
			t_sample history_256_next_260 = fixdenorm(eq_255);
			int gt_51 = (gen_262 > ((int)0));
			t_sample abs_47 = fabs(in1);
			t_sample add_46 = (abs_47 + ((t_sample)0.0001));
			t_sample rsub_49 = (((int)1) - add_46);
			t_sample abs_69 = fabs(in2);
			t_sample add_68 = (abs_69 + ((t_sample)0.0001));
			t_sample rsub_71 = (((int)1) - add_68);
			t_sample mix_25266 = (m_history_18 + (((t_sample)0.0042742627044161) * (m_ctrl_32 - m_history_18)));
			t_sample mix_24935 = mix_25266;
			t_sample mix_25267 = (m_history_17 + (((t_sample)0.0042742627044161) * (mix_24935 - m_history_17)));
			t_sample mix_24928 = mix_25267;
			t_sample mix_25268 = (m_history_16 + (((t_sample)0.0042742627044161) * (mix_24928 - m_history_16)));
			t_sample mix_24936 = mix_25268;
			t_sample gen_247 = mix_24936;
			t_sample history_236_next_24931 = fixdenorm(mix_24935);
			t_sample history_234_next_24932 = fixdenorm(mix_24928);
			t_sample history_232_next_24927 = fixdenorm(mix_24936);
			__m_count_43 = (((int)0) ? 0 : (fixdenorm(__m_count_43 + ((int)1))));
			int carry_44 = 0;
			if ((((int)0) != 0)) {
				__m_count_43 = 0;
				__m_carry_45 = 0;
				
			} else if (((selector_25 > 0) && (__m_count_43 >= selector_25))) {
				int wraps_46 = (__m_count_43 / selector_25);
				__m_carry_45 = (__m_carry_45 + wraps_46);
				__m_count_43 = (__m_count_43 - (wraps_46 * selector_25));
				carry_44 = 1;
				
			};
			int counter_177 = __m_count_43;
			int counter_178 = carry_44;
			int counter_179 = __m_carry_45;
			__m_count_48 = (((int)0) ? 0 : (fixdenorm(__m_count_48 + ((int)1))));
			int carry_49 = 0;
			if ((((int)0) != 0)) {
				__m_count_48 = 0;
				__m_carry_50 = 0;
				
			} else if (((selector_27 > 0) && (__m_count_48 >= selector_27))) {
				int wraps_51 = (__m_count_48 / selector_27);
				__m_carry_50 = (__m_carry_50 + wraps_51);
				__m_count_48 = (__m_count_48 - (wraps_51 * selector_27));
				carry_49 = 1;
				
			};
			int counter_189 = __m_count_48;
			int counter_190 = carry_49;
			int counter_191 = __m_carry_50;
			__m_count_53 = (((int)0) ? 0 : (fixdenorm(__m_count_53 + ((int)1))));
			int carry_54 = 0;
			if ((((int)0) != 0)) {
				__m_count_53 = 0;
				__m_carry_55 = 0;
				
			} else if (((selector_26 > 0) && (__m_count_53 >= selector_26))) {
				int wraps_56 = (__m_count_53 / selector_26);
				__m_carry_55 = (__m_carry_55 + wraps_56);
				__m_count_53 = (__m_count_53 - (wraps_56 * selector_26));
				carry_54 = 1;
				
			};
			int counter_181 = __m_count_53;
			int counter_182 = carry_54;
			int counter_183 = __m_carry_55;
			t_sample fold_45 = fold(in1, (-1), ((int)0));
			t_sample fold_65 = fold(in2, (-1), ((int)0));
			t_sample mix_25269 = (m_history_15 + (((t_sample)0.0042742627044161) * (m_ctrl_31 - m_history_15)));
			t_sample mix_24942 = mix_25269;
			t_sample mix_25270 = (m_history_14 + (((t_sample)0.0042742627044161) * (mix_24942 - m_history_14)));
			t_sample mix_24945 = mix_25270;
			t_sample mix_25271 = (m_history_13 + (((t_sample)0.0042742627044161) * (mix_24945 - m_history_13)));
			t_sample mix_24949 = mix_25271;
			t_sample gen_246 = mix_24949;
			t_sample history_236_next_24943 = fixdenorm(mix_24942);
			t_sample history_234_next_24941 = fixdenorm(mix_24945);
			t_sample history_232_next_24944 = fixdenorm(mix_24949);
			t_sample phasor_6 = __m_phasor_57(((int)1), samples_to_seconds);
			t_sample mul_3 = (phasor_6 * ((t_sample)0.2));
			t_sample mix_25272 = (m_history_12 + (((t_sample)0.0042742627044161) * (m_ctrl_27 - m_history_12)));
			t_sample mix_24955 = mix_25272;
			t_sample mix_25273 = (m_history_11 + (((t_sample)0.0042742627044161) * (mix_24955 - m_history_11)));
			t_sample mix_24957 = mix_25273;
			t_sample mix_25274 = (m_history_10 + (((t_sample)0.0042742627044161) * (mix_24957 - m_history_10)));
			t_sample mix_24961 = mix_25274;
			t_sample gen_245 = mix_24961;
			t_sample history_236_next_24962 = fixdenorm(mix_24955);
			t_sample history_234_next_24954 = fixdenorm(mix_24957);
			t_sample history_232_next_24956 = fixdenorm(mix_24961);
			t_sample sub_25278 = (gen_245 - ((int)0));
			t_sample scale_25275 = ((safepow((sub_25278 * ((t_sample)1)), ((int)1)) * ((int)2)) + (-1));
			t_sample gtep_115 = ((scale_25275 >= ((int)0)) ? scale_25275 : 0);
			__m_slide_58 = fixdenorm((__m_slide_58 + (((gtep_115 > __m_slide_58) ? iup_59 : idown_60) * (gtep_115 - __m_slide_58))));
			t_sample slide_112 = __m_slide_58;
			t_sample ceil_32 = ceil(slide_112);
			t_sample add_1107 = (fold_65 + gtep_115);
			t_sample sub_25282 = (gen_245 - ((int)0));
			t_sample scale_25279 = ((safepow((sub_25282 * ((t_sample)1)), ((int)1)) * ((int)2)) + (-1));
			t_sample abs_120 = fabs(scale_25279);
			t_sample sub_25286 = (abs_120 - ((int)1));
			t_sample scale_25283 = ((safepow((sub_25286 * ((t_sample)-1)), ((int)1)) * ((int)1)) + ((int)0));
			__m_slide_61 = fixdenorm((__m_slide_61 + (((scale_25283 > __m_slide_61) ? iup_62 : idown_63) * (scale_25283 - __m_slide_61))));
			t_sample slide_113 = __m_slide_61;
			t_sample ceil_33 = ceil(slide_113);
			t_sample add_2093 = (add_1107 + scale_25283);
			t_sample sub_3903 = (add_2093 - ((t_sample)0.3));
			t_sample sub_25290 = (gen_245 - ((int)0));
			t_sample scale_25287 = ((safepow((sub_25290 * ((t_sample)1)), ((int)1)) * ((int)2)) + (-1));
			t_sample ltep_117 = ((scale_25287 <= ((int)0)) ? scale_25287 : 0);
			t_sample abs_118 = fabs(ltep_117);
			__m_slide_64 = fixdenorm((__m_slide_64 + (((abs_118 > __m_slide_64) ? iup_65 : idown_66) * (abs_118 - __m_slide_64))));
			t_sample slide_114 = __m_slide_64;
			t_sample ceil_34 = ceil(slide_114);
			t_sample add_1600 = (fold_45 + abs_118);
			t_sample add_2422 = (add_1600 + scale_25283);
			t_sample sub_3574 = (add_2422 - ((t_sample)0.3));
			t_sample selector_102 = ((choice_67 >= 3) ? gt_51 : ((choice_67 >= 2) ? ((int)1) : ((choice_67 >= 1) ? gt_54 : 0)));
			t_sample selector_48 = ((choice_68 >= 3) ? gt_51 : ((choice_68 >= 2) ? ((int)1) : ((choice_68 >= 1) ? gt_54 : 0)));
			t_sample switch_50 = (selector_48 ? rsub_49 : sub_3574);
			t_sample out3 = switch_50;
			t_sample selector_70 = ((choice_69 >= 3) ? gt_51 : ((choice_69 >= 2) ? ((int)1) : ((choice_69 >= 1) ? gt_54 : 0)));
			t_sample switch_72 = (selector_70 ? rsub_71 : sub_3903);
			t_sample out4 = switch_72;
			t_sample switch_37 = (neq_28 ? ceil_32 : ((int)1));
			t_sample mul_36 = (counter_177 * switch_37);
			t_sample switch_100 = (selector_102 ? mul_36 : ((int)0));
			t_sample mul_35 = (counter_177 * switch_37);
			t_sample switch_97 = (selector_102 ? mul_35 : ((int)0));
			t_sample switch_42 = (neq_28 ? ceil_34 : ((int)1));
			t_sample mul_43 = (switch_42 * counter_189);
			t_sample switch_103 = (selector_102 ? mul_43 : ((int)0));
			t_sample mul_41 = (switch_42 * counter_189);
			t_sample switch_101 = (selector_102 ? mul_41 : ((int)0));
			t_sample switch_39 = (neq_28 ? ceil_33 : ((int)1));
			t_sample mul_40 = (switch_39 * counter_181);
			t_sample switch_99 = (selector_102 ? mul_40 : ((int)0));
			t_sample mul_38 = (switch_39 * counter_181);
			t_sample switch_98 = (selector_102 ? mul_38 : ((int)0));
			t_sample mix_25295 = (m_history_9 + (((t_sample)0.0042742627044161) * (m_ctrl_34 - m_history_9)));
			t_sample mix_24967 = mix_25295;
			t_sample mix_25296 = (m_history_8 + (((t_sample)0.0042742627044161) * (mix_24967 - m_history_8)));
			t_sample mix_24968 = mix_25296;
			t_sample mix_25297 = (m_history_7 + (((t_sample)0.0042742627044161) * (mix_24968 - m_history_7)));
			t_sample mix_24975 = mix_25297;
			t_sample gen_244 = mix_24975;
			t_sample history_236_next_24971 = fixdenorm(mix_24967);
			t_sample history_234_next_24966 = fixdenorm(mix_24968);
			t_sample history_232_next_24973 = fixdenorm(mix_24975);
			t_sample sub_25301 = (gen_244 - ((int)0));
			t_sample scale_25298 = ((safepow((sub_25301 * ((t_sample)1)), ((int)1)) * ((int)2)) + (-1));
			t_sample abs_75 = fabs(scale_25298);
			t_sample sub_25305 = (abs_75 - ((int)1));
			t_sample scale_25302 = ((safepow((sub_25305 * ((t_sample)-1)), ((int)1)) * ((t_sample)3.5)) + ((t_sample)0.5));
			int gt_14 = (scale_25302 > ((int)2));
			t_sample mix_25306 = (m_history_6 + (((t_sample)0.0042742627044161) * (m_ctrl_25 - m_history_6)));
			t_sample mix_24980 = mix_25306;
			t_sample mix_25307 = (m_history_5 + (((t_sample)0.0042742627044161) * (mix_24980 - m_history_5)));
			t_sample mix_24981 = mix_25307;
			t_sample mix_25308 = (m_history_4 + (((t_sample)0.0042742627044161) * (mix_24981 - m_history_4)));
			t_sample mix_24988 = mix_25308;
			t_sample gen_243 = mix_24988;
			t_sample history_236_next_24983 = fixdenorm(mix_24980);
			t_sample history_234_next_24979 = fixdenorm(mix_24981);
			t_sample history_232_next_24986 = fixdenorm(mix_24988);
			t_sample sub_25312 = (gen_243 - ((int)0));
			t_sample scale_25309 = ((safepow((sub_25312 * ((t_sample)1)), ((int)1)) * ((int)2)) + (-1));
			t_sample abs_59 = fabs(scale_25309);
			t_sample sub_25316 = (abs_59 - ((int)1));
			t_sample scale_25313 = ((safepow((sub_25316 * ((t_sample)-1)), ((int)1)) * ((t_sample)3.5)) + ((t_sample)0.5));
			int gt_9 = (scale_25313 > ((int)2));
			t_sample mix_25317 = (m_history_3 + (((t_sample)0.0042742627044161) * (m_ctrl_26 - m_history_3)));
			t_sample mix_24993 = mix_25317;
			t_sample mix_25318 = (m_history_2 + (((t_sample)0.0042742627044161) * (mix_24993 - m_history_2)));
			t_sample mix_24994 = mix_25318;
			t_sample mix_25319 = (m_history_1 + (((t_sample)0.0042742627044161) * (mix_24994 - m_history_1)));
			t_sample mix_25001 = mix_25319;
			t_sample gen_242 = mix_25001;
			t_sample history_236_next_24997 = fixdenorm(mix_24993);
			t_sample history_234_next_24992 = fixdenorm(mix_24994);
			t_sample history_232_next_24999 = fixdenorm(mix_25001);
			t_sample sub_25323 = (gen_242 - ((int)0));
			t_sample scale_25320 = ((safepow((sub_25323 * ((t_sample)1)), ((int)1)) * ((int)2)) + (-1));
			t_sample abs_63 = fabs(scale_25320);
			t_sample sub_25327 = (abs_63 - ((int)1));
			t_sample scale_25324 = ((safepow((sub_25327 * ((t_sample)-1)), ((int)1)) * ((t_sample)3.5)) + ((t_sample)0.5));
			int lt_8 = (scale_25324 < ((int)2));
			t_sample rdiv_147 = safediv(((int)1), scale_25313);
			__m_slide_70 = fixdenorm((__m_slide_70 + (((rdiv_147 > __m_slide_70) ? iup_71 : idown_72) * (rdiv_147 - __m_slide_70))));
			t_sample slide_57 = __m_slide_70;
			t_sample phasor_148 = __m_phasor_73(slide_57, samples_to_seconds);
			t_sample mul_145 = (phasor_148 * ((int)2));
			t_sample sub_144 = (mul_145 - ((int)1));
			t_sample cos_143 = cos(sub_144);
			t_sample sub_142 = (cos_143 - ((t_sample)0.5));
			t_sample mul_141 = (sub_142 * ((int)10));
			t_sample clamp_140 = ((mul_141 <= ((int)0)) ? ((int)0) : ((mul_141 >= ((int)1)) ? ((int)1) : mul_141));
			t_sample fold_133 = fold(phasor_148, ((int)0), ((int)1));
			double sample_index_74 = (fold_133 * (loopR_dim - 1));
			int index_trunc_75 = fixnan(floor(sample_index_74));
			double index_fract_76 = (sample_index_74 - index_trunc_75);
			int index_trunc_77 = (index_trunc_75 - 1);
			int index_trunc_78 = (index_trunc_75 + 1);
			int index_trunc_79 = (index_trunc_75 + 2);
			bool index_ignore_80 = ((index_trunc_77 >= loopR_dim) || (index_trunc_77 < 0));
			bool index_ignore_81 = ((index_trunc_75 >= loopR_dim) || (index_trunc_75 < 0));
			bool index_ignore_82 = ((index_trunc_78 >= loopR_dim) || (index_trunc_78 < 0));
			bool index_ignore_83 = ((index_trunc_79 >= loopR_dim) || (index_trunc_79 < 0));
			// phase loopR channel 1;
			double read_loopR_84 = (index_ignore_80 ? 0 : m_loopR_30.read(index_trunc_77, 0));
			double read_loopR_85 = (index_ignore_81 ? 0 : m_loopR_30.read(index_trunc_75, 0));
			double read_loopR_86 = (index_ignore_82 ? 0 : m_loopR_30.read(index_trunc_78, 0));
			double read_loopR_87 = (index_ignore_83 ? 0 : m_loopR_30.read(index_trunc_79, 0));
			double readinterp_88 = spline_interp(index_fract_76, read_loopR_84, read_loopR_85, read_loopR_86, read_loopR_87);
			t_sample sample_loopR_138 = readinterp_88;
			t_sample index_loopR_139 = sample_index_74;
			t_sample mul_132 = (sample_loopR_138 * clamp_140);
			double sample_index_89 = (fold_133 * (loopR_dim - 1));
			int index_trunc_90 = fixnan(floor(sample_index_89));
			double index_fract_91 = (sample_index_89 - index_trunc_90);
			int index_trunc_92 = (index_trunc_90 - 1);
			int index_trunc_93 = (index_trunc_90 + 1);
			int index_trunc_94 = (index_trunc_90 + 2);
			bool index_ignore_95 = ((index_trunc_92 >= loopR_dim) || (index_trunc_92 < 0));
			bool index_ignore_96 = ((index_trunc_90 >= loopR_dim) || (index_trunc_90 < 0));
			bool index_ignore_97 = ((index_trunc_93 >= loopR_dim) || (index_trunc_93 < 0));
			bool index_ignore_98 = ((index_trunc_94 >= loopR_dim) || (index_trunc_94 < 0));
			// phase loopR channel 1;
			double read_loopR_100 = ((chan_ignore_99 || index_ignore_95) ? 0 : m_loopR_30.read(index_trunc_92, 1));
			double read_loopR_101 = ((chan_ignore_99 || index_ignore_96) ? 0 : m_loopR_30.read(index_trunc_90, 1));
			double read_loopR_102 = ((chan_ignore_99 || index_ignore_97) ? 0 : m_loopR_30.read(index_trunc_93, 1));
			double read_loopR_103 = ((chan_ignore_99 || index_ignore_98) ? 0 : m_loopR_30.read(index_trunc_94, 1));
			double readinterp_104 = spline_interp(index_fract_91, read_loopR_100, read_loopR_101, read_loopR_102, read_loopR_103);
			t_sample sample_loopR_136 = readinterp_104;
			t_sample index_loopR_137 = sample_index_89;
			t_sample mul_131 = (sample_loopR_136 * clamp_140);
			t_sample rdiv_215 = safediv(((int)1), scale_25302);
			__m_slide_105 = fixdenorm((__m_slide_105 + (((rdiv_215 > __m_slide_105) ? iup_106 : idown_107) * (rdiv_215 - __m_slide_105))));
			t_sample slide_73 = __m_slide_105;
			t_sample phasor_216 = __m_phasor_108(slide_73, samples_to_seconds);
			t_sample mul_204 = (phasor_216 * ((int)2));
			t_sample sub_203 = (mul_204 - ((int)1));
			t_sample cos_202 = cos(sub_203);
			t_sample sub_201 = (cos_202 - ((t_sample)0.5));
			t_sample mul_200 = (sub_201 * ((int)10));
			t_sample clamp_199 = ((mul_200 <= ((int)0)) ? ((int)0) : ((mul_200 >= ((int)1)) ? ((int)1) : mul_200));
			t_sample fold_206 = fold(phasor_216, ((int)0), ((int)1));
			double sample_index_109 = (fold_206 * (loopL_dim - 1));
			int index_trunc_110 = fixnan(floor(sample_index_109));
			double index_fract_111 = (sample_index_109 - index_trunc_110);
			int index_trunc_112 = (index_trunc_110 - 1);
			int index_trunc_113 = (index_trunc_110 + 1);
			int index_trunc_114 = (index_trunc_110 + 2);
			int index_clamp_115 = ((index_trunc_112 < 0) ? 0 : ((index_trunc_112 > loopL_dim) ? loopL_dim : index_trunc_112));
			int index_clamp_116 = ((index_trunc_110 < 0) ? 0 : ((index_trunc_110 > loopL_dim) ? loopL_dim : index_trunc_110));
			int index_clamp_117 = ((index_trunc_113 < 0) ? 0 : ((index_trunc_113 > loopL_dim) ? loopL_dim : index_trunc_113));
			int index_clamp_118 = ((index_trunc_114 < 0) ? 0 : ((index_trunc_114 > loopL_dim) ? loopL_dim : index_trunc_114));
			// phase loopL channel 1;
			double read_loopL_119 = m_loopL_33.read(index_clamp_115, 0);
			double read_loopL_120 = m_loopL_33.read(index_clamp_116, 0);
			double read_loopL_121 = m_loopL_33.read(index_clamp_117, 0);
			double read_loopL_122 = m_loopL_33.read(index_clamp_118, 0);
			double readinterp_123 = spline_interp(index_fract_111, read_loopL_119, read_loopL_120, read_loopL_121, read_loopL_122);
			t_sample sample_loopL_212 = readinterp_123;
			t_sample index_loopL_213 = sample_index_109;
			t_sample mul_197 = (sample_loopL_212 * clamp_199);
			double sample_index_124 = (fold_206 * (loopL_dim - 1));
			int index_trunc_125 = fixnan(floor(sample_index_124));
			double index_fract_126 = (sample_index_124 - index_trunc_125);
			int index_trunc_127 = (index_trunc_125 - 1);
			int index_trunc_128 = (index_trunc_125 + 1);
			int index_trunc_129 = (index_trunc_125 + 2);
			int index_clamp_130 = ((index_trunc_127 < 0) ? 0 : ((index_trunc_127 > loopL_dim) ? loopL_dim : index_trunc_127));
			int index_clamp_131 = ((index_trunc_125 < 0) ? 0 : ((index_trunc_125 > loopL_dim) ? loopL_dim : index_trunc_125));
			int index_clamp_132 = ((index_trunc_128 < 0) ? 0 : ((index_trunc_128 > loopL_dim) ? loopL_dim : index_trunc_128));
			int index_clamp_133 = ((index_trunc_129 < 0) ? 0 : ((index_trunc_129 > loopL_dim) ? loopL_dim : index_trunc_129));
			// phase loopL channel 1;
			double read_loopL_135 = (chan_ignore_134 ? 0 : m_loopL_33.read(index_clamp_130, 1));
			double read_loopL_136 = (chan_ignore_134 ? 0 : m_loopL_33.read(index_clamp_131, 1));
			double read_loopL_137 = (chan_ignore_134 ? 0 : m_loopL_33.read(index_clamp_132, 1));
			double read_loopL_138 = (chan_ignore_134 ? 0 : m_loopL_33.read(index_clamp_133, 1));
			double readinterp_139 = spline_interp(index_fract_126, read_loopL_135, read_loopL_136, read_loopL_137, read_loopL_138);
			t_sample sample_loopL_210 = readinterp_139;
			t_sample index_loopL_211 = sample_index_124;
			t_sample mul_198 = (sample_loopL_210 * clamp_199);
			t_sample rdiv_168 = safediv(((int)1), scale_25324);
			__m_slide_140 = fixdenorm((__m_slide_140 + (((rdiv_168 > __m_slide_140) ? iup_141 : idown_142) * (rdiv_168 - __m_slide_140))));
			t_sample slide_61 = __m_slide_140;
			t_sample phasor_169 = __m_phasor_143(slide_61, samples_to_seconds);
			t_sample mul_166 = (phasor_169 * ((int)2));
			t_sample sub_165 = (mul_166 - ((int)1));
			t_sample cos_164 = cos(sub_165);
			t_sample sub_163 = (cos_164 - ((t_sample)0.5));
			t_sample mul_162 = (sub_163 * ((int)10));
			t_sample clamp_161 = ((mul_162 <= ((int)0)) ? ((int)0) : ((mul_162 >= ((int)1)) ? ((int)1) : mul_162));
			t_sample fold_154 = fold(phasor_169, ((int)0), ((int)1));
			double sample_index_144 = (fold_154 * (loopM_dim - 1));
			int index_trunc_145 = fixnan(floor(sample_index_144));
			double index_fract_146 = (sample_index_144 - index_trunc_145);
			int index_trunc_147 = (index_trunc_145 - 1);
			int index_trunc_148 = (index_trunc_145 + 1);
			int index_trunc_149 = (index_trunc_145 + 2);
			bool index_ignore_150 = ((index_trunc_147 >= loopM_dim) || (index_trunc_147 < 0));
			bool index_ignore_151 = ((index_trunc_145 >= loopM_dim) || (index_trunc_145 < 0));
			bool index_ignore_152 = ((index_trunc_148 >= loopM_dim) || (index_trunc_148 < 0));
			bool index_ignore_153 = ((index_trunc_149 >= loopM_dim) || (index_trunc_149 < 0));
			// phase loopM channel 1;
			double read_loopM_154 = (index_ignore_150 ? 0 : m_loopM_36.read(index_trunc_147, 0));
			double read_loopM_155 = (index_ignore_151 ? 0 : m_loopM_36.read(index_trunc_145, 0));
			double read_loopM_156 = (index_ignore_152 ? 0 : m_loopM_36.read(index_trunc_148, 0));
			double read_loopM_157 = (index_ignore_153 ? 0 : m_loopM_36.read(index_trunc_149, 0));
			double readinterp_158 = spline_interp(index_fract_146, read_loopM_154, read_loopM_155, read_loopM_156, read_loopM_157);
			t_sample sample_loopM_159 = readinterp_158;
			t_sample index_loopM_160 = sample_index_144;
			t_sample mul_153 = (sample_loopM_159 * clamp_161);
			t_sample mix_25328 = (mul_197 + (((t_sample)0.5) * (mul_153 - mul_197)));
			t_sample mix_25329 = (mix_25328 + (((t_sample)0.33) * (mul_132 - mix_25328)));
			t_sample mul_105 = (mix_25329 * ((int)3));
			t_sample mix_25330 = (in1 + (gen_247 * (mul_105 - in1)));
			t_sample clamp_125 = ((mix_25330 <= min_159) ? min_159 : ((mix_25330 >= ((int)1)) ? ((int)1) : mix_25330));
			t_sample out1 = clamp_125;
			t_sample fold_67 = fold(clamp_125, (-1), ((int)0));
			t_sample abs_16 = fabs(clamp_125);
			t_sample add_15 = (abs_16 + ((t_sample)0.0001));
			t_sample rsub_17 = (((int)1) - add_15);
			t_sample mul_4 = (mul_3 * rsub_17);
			t_sample switch_7 = (lt_8 ? rsub_17 : mul_4);
			t_sample switch_18 = (gt_14 ? switch_7 : fold_67);
			t_sample out5 = switch_18;
			double sample_index_160 = (fold_154 * (loopM_dim - 1));
			int index_trunc_161 = fixnan(floor(sample_index_160));
			double index_fract_162 = (sample_index_160 - index_trunc_161);
			int index_trunc_163 = (index_trunc_161 - 1);
			int index_trunc_164 = (index_trunc_161 + 1);
			int index_trunc_165 = (index_trunc_161 + 2);
			bool index_ignore_166 = ((index_trunc_163 >= loopM_dim) || (index_trunc_163 < 0));
			bool index_ignore_167 = ((index_trunc_161 >= loopM_dim) || (index_trunc_161 < 0));
			bool index_ignore_168 = ((index_trunc_164 >= loopM_dim) || (index_trunc_164 < 0));
			bool index_ignore_169 = ((index_trunc_165 >= loopM_dim) || (index_trunc_165 < 0));
			// phase loopM channel 1;
			double read_loopM_171 = ((chan_ignore_170 || index_ignore_166) ? 0 : m_loopM_36.read(index_trunc_163, 1));
			double read_loopM_172 = ((chan_ignore_170 || index_ignore_167) ? 0 : m_loopM_36.read(index_trunc_161, 1));
			double read_loopM_173 = ((chan_ignore_170 || index_ignore_168) ? 0 : m_loopM_36.read(index_trunc_164, 1));
			double read_loopM_174 = ((chan_ignore_170 || index_ignore_169) ? 0 : m_loopM_36.read(index_trunc_165, 1));
			double readinterp_175 = spline_interp(index_fract_162, read_loopM_171, read_loopM_172, read_loopM_173, read_loopM_174);
			t_sample sample_loopM_157 = readinterp_175;
			t_sample index_loopM_158 = sample_index_160;
			t_sample mul_152 = (sample_loopM_157 * clamp_161);
			t_sample mix_25331 = (mul_198 + (((t_sample)0.5) * (mul_152 - mul_198)));
			t_sample mix_25332 = (mix_25331 + (((t_sample)0.33) * (mul_131 - mix_25331)));
			t_sample mul_104 = (mix_25332 * ((int)3));
			t_sample mix_25333 = (in2 + (gen_247 * (mul_104 - in2)));
			t_sample clamp_124 = ((mix_25333 <= min_176) ? min_176 : ((mix_25333 >= ((int)1)) ? ((int)1) : mix_25333));
			t_sample out2 = clamp_124;
			t_sample fold_66 = fold(clamp_124, (-1), ((int)0));
			t_sample abs_11 = fabs(clamp_124);
			t_sample add_10 = (abs_11 + ((t_sample)0.0001));
			t_sample rsub_12 = (((int)1) - add_10);
			t_sample mul_1 = (rsub_12 * mul_3);
			t_sample switch_2 = (lt_8 ? rsub_12 : mul_1);
			t_sample switch_13 = (gt_9 ? switch_2 : fold_66);
			t_sample out6 = switch_13;
			t_sample selector_14175 = ((choice_177 >= 3) ? mul_152 : ((choice_177 >= 2) ? in2 : ((choice_177 >= 1) ? mul_152 : 0)));
			t_sample mix_25338 = (selector_14175 + (gen_246 * (mul_198 - selector_14175)));
			t_sample clamp_83 = ((mix_25338 <= min_178) ? min_178 : ((mix_25338 >= ((int)1)) ? ((int)1) : mix_25338));
			t_sample mul_108 = (clamp_83 * slide_114);
			t_sample clamp_86 = ((mul_108 <= min_179) ? min_179 : ((mul_108 >= ((int)1)) ? ((int)1) : mul_108));
			int index_trunc_181 = fixnan(floor(switch_101));
			int index_clamp_182 = ((index_trunc_181 < 0) ? 0 : ((index_trunc_181 > loopL_dim) ? loopL_dim : index_trunc_181));
			if ((!chan_ignore_180)) {
				m_loopL_33.write((clamp_86 + (m_loopL_33.read(index_clamp_182, ((int)1)) * slide_127)), index_clamp_182, ((int)1));
				
			};
			t_sample selector_14173 = ((choice_183 >= 3) ? mul_198 : ((choice_183 >= 2) ? in2 : ((choice_183 >= 1) ? mul_152 : 0)));
			t_sample mix_25339 = (selector_14173 + (gen_246 * (mul_131 - selector_14173)));
			t_sample clamp_79 = ((mix_25339 <= min_184) ? min_184 : ((mix_25339 >= ((int)1)) ? ((int)1) : mix_25339));
			t_sample mul_106 = (clamp_79 * slide_112);
			t_sample clamp_84 = ((mul_106 <= min_185) ? min_185 : ((mul_106 >= ((int)1)) ? ((int)1) : mul_106));
			int index_trunc_187 = fixnan(floor(switch_97));
			bool index_ignore_188 = ((index_trunc_187 >= loopR_dim) || (index_trunc_187 < 0));
			if ((!(chan_ignore_186 || index_ignore_188))) {
				m_loopR_30.write((clamp_84 + (m_loopR_30.read(index_trunc_187, ((int)1)) * slide_127)), index_trunc_187, ((int)1));
				
			};
			t_sample selector_14174 = ((choice_189 >= 3) ? in2 : ((choice_189 >= 2) ? in2 : ((choice_189 >= 1) ? in2 : 0)));
			t_sample mix_25340 = (selector_14174 + (gen_246 * (mul_152 - selector_14174)));
			t_sample clamp_81 = ((mix_25340 <= min_190) ? min_190 : ((mix_25340 >= ((int)1)) ? ((int)1) : mix_25340));
			t_sample mul_107 = (clamp_81 * slide_113);
			t_sample clamp_85 = ((mul_107 <= min_191) ? min_191 : ((mul_107 >= ((int)1)) ? ((int)1) : mul_107));
			int index_trunc_193 = fixnan(floor(switch_98));
			int index_wrap_194 = ((index_trunc_193 < 0) ? ((loopM_dim - 1) + ((index_trunc_193 + 1) % loopM_dim)) : (index_trunc_193 % loopM_dim));
			if ((!chan_ignore_192)) {
				m_loopM_36.write((clamp_85 + (m_loopM_36.read(index_wrap_194, ((int)1)) * slide_127)), index_wrap_194, ((int)1));
				
			};
			t_sample selector_9175 = ((choice_195 >= 3) ? mul_197 : ((choice_195 >= 2) ? in1 : ((choice_195 >= 1) ? mul_153 : 0)));
			t_sample mix_25341 = (selector_9175 + (gen_246 * (mul_132 - selector_9175)));
			t_sample clamp_13328 = ((mix_25341 <= min_196) ? min_196 : ((mix_25341 >= ((int)1)) ? ((int)1) : mix_25341));
			t_sample mul_109 = (clamp_13328 * slide_112);
			t_sample clamp_87 = ((mul_109 <= min_197) ? min_197 : ((mul_109 >= ((int)1)) ? ((int)1) : mul_109));
			int index_trunc_198 = fixnan(floor(switch_100));
			bool index_ignore_199 = ((index_trunc_198 >= loopR_dim) || (index_trunc_198 < 0));
			if ((!index_ignore_199)) {
				m_loopR_30.write((clamp_87 + (m_loopR_30.read(index_trunc_198, 0) * slide_127)), index_trunc_198, 0);
				
			};
			t_sample selector_8205 = ((choice_200 >= 3) ? mul_153 : ((choice_200 >= 2) ? in1 : ((choice_200 >= 1) ? mul_153 : 0)));
			t_sample mix_25342 = (selector_8205 + (gen_246 * (mul_197 - selector_8205)));
			t_sample clamp_92 = ((mix_25342 <= min_201) ? min_201 : ((mix_25342 >= ((int)1)) ? ((int)1) : mix_25342));
			t_sample mul_111 = (clamp_92 * slide_114);
			t_sample clamp_89 = ((mul_111 <= min_202) ? min_202 : ((mul_111 >= ((int)1)) ? ((int)1) : mul_111));
			int index_trunc_203 = fixnan(floor(switch_103));
			int index_clamp_204 = ((index_trunc_203 < 0) ? 0 : ((index_trunc_203 > loopL_dim) ? loopL_dim : index_trunc_203));
			m_loopL_33.write((clamp_89 + (m_loopL_33.read(index_clamp_204, 0) * slide_127)), index_clamp_204, 0);
			t_sample selector_8690 = ((choice_205 >= 3) ? in1 : ((choice_205 >= 2) ? in1 : ((choice_205 >= 1) ? in1 : 0)));
			t_sample mix_25343 = (selector_8690 + (gen_246 * (mul_153 - selector_8690)));
			t_sample clamp_91 = ((mix_25343 <= min_206) ? min_206 : ((mix_25343 >= ((int)1)) ? ((int)1) : mix_25343));
			t_sample mul_110 = (clamp_91 * slide_113);
			t_sample clamp_88 = ((mul_110 <= min_207) ? min_207 : ((mul_110 >= ((int)1)) ? ((int)1) : mul_110));
			int index_trunc_208 = fixnan(floor(switch_99));
			int index_wrap_209 = ((index_trunc_208 < 0) ? ((loopM_dim - 1) + ((index_trunc_208 + 1) % loopM_dim)) : (index_trunc_208 % loopM_dim));
			m_loopM_36.write((clamp_88 + (m_loopM_36.read(index_wrap_209, 0) * slide_127)), index_wrap_209, 0);
			m_history_22 = history_236_next_238;
			m_history_20 = history_232_next_240;
			m_history_21 = history_234_next_239;
			m_history_19 = history_256_next_260;
			m_history_18 = history_236_next_24931;
			m_history_16 = history_232_next_24927;
			m_history_17 = history_234_next_24932;
			m_history_15 = history_236_next_24943;
			m_history_13 = history_232_next_24944;
			m_history_14 = history_234_next_24941;
			m_history_12 = history_236_next_24962;
			m_history_10 = history_232_next_24956;
			m_history_11 = history_234_next_24954;
			m_history_9 = history_236_next_24971;
			m_history_7 = history_232_next_24973;
			m_history_8 = history_234_next_24966;
			m_history_6 = history_236_next_24983;
			m_history_4 = history_232_next_24986;
			m_history_5 = history_234_next_24979;
			m_history_3 = history_236_next_24997;
			m_history_1 = history_232_next_24999;
			m_history_2 = history_234_next_24992;
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
			(*(__out10++)) = out10;
			
		};
		return __exception;
		
	};
	inline void set_sw2(t_param _value) {
		m_sw_23 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_ctrl7(t_param _value) {
		m_ctrl_24 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_ctrl6(t_param _value) {
		m_ctrl_25 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_ctrl4(t_param _value) {
		m_ctrl_26 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_ctrl3(t_param _value) {
		m_ctrl_27 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_button(t_param _value) {
		m_button_28 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw1(t_param _value) {
		m_sw_29 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_loopR(void * _value) {
		m_loopR_30.setbuffer(_value);
	};
	inline void set_ctrl5(t_param _value) {
		m_ctrl_31 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_ctrl1(t_param _value) {
		m_ctrl_32 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_loopL(void * _value) {
		m_loopL_33.setbuffer(_value);
	};
	inline void set_ctrl2(t_param _value) {
		m_ctrl_34 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_gate(t_param _value) {
		m_gate_35 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_loopM(void * _value) {
		m_loopM_36.setbuffer(_value);
	};
	
} State;


///
///	Configuration for the genlib API
///

/// Number of signal inputs and outputs

int gen_kernel_numins = 2;
int gen_kernel_numouts = 10;

int num_inputs() { return gen_kernel_numins; }
int num_outputs() { return gen_kernel_numouts; }
int num_params() { return 14; }

/// Assistive lables for the signal inputs and outputs

const char *gen_kernel_innames[] = { "in1", "in2" };
const char *gen_kernel_outnames[] = { "out1", "out2", "led1", "led2", "led3", "led4", "out7", "out8", "out9", "out10" };

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
		case 9: self->set_loopL(ref); break;
		case 10: self->set_loopM(ref); break;
		case 11: self->set_loopR(ref); break;
		case 12: self->set_sw1(value); break;
		case 13: self->set_sw2(value); break;
		
		default: break;
	}
}

/// Get the value of a parameter of a State object

void getparameter(CommonState *cself, long index, t_param *value) {
	State *self = (State *)cself;
	switch (index) {
		case 0: *value = self->m_button_28; break;
		case 1: *value = self->m_ctrl_32; break;
		case 2: *value = self->m_ctrl_34; break;
		case 3: *value = self->m_ctrl_27; break;
		case 4: *value = self->m_ctrl_26; break;
		case 5: *value = self->m_ctrl_31; break;
		case 6: *value = self->m_ctrl_25; break;
		case 7: *value = self->m_ctrl_24; break;
		case 8: *value = self->m_gate_35; break;
		
		
		
		case 12: *value = self->m_sw_29; break;
		case 13: *value = self->m_sw_23; break;
		
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
	self->__commonstate.params = (ParamInfo *)genlib_sysmem_newptr(14 * sizeof(ParamInfo));
	self->__commonstate.numparams = 14;
	// initialize parameter 0 ("m_button_28")
	pi = self->__commonstate.params + 0;
	pi->name = "button";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_button_28;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 1 ("m_ctrl_32")
	pi = self->__commonstate.params + 1;
	pi->name = "ctrl1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_ctrl_32;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_ctrl_34")
	pi = self->__commonstate.params + 2;
	pi->name = "ctrl2";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_ctrl_34;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 3 ("m_ctrl_27")
	pi = self->__commonstate.params + 3;
	pi->name = "ctrl3";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_ctrl_27;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 4 ("m_ctrl_26")
	pi = self->__commonstate.params + 4;
	pi->name = "ctrl4";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_ctrl_26;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 5 ("m_ctrl_31")
	pi = self->__commonstate.params + 5;
	pi->name = "ctrl5";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_ctrl_31;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 6 ("m_ctrl_25")
	pi = self->__commonstate.params + 6;
	pi->name = "ctrl6";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_ctrl_25;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 7 ("m_ctrl_24")
	pi = self->__commonstate.params + 7;
	pi->name = "ctrl7";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_ctrl_24;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 8 ("m_gate_35")
	pi = self->__commonstate.params + 8;
	pi->name = "gate";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_gate_35;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 9 ("m_loopL_33")
	pi = self->__commonstate.params + 9;
	pi->name = "loopL";
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
	// initialize parameter 10 ("m_loopM_36")
	pi = self->__commonstate.params + 10;
	pi->name = "loopM";
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
	// initialize parameter 11 ("m_loopR_30")
	pi = self->__commonstate.params + 11;
	pi->name = "loopR";
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
	// initialize parameter 12 ("m_sw_29")
	pi = self->__commonstate.params + 12;
	pi->name = "sw1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_29;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 13 ("m_sw_23")
	pi = self->__commonstate.params + 13;
	pi->name = "sw2";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_23;
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


} // BenderVersio_2dbeta2::
