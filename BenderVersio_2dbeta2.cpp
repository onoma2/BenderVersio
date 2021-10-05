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
	Data m_loop_27;
	Data m_loop_36;
	Data m_loop_32;
	Delta __m_delta_40;
	Phasor __m_phasor_156;
	Phasor __m_phasor_113;
	Phasor __m_phasor_69;
	PlusEquals __m_pluseq_41;
	int __exception;
	int vectorsize;
	t_sample m_history_7;
	t_sample m_history_1;
	t_sample __m_count_42;
	t_sample m_history_2;
	t_sample __m_slide_37;
	t_sample m_history_3;
	t_sample m_ctrl_35;
	t_sample __m_carry_44;
	t_sample m_sw_33;
	t_sample m_button_34;
	t_sample __m_count_46;
	t_sample __m_carry_48;
	t_sample __m_count_50;
	t_sample samples_to_seconds;
	t_sample samplerate;
	t_sample __m_slide_110;
	t_sample m_history_4;
	t_sample __m_slide_66;
	t_sample __m_slide_57;
	t_sample __m_slide_60;
	t_sample __m_carry_52;
	t_sample __m_slide_54;
	t_sample m_history_6;
	t_sample m_ctrl_31;
	t_sample m_ctrl_29;
	t_sample m_history_14;
	t_sample m_history_13;
	t_sample m_history_15;
	t_sample m_history_16;
	t_sample m_history_17;
	t_sample m_history_12;
	t_sample m_history_10;
	t_sample m_history_11;
	t_sample m_history_8;
	t_sample m_history_9;
	t_sample m_ctrl_30;
	t_sample m_history_18;
	t_sample m_history_20;
	t_sample __m_slide_153;
	t_sample m_history_5;
	t_sample m_ctrl_28;
	t_sample m_history_19;
	t_sample m_sw_25;
	t_sample m_gate_23;
	t_sample m_ctrl_24;
	t_sample m_history_21;
	t_sample m_history_22;
	t_sample m_ctrl_26;
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
		m_gate_23 = ((int)0);
		m_ctrl_24 = ((int)0);
		m_sw_25 = ((int)0);
		m_ctrl_26 = ((int)0);
		m_loop_27.reset("loop1", ((int)96000), ((int)2));
		m_ctrl_28 = ((int)0);
		m_ctrl_29 = ((int)0);
		m_ctrl_30 = ((int)0);
		m_ctrl_31 = ((int)0);
		m_loop_32.reset("loop3", ((int)96000), ((int)2));
		m_sw_33 = ((int)0);
		m_button_34 = ((int)0);
		m_ctrl_35 = ((int)0);
		m_loop_36.reset("loop2", ((int)96000), ((int)2));
		__m_slide_37 = 0;
		__m_delta_40.reset(0);
		__m_pluseq_41.reset(0);
		__m_count_42 = 0;
		__m_carry_44 = 0;
		__m_count_46 = 0;
		__m_carry_48 = 0;
		__m_count_50 = 0;
		__m_carry_52 = 0;
		__m_slide_54 = 0;
		__m_slide_57 = 0;
		__m_slide_60 = 0;
		__m_slide_66 = 0;
		samples_to_seconds = (1 / samplerate);
		__m_phasor_69.reset(0);
		__m_slide_110 = 0;
		__m_phasor_113.reset(0);
		__m_slide_153 = 0;
		__m_phasor_156.reset(0);
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
		int loop2_dim = m_loop_36.dim;
		int loop2_channels = m_loop_36.channels;
		int loop2_dim_161 = loop2_dim;
		int loop3_dim = m_loop_32.dim;
		int loop3_channels = m_loop_32.channels;
		int loop3_dim_159 = loop3_dim;
		int loop1_dim = m_loop_27.dim;
		int loop1_channels = m_loop_27.channels;
		int loop1_dim_169 = loop1_dim;
		t_sample iup_38 = (1 / maximum(1, abs(((int)4000))));
		t_sample idown_39 = (1 / maximum(1, abs(((int)4000))));
		int or_239 = (m_gate_23 || m_button_34);
		int gt_29 = (or_239 > ((int)0));
		int eq_202 = (m_sw_25 == ((int)0));
		t_sample iup_55 = (1 / maximum(1, abs(((int)4000))));
		t_sample idown_56 = (1 / maximum(1, abs(((int)4000))));
		t_sample iup_58 = (1 / maximum(1, abs(((int)4000))));
		t_sample idown_59 = (1 / maximum(1, abs(((int)4000))));
		t_sample iup_61 = (1 / maximum(1, abs(((int)4000))));
		t_sample idown_62 = (1 / maximum(1, abs(((int)4000))));
		int eq_206 = (m_sw_25 == ((t_sample)0.5));
		t_sample switch_205 = (eq_206 ? ((int)0) : m_sw_25);
		t_sample switch_203 = (eq_202 ? ((t_sample)0.5) : switch_205);
		t_sample sub_3411 = (switch_203 - ((int)0));
		t_sample scale_3408 = ((safepow((sub_3411 * ((t_sample)1)), ((int)1)) * ((int)2)) + ((int)1));
		t_sample choice_63 = int(scale_3408);
		t_sample choice_64 = int(scale_3408);
		t_sample choice_65 = int(scale_3408);
		int neq_1 = (scale_3408 != ((int)2));
		t_sample iup_67 = (1 / maximum(1, abs(((int)4000))));
		t_sample idown_68 = (1 / maximum(1, abs(((int)4000))));
		samples_to_seconds = (1 / samplerate);
		bool chan_ignore_80 = ((1 < 0) || (1 >= loop1_channels));
		int min_86 = (-1);
		int min_87 = (-1);
		bool chan_ignore_88 = ((((int)1) < 0) || (((int)1) >= loop1_channels));
		int min_106 = (-1);
		int min_107 = (-1);
		t_sample iup_111 = (1 / maximum(1, abs(((int)4000))));
		t_sample idown_112 = (1 / maximum(1, abs(((int)4000))));
		int min_129 = (-1);
		bool chan_ignore_142 = ((1 < 0) || (1 >= loop3_channels));
		int min_148 = (-1);
		int min_149 = (-1);
		bool chan_ignore_150 = ((((int)1) < 0) || (((int)1) >= loop3_channels));
		t_sample iup_154 = (1 / maximum(1, abs(((int)4000))));
		t_sample idown_155 = (1 / maximum(1, abs(((int)4000))));
		int min_172 = (-1);
		int min_173 = (-1);
		int min_176 = (-1);
		bool chan_ignore_187 = ((1 < 0) || (1 >= loop2_channels));
		int min_193 = (-1);
		int min_194 = (-1);
		bool chan_ignore_195 = ((((int)1) < 0) || (((int)1) >= loop2_channels));
		int min_198 = (-1);
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			const t_sample in2 = (*(__in2++));
			t_sample out7 = ((int)0);
			t_sample mix_3380 = (m_history_22 + (((t_sample)0.0042742627044161) * (m_ctrl_28 - m_history_22)));
			t_sample mix_211 = mix_3380;
			t_sample mix_3381 = (m_history_21 + (((t_sample)0.0042742627044161) * (mix_211 - m_history_21)));
			t_sample mix_209 = mix_3381;
			t_sample mix_3382 = (m_history_20 + (((t_sample)0.0042742627044161) * (mix_209 - m_history_20)));
			t_sample mix_207 = mix_3382;
			t_sample gen_220 = mix_207;
			t_sample history_212_next_214 = fixdenorm(mix_211);
			t_sample history_210_next_215 = fixdenorm(mix_209);
			t_sample history_208_next_216 = fixdenorm(mix_207);
			__m_slide_37 = fixdenorm((__m_slide_37 + (((gen_220 > __m_slide_37) ? iup_38 : idown_39) * (gen_220 - __m_slide_37))));
			t_sample slide_102 = __m_slide_37;
			t_sample fold_20 = fold(in1, (-1), ((int)0));
			t_sample fold_40 = fold(in2, (-1), ((int)0));
			int delta_235 = __m_delta_40(or_239);
			int gtep_234 = ((delta_235 >= ((int)1)) ? delta_235 : 0);
			t_sample plusequals_233 = __m_pluseq_41.post(gtep_234, m_history_19, 0);
			t_sample gen_238 = plusequals_233;
			int eq_231 = (plusequals_233 == ((int)2));
			t_sample history_232_next_236 = fixdenorm(eq_231);
			int gt_26 = (gen_238 > ((int)0));
			__m_count_42 = (((int)0) ? 0 : (fixdenorm(__m_count_42 + ((int)1))));
			int carry_43 = 0;
			if ((((int)0) != 0)) {
				__m_count_42 = 0;
				__m_carry_44 = 0;
				
			} else if (((loop2_dim_161 > 0) && (__m_count_42 >= loop2_dim_161))) {
				int wraps_45 = (__m_count_42 / loop2_dim_161);
				__m_carry_44 = (__m_carry_44 + wraps_45);
				__m_count_42 = (__m_count_42 - (wraps_45 * loop2_dim_161));
				carry_43 = 1;
				
			};
			int counter_156 = __m_count_42;
			int counter_157 = carry_43;
			int counter_158 = __m_carry_44;
			__m_count_46 = (((int)0) ? 0 : (fixdenorm(__m_count_46 + ((int)1))));
			int carry_47 = 0;
			if ((((int)0) != 0)) {
				__m_count_46 = 0;
				__m_carry_48 = 0;
				
			} else if (((loop1_dim_169 > 0) && (__m_count_46 >= loop1_dim_169))) {
				int wraps_49 = (__m_count_46 / loop1_dim_169);
				__m_carry_48 = (__m_carry_48 + wraps_49);
				__m_count_46 = (__m_count_46 - (wraps_49 * loop1_dim_169));
				carry_47 = 1;
				
			};
			int counter_164 = __m_count_46;
			int counter_165 = carry_47;
			int counter_166 = __m_carry_48;
			__m_count_50 = (((int)0) ? 0 : (fixdenorm(__m_count_50 + ((int)1))));
			int carry_51 = 0;
			if ((((int)0) != 0)) {
				__m_count_50 = 0;
				__m_carry_52 = 0;
				
			} else if (((loop3_dim_159 > 0) && (__m_count_50 >= loop3_dim_159))) {
				int wraps_53 = (__m_count_50 / loop3_dim_159);
				__m_carry_52 = (__m_carry_52 + wraps_53);
				__m_count_50 = (__m_count_50 - (wraps_53 * loop3_dim_159));
				carry_51 = 1;
				
			};
			int counter_152 = __m_count_50;
			int counter_153 = carry_51;
			int counter_154 = __m_carry_52;
			t_sample abs_22 = fabs(in1);
			t_sample add_21 = (abs_22 + ((t_sample)0.0001));
			t_sample rsub_24 = (((int)1) - add_21);
			t_sample abs_44 = fabs(in2);
			t_sample add_43 = (abs_44 + ((t_sample)0.0001));
			t_sample rsub_46 = (((int)1) - add_43);
			t_sample mix_3383 = (m_history_18 + (((t_sample)0.0042742627044161) * (m_ctrl_35 - m_history_18)));
			t_sample mix_3140 = mix_3383;
			t_sample mix_3384 = (m_history_17 + (((t_sample)0.0042742627044161) * (mix_3140 - m_history_17)));
			t_sample mix_3143 = mix_3384;
			t_sample mix_3385 = (m_history_16 + (((t_sample)0.0042742627044161) * (mix_3143 - m_history_16)));
			t_sample mix_3145 = mix_3385;
			t_sample gen_223 = mix_3145;
			t_sample history_212_next_3144 = fixdenorm(mix_3140);
			t_sample history_210_next_3147 = fixdenorm(mix_3143);
			t_sample history_208_next_3139 = fixdenorm(mix_3145);
			t_sample mix_3386 = (m_history_15 + (((t_sample)0.0042742627044161) * (m_ctrl_29 - m_history_15)));
			t_sample mix_3153 = mix_3386;
			t_sample mix_3387 = (m_history_14 + (((t_sample)0.0042742627044161) * (mix_3153 - m_history_14)));
			t_sample mix_3156 = mix_3387;
			t_sample mix_3388 = (m_history_13 + (((t_sample)0.0042742627044161) * (mix_3156 - m_history_13)));
			t_sample mix_3158 = mix_3388;
			t_sample gen_217 = mix_3158;
			t_sample history_212_next_3157 = fixdenorm(mix_3153);
			t_sample history_210_next_3160 = fixdenorm(mix_3156);
			t_sample history_208_next_3152 = fixdenorm(mix_3158);
			t_sample mix_3389 = (m_history_12 + (((t_sample)0.0042742627044161) * (m_ctrl_31 - m_history_12)));
			t_sample mix_3166 = mix_3389;
			t_sample mix_3390 = (m_history_11 + (((t_sample)0.0042742627044161) * (mix_3166 - m_history_11)));
			t_sample mix_3170 = mix_3390;
			t_sample mix_3391 = (m_history_10 + (((t_sample)0.0042742627044161) * (mix_3170 - m_history_10)));
			t_sample mix_3172 = mix_3391;
			t_sample gen_218 = mix_3172;
			t_sample history_212_next_3171 = fixdenorm(mix_3166);
			t_sample history_210_next_3173 = fixdenorm(mix_3170);
			t_sample history_208_next_3165 = fixdenorm(mix_3172);
			t_sample sub_3395 = (gen_218 - ((int)0));
			t_sample scale_3392 = ((safepow((sub_3395 * ((t_sample)1)), ((int)1)) * ((int)2)) + (-1));
			t_sample gtep_90 = ((scale_3392 >= ((int)0)) ? scale_3392 : 0);
			__m_slide_54 = fixdenorm((__m_slide_54 + (((gtep_90 > __m_slide_54) ? iup_55 : idown_56) * (gtep_90 - __m_slide_54))));
			t_sample slide_87 = __m_slide_54;
			t_sample out10 = slide_87;
			t_sample ceil_5 = ceil(slide_87);
			t_sample sub_3399 = (gen_218 - ((int)0));
			t_sample scale_3396 = ((safepow((sub_3399 * ((t_sample)1)), ((int)1)) * ((int)2)) + (-1));
			t_sample abs_95 = fabs(scale_3396);
			t_sample sub_3403 = (abs_95 - ((int)1));
			t_sample scale_3400 = ((safepow((sub_3403 * ((t_sample)-1)), ((int)1)) * ((int)1)) + ((int)0));
			__m_slide_57 = fixdenorm((__m_slide_57 + (((scale_3400 > __m_slide_57) ? iup_58 : idown_59) * (scale_3400 - __m_slide_57))));
			t_sample slide_88 = __m_slide_57;
			t_sample out9 = slide_88;
			t_sample ceil_6 = ceil(slide_88);
			t_sample sub_3407 = (gen_218 - ((int)0));
			t_sample scale_3404 = ((safepow((sub_3407 * ((t_sample)1)), ((int)1)) * ((int)2)) + (-1));
			t_sample ltep_92 = ((scale_3404 <= ((int)0)) ? scale_3404 : 0);
			t_sample abs_93 = fabs(ltep_92);
			__m_slide_60 = fixdenorm((__m_slide_60 + (((abs_93 > __m_slide_60) ? iup_61 : idown_62) * (abs_93 - __m_slide_60))));
			t_sample slide_89 = __m_slide_60;
			t_sample ceil_7 = ceil(slide_89);
			t_sample selector_77 = ((choice_63 >= 3) ? gt_26 : ((choice_63 >= 2) ? ((int)1) : ((choice_63 >= 1) ? gt_29 : 0)));
			t_sample selector_23 = ((choice_64 >= 3) ? gt_26 : ((choice_64 >= 2) ? ((int)1) : ((choice_64 >= 1) ? gt_29 : 0)));
			t_sample switch_25 = (selector_23 ? rsub_24 : fold_20);
			t_sample out3 = switch_25;
			t_sample selector_45 = ((choice_65 >= 3) ? gt_26 : ((choice_65 >= 2) ? ((int)1) : ((choice_65 >= 1) ? gt_29 : 0)));
			t_sample switch_47 = (selector_45 ? rsub_46 : fold_40);
			t_sample out4 = switch_47;
			t_sample switch_12 = (neq_1 ? ceil_6 : ((int)1));
			t_sample mul_13 = (switch_12 * counter_156);
			t_sample switch_74 = (selector_77 ? mul_13 : ((int)0));
			t_sample mul_11 = (switch_12 * counter_156);
			t_sample switch_73 = (selector_77 ? mul_11 : ((int)0));
			t_sample switch_15 = (neq_1 ? ceil_7 : ((int)1));
			t_sample mul_14 = (switch_15 * counter_164);
			t_sample switch_76 = (selector_77 ? mul_14 : ((int)0));
			t_sample mul_16 = (switch_15 * counter_164);
			t_sample switch_78 = (selector_77 ? mul_16 : ((int)0));
			t_sample switch_10 = (neq_1 ? ceil_5 : ((int)1));
			t_sample mul_8 = (counter_152 * switch_10);
			t_sample switch_72 = (selector_77 ? mul_8 : ((int)0));
			t_sample mul_9 = (counter_152 * switch_10);
			t_sample switch_75 = (selector_77 ? mul_9 : ((int)0));
			t_sample mix_3412 = (m_history_9 + (((t_sample)0.0042742627044161) * (m_ctrl_26 - m_history_9)));
			t_sample mix_3181 = mix_3412;
			t_sample mix_3413 = (m_history_8 + (((t_sample)0.0042742627044161) * (mix_3181 - m_history_8)));
			t_sample mix_3183 = mix_3413;
			t_sample mix_3414 = (m_history_7 + (((t_sample)0.0042742627044161) * (mix_3183 - m_history_7)));
			t_sample mix_3182 = mix_3414;
			t_sample gen_221 = mix_3182;
			t_sample history_212_next_3184 = fixdenorm(mix_3181);
			t_sample history_210_next_3186 = fixdenorm(mix_3183);
			t_sample history_208_next_3180 = fixdenorm(mix_3182);
			t_sample sub_3418 = (gen_221 - ((int)0));
			t_sample scale_3415 = ((safepow((sub_3418 * ((t_sample)1)), ((int)1)) * ((int)2)) + (-1));
			t_sample abs_50 = fabs(scale_3415);
			t_sample sub_3422 = (abs_50 - ((int)1));
			t_sample scale_3419 = ((safepow((sub_3422 * ((t_sample)-1)), ((int)1)) * ((t_sample)7.5)) + ((t_sample)0.5));
			__m_slide_66 = fixdenorm((__m_slide_66 + (((scale_3419 > __m_slide_66) ? iup_67 : idown_68) * (scale_3419 - __m_slide_66))));
			t_sample slide_48 = __m_slide_66;
			t_sample rdiv_190 = safediv(((int)1), slide_48);
			t_sample NL_225 = (rdiv_190 + slide_89);
			t_sample out8 = NL_225;
			t_sample phasor_191 = __m_phasor_69(rdiv_190, samples_to_seconds);
			t_sample mul_179 = (phasor_191 * ((int)2));
			t_sample sub_178 = (mul_179 - ((int)1));
			t_sample cos_177 = cos(sub_178);
			t_sample sub_176 = (cos_177 - ((t_sample)0.5));
			t_sample mul_175 = (sub_176 * ((int)10));
			t_sample clamp_174 = ((mul_175 <= ((int)0)) ? ((int)0) : ((mul_175 >= ((int)1)) ? ((int)1) : mul_175));
			t_sample fold_181 = fold(phasor_191, ((int)0), ((int)1));
			double sample_index_70 = (fold_181 * (loop1_dim - 1));
			int index_trunc_71 = fixnan(floor(sample_index_70));
			double index_fract_72 = (sample_index_70 - index_trunc_71);
			int index_trunc_73 = (index_trunc_71 - 1);
			int index_trunc_74 = (index_trunc_71 + 1);
			int index_trunc_75 = (index_trunc_71 + 2);
			bool index_ignore_76 = ((index_trunc_73 >= loop1_dim) || (index_trunc_73 < 0));
			bool index_ignore_77 = ((index_trunc_71 >= loop1_dim) || (index_trunc_71 < 0));
			bool index_ignore_78 = ((index_trunc_74 >= loop1_dim) || (index_trunc_74 < 0));
			bool index_ignore_79 = ((index_trunc_75 >= loop1_dim) || (index_trunc_75 < 0));
			// phase loop1 channel 1;
			double read_loop_81 = ((chan_ignore_80 || index_ignore_76) ? 0 : m_loop_27.read(index_trunc_73, 1));
			double read_loop_82 = ((chan_ignore_80 || index_ignore_77) ? 0 : m_loop_27.read(index_trunc_71, 1));
			double read_loop_83 = ((chan_ignore_80 || index_ignore_78) ? 0 : m_loop_27.read(index_trunc_74, 1));
			double read_loop_84 = ((chan_ignore_80 || index_ignore_79) ? 0 : m_loop_27.read(index_trunc_75, 1));
			double readinterp_85 = spline_interp(index_fract_72, read_loop_81, read_loop_82, read_loop_83, read_loop_84);
			t_sample sample_loop_185 = readinterp_85;
			t_sample index_loop_186 = sample_index_70;
			t_sample mul_173 = (sample_loop_185 * clamp_174);
			t_sample mix_3423 = (in2 + (gen_217 * (mul_173 - in2)));
			t_sample clamp_58 = ((mix_3423 <= min_86) ? min_86 : ((mix_3423 >= ((int)1)) ? ((int)1) : mix_3423));
			t_sample mul_83 = (clamp_58 * slide_89);
			t_sample clamp_61 = ((mul_83 <= min_87) ? min_87 : ((mul_83 >= ((int)1)) ? ((int)1) : mul_83));
			int index_trunc_89 = fixnan(floor(switch_76));
			int index_wrap_90 = ((index_trunc_89 < 0) ? ((loop1_dim - 1) + ((index_trunc_89 + 1) % loop1_dim)) : (index_trunc_89 % loop1_dim));
			if ((!chan_ignore_88)) {
				m_loop_27.write((clamp_61 + (m_loop_27.read(index_wrap_90, ((int)1)) * slide_102)), index_wrap_90, ((int)1));
				
			};
			double sample_index_91 = (fold_181 * (loop1_dim - 1));
			int index_trunc_92 = fixnan(floor(sample_index_91));
			double index_fract_93 = (sample_index_91 - index_trunc_92);
			int index_trunc_94 = (index_trunc_92 - 1);
			int index_trunc_95 = (index_trunc_92 + 1);
			int index_trunc_96 = (index_trunc_92 + 2);
			bool index_ignore_97 = ((index_trunc_94 >= loop1_dim) || (index_trunc_94 < 0));
			bool index_ignore_98 = ((index_trunc_92 >= loop1_dim) || (index_trunc_92 < 0));
			bool index_ignore_99 = ((index_trunc_95 >= loop1_dim) || (index_trunc_95 < 0));
			bool index_ignore_100 = ((index_trunc_96 >= loop1_dim) || (index_trunc_96 < 0));
			// phase loop1 channel 1;
			double read_loop_101 = (index_ignore_97 ? 0 : m_loop_27.read(index_trunc_94, 0));
			double read_loop_102 = (index_ignore_98 ? 0 : m_loop_27.read(index_trunc_92, 0));
			double read_loop_103 = (index_ignore_99 ? 0 : m_loop_27.read(index_trunc_95, 0));
			double read_loop_104 = (index_ignore_100 ? 0 : m_loop_27.read(index_trunc_96, 0));
			double readinterp_105 = spline_interp(index_fract_93, read_loop_101, read_loop_102, read_loop_103, read_loop_104);
			t_sample sample_loop_187 = readinterp_105;
			t_sample index_loop_188 = sample_index_91;
			t_sample mul_172 = (sample_loop_187 * clamp_174);
			t_sample mix_3424 = (in1 + (gen_217 * (mul_172 - in1)));
			t_sample clamp_67 = ((mix_3424 <= min_106) ? min_106 : ((mix_3424 >= ((int)1)) ? ((int)1) : mix_3424));
			t_sample mul_86 = (clamp_67 * slide_89);
			t_sample clamp_64 = ((mul_86 <= min_107) ? min_107 : ((mul_86 >= ((int)1)) ? ((int)1) : mul_86));
			int index_trunc_108 = fixnan(floor(switch_78));
			int index_wrap_109 = ((index_trunc_108 < 0) ? ((loop1_dim - 1) + ((index_trunc_108 + 1) % loop1_dim)) : (index_trunc_108 % loop1_dim));
			m_loop_27.write((clamp_64 + (m_loop_27.read(index_wrap_109, 0) * slide_102)), index_wrap_109, 0);
			t_sample mix_3425 = (m_history_6 + (((t_sample)0.0042742627044161) * (m_ctrl_24 - m_history_6)));
			t_sample mix_3193 = mix_3425;
			t_sample mix_3426 = (m_history_5 + (((t_sample)0.0042742627044161) * (mix_3193 - m_history_5)));
			t_sample mix_3196 = mix_3426;
			t_sample mix_3427 = (m_history_4 + (((t_sample)0.0042742627044161) * (mix_3196 - m_history_4)));
			t_sample mix_3195 = mix_3427;
			t_sample gen_219 = mix_3195;
			t_sample history_212_next_3197 = fixdenorm(mix_3193);
			t_sample history_210_next_3199 = fixdenorm(mix_3196);
			t_sample history_208_next_3192 = fixdenorm(mix_3195);
			t_sample sub_3431 = (gen_219 - ((int)0));
			t_sample scale_3428 = ((safepow((sub_3431 * ((t_sample)1)), ((int)1)) * ((int)2)) + (-1));
			t_sample abs_34 = fabs(scale_3428);
			t_sample sub_3435 = (abs_34 - ((int)1));
			t_sample scale_3432 = ((safepow((sub_3435 * ((t_sample)-1)), ((int)1)) * ((t_sample)7.5)) + ((t_sample)0.5));
			__m_slide_110 = fixdenorm((__m_slide_110 + (((scale_3432 > __m_slide_110) ? iup_111 : idown_112) * (scale_3432 - __m_slide_110))));
			t_sample slide_32 = __m_slide_110;
			t_sample rdiv_122 = safediv(((int)1), slide_32);
			t_sample phasor_123 = __m_phasor_113(rdiv_122, samples_to_seconds);
			t_sample mul_120 = (phasor_123 * ((int)2));
			t_sample sub_119 = (mul_120 - ((int)1));
			t_sample cos_118 = cos(sub_119);
			t_sample sub_117 = (cos_118 - ((t_sample)0.5));
			t_sample mul_116 = (sub_117 * ((int)10));
			t_sample clamp_115 = ((mul_116 <= ((int)0)) ? ((int)0) : ((mul_116 >= ((int)1)) ? ((int)1) : mul_116));
			t_sample fold_108 = fold(phasor_123, ((int)0), ((int)1));
			double sample_index_114 = (fold_108 * (loop3_dim - 1));
			int index_trunc_115 = fixnan(floor(sample_index_114));
			double index_fract_116 = (sample_index_114 - index_trunc_115);
			int index_trunc_117 = (index_trunc_115 - 1);
			int index_trunc_118 = (index_trunc_115 + 1);
			int index_trunc_119 = (index_trunc_115 + 2);
			bool index_ignore_120 = ((index_trunc_117 >= loop3_dim) || (index_trunc_117 < 0));
			bool index_ignore_121 = ((index_trunc_115 >= loop3_dim) || (index_trunc_115 < 0));
			bool index_ignore_122 = ((index_trunc_118 >= loop3_dim) || (index_trunc_118 < 0));
			bool index_ignore_123 = ((index_trunc_119 >= loop3_dim) || (index_trunc_119 < 0));
			// phase loop3 channel 1;
			double read_loop_124 = (index_ignore_120 ? 0 : m_loop_32.read(index_trunc_117, 0));
			double read_loop_125 = (index_ignore_121 ? 0 : m_loop_32.read(index_trunc_115, 0));
			double read_loop_126 = (index_ignore_122 ? 0 : m_loop_32.read(index_trunc_118, 0));
			double read_loop_127 = (index_ignore_123 ? 0 : m_loop_32.read(index_trunc_119, 0));
			double readinterp_128 = spline_interp(index_fract_116, read_loop_124, read_loop_125, read_loop_126, read_loop_127);
			t_sample sample_loop_113 = readinterp_128;
			t_sample index_loop_114 = sample_index_114;
			t_sample mul_107 = (sample_loop_113 * clamp_115);
			t_sample mix_3436 = (in1 + (gen_217 * (mul_107 - in1)));
			t_sample mul_84 = (mix_3436 * slide_87);
			t_sample clamp_62 = ((mul_84 <= min_129) ? min_129 : ((mul_84 >= ((int)1)) ? ((int)1) : mul_84));
			int index_trunc_130 = fixnan(floor(switch_75));
			int index_wrap_131 = ((index_trunc_130 < 0) ? ((loop3_dim - 1) + ((index_trunc_130 + 1) % loop3_dim)) : (index_trunc_130 % loop3_dim));
			m_loop_32.write((clamp_62 + (m_loop_32.read(index_wrap_131, 0) * slide_102)), index_wrap_131, 0);
			double sample_index_132 = (fold_108 * (loop3_dim - 1));
			int index_trunc_133 = fixnan(floor(sample_index_132));
			double index_fract_134 = (sample_index_132 - index_trunc_133);
			int index_trunc_135 = (index_trunc_133 - 1);
			int index_trunc_136 = (index_trunc_133 + 1);
			int index_trunc_137 = (index_trunc_133 + 2);
			bool index_ignore_138 = ((index_trunc_135 >= loop3_dim) || (index_trunc_135 < 0));
			bool index_ignore_139 = ((index_trunc_133 >= loop3_dim) || (index_trunc_133 < 0));
			bool index_ignore_140 = ((index_trunc_136 >= loop3_dim) || (index_trunc_136 < 0));
			bool index_ignore_141 = ((index_trunc_137 >= loop3_dim) || (index_trunc_137 < 0));
			// phase loop3 channel 1;
			double read_loop_143 = ((chan_ignore_142 || index_ignore_138) ? 0 : m_loop_32.read(index_trunc_135, 1));
			double read_loop_144 = ((chan_ignore_142 || index_ignore_139) ? 0 : m_loop_32.read(index_trunc_133, 1));
			double read_loop_145 = ((chan_ignore_142 || index_ignore_140) ? 0 : m_loop_32.read(index_trunc_136, 1));
			double read_loop_146 = ((chan_ignore_142 || index_ignore_141) ? 0 : m_loop_32.read(index_trunc_137, 1));
			double readinterp_147 = spline_interp(index_fract_134, read_loop_143, read_loop_144, read_loop_145, read_loop_146);
			t_sample sample_loop_111 = readinterp_147;
			t_sample index_loop_112 = sample_index_132;
			t_sample mul_106 = (sample_loop_111 * clamp_115);
			t_sample mix_3437 = (in2 + (gen_217 * (mul_106 - in2)));
			t_sample clamp_54 = ((mix_3437 <= min_148) ? min_148 : ((mix_3437 >= ((int)1)) ? ((int)1) : mix_3437));
			t_sample mul_81 = (clamp_54 * slide_87);
			t_sample clamp_59 = ((mul_81 <= min_149) ? min_149 : ((mul_81 >= ((int)1)) ? ((int)1) : mul_81));
			int index_trunc_151 = fixnan(floor(switch_72));
			int index_wrap_152 = ((index_trunc_151 < 0) ? ((loop3_dim - 1) + ((index_trunc_151 + 1) % loop3_dim)) : (index_trunc_151 % loop3_dim));
			if ((!chan_ignore_150)) {
				m_loop_32.write((clamp_59 + (m_loop_32.read(index_wrap_152, ((int)1)) * slide_102)), index_wrap_152, ((int)1));
				
			};
			t_sample mix_3438 = (m_history_3 + (((t_sample)0.0042742627044161) * (m_ctrl_30 - m_history_3)));
			t_sample mix_3208 = mix_3438;
			t_sample mix_3439 = (m_history_2 + (((t_sample)0.0042742627044161) * (mix_3208 - m_history_2)));
			t_sample mix_3210 = mix_3439;
			t_sample mix_3440 = (m_history_1 + (((t_sample)0.0042742627044161) * (mix_3210 - m_history_1)));
			t_sample mix_3209 = mix_3440;
			t_sample gen_222 = mix_3209;
			t_sample history_212_next_3211 = fixdenorm(mix_3208);
			t_sample history_210_next_3212 = fixdenorm(mix_3210);
			t_sample history_208_next_3207 = fixdenorm(mix_3209);
			t_sample sub_3444 = (gen_222 - ((int)0));
			t_sample scale_3441 = ((safepow((sub_3444 * ((t_sample)1)), ((int)1)) * ((int)2)) + (-1));
			t_sample abs_38 = fabs(scale_3441);
			t_sample sub_3448 = (abs_38 - ((int)1));
			t_sample scale_3445 = ((safepow((sub_3448 * ((t_sample)-1)), ((int)1)) * ((t_sample)7.5)) + ((t_sample)0.5));
			__m_slide_153 = fixdenorm((__m_slide_153 + (((scale_3445 > __m_slide_153) ? iup_154 : idown_155) * (scale_3445 - __m_slide_153))));
			t_sample slide_36 = __m_slide_153;
			t_sample rdiv_143 = safediv(((int)1), slide_36);
			t_sample phasor_144 = __m_phasor_156(rdiv_143, samples_to_seconds);
			t_sample mul_141 = (phasor_144 * ((int)2));
			t_sample sub_140 = (mul_141 - ((int)1));
			t_sample cos_139 = cos(sub_140);
			t_sample sub_138 = (cos_139 - ((t_sample)0.5));
			t_sample mul_137 = (sub_138 * ((int)10));
			t_sample clamp_136 = ((mul_137 <= ((int)0)) ? ((int)0) : ((mul_137 >= ((int)1)) ? ((int)1) : mul_137));
			t_sample fold_129 = fold(phasor_144, ((int)0), ((int)1));
			double sample_index_157 = (fold_129 * (loop2_dim - 1));
			int index_trunc_158 = fixnan(floor(sample_index_157));
			double index_fract_159 = (sample_index_157 - index_trunc_158);
			int index_trunc_160 = (index_trunc_158 - 1);
			int index_trunc_161 = (index_trunc_158 + 1);
			int index_trunc_162 = (index_trunc_158 + 2);
			bool index_ignore_163 = ((index_trunc_160 >= loop2_dim) || (index_trunc_160 < 0));
			bool index_ignore_164 = ((index_trunc_158 >= loop2_dim) || (index_trunc_158 < 0));
			bool index_ignore_165 = ((index_trunc_161 >= loop2_dim) || (index_trunc_161 < 0));
			bool index_ignore_166 = ((index_trunc_162 >= loop2_dim) || (index_trunc_162 < 0));
			// phase loop2 channel 1;
			double read_loop_167 = (index_ignore_163 ? 0 : m_loop_36.read(index_trunc_160, 0));
			double read_loop_168 = (index_ignore_164 ? 0 : m_loop_36.read(index_trunc_158, 0));
			double read_loop_169 = (index_ignore_165 ? 0 : m_loop_36.read(index_trunc_161, 0));
			double read_loop_170 = (index_ignore_166 ? 0 : m_loop_36.read(index_trunc_162, 0));
			double readinterp_171 = spline_interp(index_fract_159, read_loop_167, read_loop_168, read_loop_169, read_loop_170);
			t_sample sample_loop_134 = readinterp_171;
			t_sample index_loop_135 = sample_index_157;
			t_sample mul_128 = (sample_loop_134 * clamp_136);
			t_sample mix_3449 = (in1 + (gen_217 * (mul_128 - in1)));
			t_sample clamp_66 = ((mix_3449 <= min_172) ? min_172 : ((mix_3449 >= ((int)1)) ? ((int)1) : mix_3449));
			t_sample mul_85 = (clamp_66 * slide_88);
			t_sample clamp_63 = ((mul_85 <= min_173) ? min_173 : ((mul_85 >= ((int)1)) ? ((int)1) : mul_85));
			int index_trunc_174 = fixnan(floor(switch_74));
			int index_wrap_175 = ((index_trunc_174 < 0) ? ((loop2_dim - 1) + ((index_trunc_174 + 1) % loop2_dim)) : (index_trunc_174 % loop2_dim));
			m_loop_36.write((clamp_63 + (m_loop_36.read(index_wrap_175, 0) * slide_102)), index_wrap_175, 0);
			t_sample mix_3450 = (mul_172 + (((t_sample)0.5) * (mul_128 - mul_172)));
			t_sample mix_3451 = (mix_3450 + (((t_sample)0.66) * (mul_107 - mix_3450)));
			t_sample mul_80 = (mix_3451 * ((int)4));
			t_sample mix_3452 = (in1 + (gen_223 * (mul_80 - in1)));
			t_sample clamp_100 = ((mix_3452 <= min_176) ? min_176 : ((mix_3452 >= ((int)1)) ? ((int)1) : mix_3452));
			t_sample out1 = clamp_100;
			t_sample fold_42 = fold(clamp_100, (-1), ((int)0));
			t_sample out5 = fold_42;
			double sample_index_177 = (fold_129 * (loop2_dim - 1));
			int index_trunc_178 = fixnan(floor(sample_index_177));
			double index_fract_179 = (sample_index_177 - index_trunc_178);
			int index_trunc_180 = (index_trunc_178 - 1);
			int index_trunc_181 = (index_trunc_178 + 1);
			int index_trunc_182 = (index_trunc_178 + 2);
			bool index_ignore_183 = ((index_trunc_180 >= loop2_dim) || (index_trunc_180 < 0));
			bool index_ignore_184 = ((index_trunc_178 >= loop2_dim) || (index_trunc_178 < 0));
			bool index_ignore_185 = ((index_trunc_181 >= loop2_dim) || (index_trunc_181 < 0));
			bool index_ignore_186 = ((index_trunc_182 >= loop2_dim) || (index_trunc_182 < 0));
			// phase loop2 channel 1;
			double read_loop_188 = ((chan_ignore_187 || index_ignore_183) ? 0 : m_loop_36.read(index_trunc_180, 1));
			double read_loop_189 = ((chan_ignore_187 || index_ignore_184) ? 0 : m_loop_36.read(index_trunc_178, 1));
			double read_loop_190 = ((chan_ignore_187 || index_ignore_185) ? 0 : m_loop_36.read(index_trunc_181, 1));
			double read_loop_191 = ((chan_ignore_187 || index_ignore_186) ? 0 : m_loop_36.read(index_trunc_182, 1));
			double readinterp_192 = spline_interp(index_fract_179, read_loop_188, read_loop_189, read_loop_190, read_loop_191);
			t_sample sample_loop_132 = readinterp_192;
			t_sample index_loop_133 = sample_index_177;
			t_sample mul_127 = (sample_loop_132 * clamp_136);
			t_sample mix_3453 = (in2 + (gen_217 * (mul_127 - in2)));
			t_sample clamp_56 = ((mix_3453 <= min_193) ? min_193 : ((mix_3453 >= ((int)1)) ? ((int)1) : mix_3453));
			t_sample mul_82 = (clamp_56 * slide_88);
			t_sample clamp_60 = ((mul_82 <= min_194) ? min_194 : ((mul_82 >= ((int)1)) ? ((int)1) : mul_82));
			int index_trunc_196 = fixnan(floor(switch_73));
			int index_wrap_197 = ((index_trunc_196 < 0) ? ((loop2_dim - 1) + ((index_trunc_196 + 1) % loop2_dim)) : (index_trunc_196 % loop2_dim));
			if ((!chan_ignore_195)) {
				m_loop_36.write((clamp_60 + (m_loop_36.read(index_wrap_197, ((int)1)) * slide_102)), index_wrap_197, ((int)1));
				
			};
			t_sample mix_3454 = (mul_173 + (((t_sample)0.5) * (mul_127 - mul_173)));
			t_sample mix_3455 = (mix_3454 + (((t_sample)0.66) * (mul_106 - mix_3454)));
			t_sample mul_79 = (mix_3455 * ((int)4));
			t_sample mix_3456 = (in2 + (gen_223 * (mul_79 - in2)));
			t_sample clamp_99 = ((mix_3456 <= min_198) ? min_198 : ((mix_3456 >= ((int)1)) ? ((int)1) : mix_3456));
			t_sample out2 = clamp_99;
			t_sample fold_41 = fold(clamp_99, (-1), ((int)0));
			t_sample out6 = fold_41;
			m_history_22 = history_212_next_214;
			m_history_20 = history_208_next_216;
			m_history_21 = history_210_next_215;
			m_history_19 = history_232_next_236;
			m_history_18 = history_212_next_3144;
			m_history_16 = history_208_next_3139;
			m_history_17 = history_210_next_3147;
			m_history_15 = history_212_next_3157;
			m_history_13 = history_208_next_3152;
			m_history_14 = history_210_next_3160;
			m_history_12 = history_212_next_3171;
			m_history_10 = history_208_next_3165;
			m_history_11 = history_210_next_3173;
			m_history_9 = history_212_next_3184;
			m_history_7 = history_208_next_3180;
			m_history_8 = history_210_next_3186;
			m_history_6 = history_212_next_3197;
			m_history_4 = history_208_next_3192;
			m_history_5 = history_210_next_3199;
			m_history_3 = history_212_next_3211;
			m_history_1 = history_208_next_3207;
			m_history_2 = history_210_next_3212;
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
	inline void set_gate(t_param _value) {
		m_gate_23 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_ctrl6(t_param _value) {
		m_ctrl_24 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw1(t_param _value) {
		m_sw_25 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_ctrl3(t_param _value) {
		m_ctrl_26 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_loop1(void * _value) {
		m_loop_27.setbuffer(_value);
	};
	inline void set_ctrl2(t_param _value) {
		m_ctrl_28 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_ctrl7(t_param _value) {
		m_ctrl_29 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_ctrl5(t_param _value) {
		m_ctrl_30 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_ctrl4(t_param _value) {
		m_ctrl_31 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_loop3(void * _value) {
		m_loop_32.setbuffer(_value);
	};
	inline void set_sw2(t_param _value) {
		m_sw_33 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_button(t_param _value) {
		m_button_34 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_ctrl1(t_param _value) {
		m_ctrl_35 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_loop2(void * _value) {
		m_loop_36.setbuffer(_value);
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
		case 9: self->set_loop1(ref); break;
		case 10: self->set_loop2(ref); break;
		case 11: self->set_loop3(ref); break;
		case 12: self->set_sw1(value); break;
		case 13: self->set_sw2(value); break;
		
		default: break;
	}
}

/// Get the value of a parameter of a State object

void getparameter(CommonState *cself, long index, t_param *value) {
	State *self = (State *)cself;
	switch (index) {
		case 0: *value = self->m_button_34; break;
		case 1: *value = self->m_ctrl_35; break;
		case 2: *value = self->m_ctrl_28; break;
		case 3: *value = self->m_ctrl_26; break;
		case 4: *value = self->m_ctrl_31; break;
		case 5: *value = self->m_ctrl_30; break;
		case 6: *value = self->m_ctrl_24; break;
		case 7: *value = self->m_ctrl_29; break;
		case 8: *value = self->m_gate_23; break;
		
		
		
		case 12: *value = self->m_sw_25; break;
		case 13: *value = self->m_sw_33; break;
		
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
	// initialize parameter 0 ("m_button_34")
	pi = self->__commonstate.params + 0;
	pi->name = "button";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_button_34;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 1 ("m_ctrl_35")
	pi = self->__commonstate.params + 1;
	pi->name = "ctrl1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_ctrl_35;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_ctrl_28")
	pi = self->__commonstate.params + 2;
	pi->name = "ctrl2";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_ctrl_28;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 3 ("m_ctrl_26")
	pi = self->__commonstate.params + 3;
	pi->name = "ctrl3";
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
	// initialize parameter 4 ("m_ctrl_31")
	pi = self->__commonstate.params + 4;
	pi->name = "ctrl4";
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
	// initialize parameter 5 ("m_ctrl_30")
	pi = self->__commonstate.params + 5;
	pi->name = "ctrl5";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_ctrl_30;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 6 ("m_ctrl_24")
	pi = self->__commonstate.params + 6;
	pi->name = "ctrl6";
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
	// initialize parameter 7 ("m_ctrl_29")
	pi = self->__commonstate.params + 7;
	pi->name = "ctrl7";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_ctrl_29;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 8 ("m_gate_23")
	pi = self->__commonstate.params + 8;
	pi->name = "gate";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_gate_23;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 9 ("m_loop_27")
	pi = self->__commonstate.params + 9;
	pi->name = "loop1";
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
	// initialize parameter 10 ("m_loop_36")
	pi = self->__commonstate.params + 10;
	pi->name = "loop2";
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
	// initialize parameter 11 ("m_loop_32")
	pi = self->__commonstate.params + 11;
	pi->name = "loop3";
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
	// initialize parameter 12 ("m_sw_25")
	pi = self->__commonstate.params + 12;
	pi->name = "sw1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_25;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 13 ("m_sw_33")
	pi = self->__commonstate.params + 13;
	pi->name = "sw2";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_33;
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
