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
	Data m_loop_32;
	Data m_loop_36;
	Data m_loop_33;
	Delta __m_delta_40;
	Phasor __m_phasor_156;
	Phasor __m_phasor_112;
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
	t_sample m_history_4;
	t_sample m_ctrl_34;
	t_sample __m_count_46;
	t_sample __m_carry_48;
	t_sample __m_count_50;
	t_sample samples_to_seconds;
	t_sample samplerate;
	t_sample __m_slide_109;
	t_sample m_history_5;
	t_sample __m_slide_66;
	t_sample __m_slide_57;
	t_sample __m_slide_60;
	t_sample __m_carry_52;
	t_sample __m_slide_54;
	t_sample m_history_6;
	t_sample m_sw_31;
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
	t_sample m_button_30;
	t_sample m_history_18;
	t_sample m_history_20;
	t_sample __m_slide_153;
	t_sample m_ctrl_27;
	t_sample m_ctrl_28;
	t_sample m_history_19;
	t_sample m_ctrl_25;
	t_sample m_sw_23;
	t_sample m_gate_24;
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
		m_sw_23 = ((int)0);
		m_gate_24 = ((int)0);
		m_ctrl_25 = ((int)0);
		m_ctrl_26 = ((int)0);
		m_ctrl_27 = ((int)0);
		m_ctrl_28 = ((int)0);
		m_ctrl_29 = ((int)0);
		m_button_30 = ((int)0);
		m_sw_31 = ((int)0);
		m_loop_32.reset("loop1", ((int)96000), ((int)2));
		m_loop_33.reset("loop2", ((int)96000), ((int)2));
		m_ctrl_34 = ((int)0);
		m_ctrl_35 = ((int)0);
		m_loop_36.reset("loop3", ((int)96000), ((int)2));
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
		__m_slide_109 = 0;
		__m_phasor_112.reset(0);
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
		int loop3_dim = m_loop_36.dim;
		int loop3_channels = m_loop_36.channels;
		int loop3_dim_8098 = loop3_dim;
		int loop2_dim = m_loop_33.dim;
		int loop2_channels = m_loop_33.channels;
		int loop2_dim_152 = loop2_dim;
		int loop1_dim = m_loop_32.dim;
		int loop1_channels = m_loop_32.channels;
		int loop1_dim_7932 = loop1_dim;
		t_sample iup_38 = (1 / maximum(1, abs(((int)4000))));
		t_sample idown_39 = (1 / maximum(1, abs(((int)4000))));
		int or_230 = (m_gate_24 || m_button_30);
		int gt_20 = (or_230 > ((int)0));
		t_sample iup_55 = (1 / maximum(1, abs(((int)4000))));
		t_sample idown_56 = (1 / maximum(1, abs(((int)4000))));
		t_sample iup_58 = (1 / maximum(1, abs(((int)4000))));
		t_sample idown_59 = (1 / maximum(1, abs(((int)4000))));
		t_sample iup_61 = (1 / maximum(1, abs(((int)4000))));
		t_sample idown_62 = (1 / maximum(1, abs(((int)4000))));
		int eq_193 = (m_sw_23 == ((int)0));
		int eq_197 = (m_sw_23 == ((t_sample)0.5));
		t_sample switch_196 = (eq_197 ? ((int)0) : m_sw_23);
		t_sample switch_194 = (eq_193 ? ((t_sample)0.5) : switch_196);
		t_sample sub_26585 = (switch_194 - ((int)0));
		t_sample scale_26582 = ((safepow((sub_26585 * ((t_sample)1)), ((int)1)) * ((int)2)) + ((int)1));
		t_sample choice_63 = int(scale_26582);
		t_sample choice_64 = int(scale_26582);
		t_sample choice_65 = int(scale_26582);
		int neq_25349 = (scale_26582 != ((int)2));
		t_sample iup_67 = (1 / maximum(1, abs(((int)4000))));
		t_sample idown_68 = (1 / maximum(1, abs(((int)4000))));
		samples_to_seconds = (1 / samplerate);
		int min_85 = (-1);
		bool chan_ignore_98 = ((1 < 0) || (1 >= loop3_channels));
		int min_104 = (-1);
		int min_105 = (-1);
		bool chan_ignore_106 = ((((int)1) < 0) || (((int)1) >= loop3_channels));
		t_sample iup_110 = (1 / maximum(1, abs(((int)4000))));
		t_sample idown_111 = (1 / maximum(1, abs(((int)4000))));
		bool chan_ignore_123 = ((1 < 0) || (1 >= loop1_channels));
		int min_129 = (-1);
		int min_130 = (-1);
		bool chan_ignore_131 = ((((int)1) < 0) || (((int)1) >= loop1_channels));
		int min_149 = (-1);
		int min_150 = (-1);
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
			t_sample mix_26554 = (m_history_22 + (((t_sample)0.0042742627044161) * (m_ctrl_27 - m_history_22)));
			t_sample mix_202 = mix_26554;
			t_sample mix_26555 = (m_history_21 + (((t_sample)0.0042742627044161) * (mix_202 - m_history_21)));
			t_sample mix_200 = mix_26555;
			t_sample mix_26556 = (m_history_20 + (((t_sample)0.0042742627044161) * (mix_200 - m_history_20)));
			t_sample mix_198 = mix_26556;
			t_sample gen_211 = mix_198;
			t_sample history_203_next_205 = fixdenorm(mix_202);
			t_sample history_201_next_206 = fixdenorm(mix_200);
			t_sample history_199_next_207 = fixdenorm(mix_198);
			__m_slide_37 = fixdenorm((__m_slide_37 + (((gen_211 > __m_slide_37) ? iup_38 : idown_39) * (gen_211 - __m_slide_37))));
			t_sample slide_93 = __m_slide_37;
			t_sample fold_31 = fold(in2, (-1), ((int)0));
			t_sample fold_11 = fold(in1, (-1), ((int)0));
			int delta_226 = __m_delta_40(or_230);
			int gtep_225 = ((delta_226 >= ((int)1)) ? delta_226 : 0);
			t_sample plusequals_224 = __m_pluseq_41.post(gtep_225, m_history_19, 0);
			t_sample gen_229 = plusequals_224;
			int eq_222 = (plusequals_224 == ((int)2));
			t_sample history_223_next_227 = fixdenorm(eq_222);
			int gt_17 = (gen_229 > ((int)0));
			__m_count_42 = (((int)0) ? 0 : (fixdenorm(__m_count_42 + ((int)1))));
			int carry_43 = 0;
			if ((((int)0) != 0)) {
				__m_count_42 = 0;
				__m_carry_44 = 0;
				
			} else if (((loop3_dim_8098 > 0) && (__m_count_42 >= loop3_dim_8098))) {
				int wraps_45 = (__m_count_42 / loop3_dim_8098);
				__m_carry_44 = (__m_carry_44 + wraps_45);
				__m_count_42 = (__m_count_42 - (wraps_45 * loop3_dim_8098));
				carry_43 = 1;
				
			};
			int counter_143 = __m_count_42;
			int counter_144 = carry_43;
			int counter_145 = __m_carry_44;
			__m_count_46 = (((int)0) ? 0 : (fixdenorm(__m_count_46 + ((int)1))));
			int carry_47 = 0;
			if ((((int)0) != 0)) {
				__m_count_46 = 0;
				__m_carry_48 = 0;
				
			} else if (((loop1_dim_7932 > 0) && (__m_count_46 >= loop1_dim_7932))) {
				int wraps_49 = (__m_count_46 / loop1_dim_7932);
				__m_carry_48 = (__m_carry_48 + wraps_49);
				__m_count_46 = (__m_count_46 - (wraps_49 * loop1_dim_7932));
				carry_47 = 1;
				
			};
			int counter_155 = __m_count_46;
			int counter_156 = carry_47;
			int counter_157 = __m_carry_48;
			t_sample abs_35 = fabs(in2);
			t_sample add_34 = (abs_35 + ((t_sample)0.0001));
			t_sample rsub_37 = (((int)1) - add_34);
			__m_count_50 = (((int)0) ? 0 : (fixdenorm(__m_count_50 + ((int)1))));
			int carry_51 = 0;
			if ((((int)0) != 0)) {
				__m_count_50 = 0;
				__m_carry_52 = 0;
				
			} else if (((loop2_dim_152 > 0) && (__m_count_50 >= loop2_dim_152))) {
				int wraps_53 = (__m_count_50 / loop2_dim_152);
				__m_carry_52 = (__m_carry_52 + wraps_53);
				__m_count_50 = (__m_count_50 - (wraps_53 * loop2_dim_152));
				carry_51 = 1;
				
			};
			int counter_147 = __m_count_50;
			int counter_148 = carry_51;
			int counter_149 = __m_carry_52;
			t_sample mix_26557 = (m_history_18 + (((t_sample)0.0042742627044161) * (m_ctrl_29 - m_history_18)));
			t_sample mix_26317 = mix_26557;
			t_sample mix_26558 = (m_history_17 + (((t_sample)0.0042742627044161) * (mix_26317 - m_history_17)));
			t_sample mix_26321 = mix_26558;
			t_sample mix_26559 = (m_history_16 + (((t_sample)0.0042742627044161) * (mix_26321 - m_history_16)));
			t_sample mix_26319 = mix_26559;
			t_sample gen_214 = mix_26319;
			t_sample history_203_next_26315 = fixdenorm(mix_26317);
			t_sample history_201_next_26316 = fixdenorm(mix_26321);
			t_sample history_199_next_26312 = fixdenorm(mix_26319);
			t_sample abs_13 = fabs(in1);
			t_sample add_12 = (abs_13 + ((t_sample)0.0001));
			t_sample rsub_15 = (((int)1) - add_12);
			t_sample mix_26560 = (m_history_15 + (((t_sample)0.0042742627044161) * (m_ctrl_25 - m_history_15)));
			t_sample mix_26334 = mix_26560;
			t_sample mix_26561 = (m_history_14 + (((t_sample)0.0042742627044161) * (mix_26334 - m_history_14)));
			t_sample mix_26327 = mix_26561;
			t_sample mix_26562 = (m_history_13 + (((t_sample)0.0042742627044161) * (mix_26327 - m_history_13)));
			t_sample mix_26332 = mix_26562;
			t_sample gen_208 = mix_26332;
			t_sample history_203_next_26330 = fixdenorm(mix_26334);
			t_sample history_201_next_26333 = fixdenorm(mix_26327);
			t_sample history_199_next_26328 = fixdenorm(mix_26332);
			t_sample mix_26563 = (m_history_12 + (((t_sample)0.0042742627044161) * (m_ctrl_35 - m_history_12)));
			t_sample mix_26346 = mix_26563;
			t_sample mix_26564 = (m_history_11 + (((t_sample)0.0042742627044161) * (mix_26346 - m_history_11)));
			t_sample mix_26340 = mix_26564;
			t_sample mix_26565 = (m_history_10 + (((t_sample)0.0042742627044161) * (mix_26340 - m_history_10)));
			t_sample mix_26347 = mix_26565;
			t_sample gen_209 = mix_26347;
			t_sample history_203_next_26343 = fixdenorm(mix_26346);
			t_sample history_201_next_26344 = fixdenorm(mix_26340);
			t_sample history_199_next_26341 = fixdenorm(mix_26347);
			t_sample sub_26569 = (gen_209 - ((int)0));
			t_sample scale_26566 = ((safepow((sub_26569 * ((t_sample)1)), ((int)1)) * ((int)2)) + (-1));
			t_sample gtep_81 = ((scale_26566 >= ((int)0)) ? scale_26566 : 0);
			__m_slide_54 = fixdenorm((__m_slide_54 + (((gtep_81 > __m_slide_54) ? iup_55 : idown_56) * (gtep_81 - __m_slide_54))));
			t_sample slide_78 = __m_slide_54;
			t_sample out10 = slide_78;
			t_sample ceil_23105 = ceil(slide_78);
			t_sample sub_26573 = (gen_209 - ((int)0));
			t_sample scale_26570 = ((safepow((sub_26573 * ((t_sample)1)), ((int)1)) * ((int)2)) + (-1));
			t_sample abs_86 = fabs(scale_26570);
			t_sample sub_26577 = (abs_86 - ((int)1));
			t_sample scale_26574 = ((safepow((sub_26577 * ((t_sample)-1)), ((int)1)) * ((int)1)) + ((int)0));
			__m_slide_57 = fixdenorm((__m_slide_57 + (((scale_26574 > __m_slide_57) ? iup_58 : idown_59) * (scale_26574 - __m_slide_57))));
			t_sample slide_79 = __m_slide_57;
			t_sample out9 = slide_79;
			t_sample ceil_22784 = ceil(slide_79);
			t_sample sub_26581 = (gen_209 - ((int)0));
			t_sample scale_26578 = ((safepow((sub_26581 * ((t_sample)1)), ((int)1)) * ((int)2)) + (-1));
			t_sample ltep_83 = ((scale_26578 <= ((int)0)) ? scale_26578 : 0);
			t_sample abs_84 = fabs(ltep_83);
			__m_slide_60 = fixdenorm((__m_slide_60 + (((abs_84 > __m_slide_60) ? iup_61 : idown_62) * (abs_84 - __m_slide_60))));
			t_sample slide_80 = __m_slide_60;
			t_sample out8 = slide_80;
			t_sample ceil_21983 = ceil(slide_80);
			t_sample selector_68 = ((choice_63 >= 3) ? gt_17 : ((choice_63 >= 2) ? ((int)1) : ((choice_63 >= 1) ? gt_20 : 0)));
			t_sample selector_36 = ((choice_64 >= 3) ? gt_17 : ((choice_64 >= 2) ? ((int)1) : ((choice_64 >= 1) ? gt_20 : 0)));
			t_sample switch_38 = (selector_36 ? rsub_37 : fold_31);
			t_sample out4 = switch_38;
			t_sample selector_14 = ((choice_65 >= 3) ? gt_17 : ((choice_65 >= 2) ? ((int)1) : ((choice_65 >= 1) ? gt_20 : 0)));
			t_sample switch_16 = (selector_14 ? rsub_15 : fold_11);
			t_sample out3 = switch_16;
			t_sample switch_21822 = (neq_25349 ? ceil_23105 : ((int)1));
			t_sample mul_19735 = (counter_143 * switch_21822);
			t_sample switch_66 = (selector_68 ? mul_19735 : ((int)0));
			t_sample mul_20056 = (counter_143 * switch_21822);
			t_sample switch_63 = (selector_68 ? mul_20056 : ((int)0));
			t_sample switch_21500 = (neq_25349 ? ceil_21983 : ((int)1));
			t_sample mul_16208 = (switch_21500 * counter_155);
			t_sample switch_67 = (selector_68 ? mul_16208 : ((int)0));
			t_sample mul_15086 = (switch_21500 * counter_155);
			t_sample switch_69 = (selector_68 ? mul_15086 : ((int)0));
			t_sample switch_21661 = (neq_25349 ? ceil_22784 : ((int)1));
			t_sample mul_17011 = (switch_21661 * counter_147);
			t_sample switch_65 = (selector_68 ? mul_17011 : ((int)0));
			t_sample mul_17009 = (switch_21661 * counter_147);
			t_sample switch_64 = (selector_68 ? mul_17009 : ((int)0));
			t_sample mix_26586 = (m_history_9 + (((t_sample)0.0042742627044161) * (m_ctrl_26 - m_history_9)));
			t_sample mix_26352 = mix_26586;
			t_sample mix_26587 = (m_history_8 + (((t_sample)0.0042742627044161) * (mix_26352 - m_history_8)));
			t_sample mix_26351 = mix_26587;
			t_sample mix_26588 = (m_history_7 + (((t_sample)0.0042742627044161) * (mix_26351 - m_history_7)));
			t_sample mix_26359 = mix_26588;
			t_sample gen_210 = mix_26359;
			t_sample history_203_next_26357 = fixdenorm(mix_26352);
			t_sample history_201_next_26360 = fixdenorm(mix_26351);
			t_sample history_199_next_26355 = fixdenorm(mix_26359);
			t_sample sub_26592 = (gen_210 - ((int)0));
			t_sample scale_26589 = ((safepow((sub_26592 * ((t_sample)1)), ((int)1)) * ((int)2)) + (-1));
			t_sample abs_25 = fabs(scale_26589);
			t_sample sub_26596 = (abs_25 - ((int)1));
			t_sample scale_26593 = ((safepow((sub_26596 * ((t_sample)-1)), ((t_sample)2.5)) * ((t_sample)3.5)) + ((t_sample)0.5));
			__m_slide_66 = fixdenorm((__m_slide_66 + (((scale_26593 > __m_slide_66) ? iup_67 : idown_68) * (scale_26593 - __m_slide_66))));
			t_sample slide_23 = __m_slide_66;
			t_sample rdiv_113 = safediv(((int)1), slide_23);
			t_sample phasor_114 = __m_phasor_69(rdiv_113, samples_to_seconds);
			t_sample mul_111 = (phasor_114 * ((int)2));
			t_sample sub_110 = (mul_111 - ((int)1));
			t_sample cos_109 = cos(sub_110);
			t_sample sub_108 = (cos_109 - ((t_sample)0.5));
			t_sample mul_107 = (sub_108 * ((int)10));
			t_sample clamp_106 = ((mul_107 <= ((int)0)) ? ((int)0) : ((mul_107 >= ((int)1)) ? ((int)1) : mul_107));
			t_sample fold_99 = fold(phasor_114, ((int)0), ((int)1));
			double sample_index_70 = (fold_99 * (loop3_dim - 1));
			int index_trunc_71 = fixnan(floor(sample_index_70));
			double index_fract_72 = (sample_index_70 - index_trunc_71);
			int index_trunc_73 = (index_trunc_71 - 1);
			int index_trunc_74 = (index_trunc_71 + 1);
			int index_trunc_75 = (index_trunc_71 + 2);
			bool index_ignore_76 = ((index_trunc_73 >= loop3_dim) || (index_trunc_73 < 0));
			bool index_ignore_77 = ((index_trunc_71 >= loop3_dim) || (index_trunc_71 < 0));
			bool index_ignore_78 = ((index_trunc_74 >= loop3_dim) || (index_trunc_74 < 0));
			bool index_ignore_79 = ((index_trunc_75 >= loop3_dim) || (index_trunc_75 < 0));
			// phase loop3 channel 1;
			double read_loop_80 = (index_ignore_76 ? 0 : m_loop_36.read(index_trunc_73, 0));
			double read_loop_81 = (index_ignore_77 ? 0 : m_loop_36.read(index_trunc_71, 0));
			double read_loop_82 = (index_ignore_78 ? 0 : m_loop_36.read(index_trunc_74, 0));
			double read_loop_83 = (index_ignore_79 ? 0 : m_loop_36.read(index_trunc_75, 0));
			double readinterp_84 = spline_interp(index_fract_72, read_loop_80, read_loop_81, read_loop_82, read_loop_83);
			t_sample sample_loop_104 = readinterp_84;
			t_sample index_loop_105 = sample_index_70;
			t_sample mul_98 = (sample_loop_104 * clamp_106);
			t_sample mix_26597 = (in1 + (gen_208 * (mul_98 - in1)));
			t_sample mul_75 = (mix_26597 * slide_78);
			t_sample clamp_53 = ((mul_75 <= min_85) ? min_85 : ((mul_75 >= ((int)1)) ? ((int)1) : mul_75));
			int index_trunc_86 = fixnan(floor(switch_66));
			int index_wrap_87 = ((index_trunc_86 < 0) ? ((loop3_dim - 1) + ((index_trunc_86 + 1) % loop3_dim)) : (index_trunc_86 % loop3_dim));
			m_loop_36.write((clamp_53 + (m_loop_36.read(index_wrap_87, 0) * slide_93)), index_wrap_87, 0);
			double sample_index_88 = (fold_99 * (loop3_dim - 1));
			int index_trunc_89 = fixnan(floor(sample_index_88));
			double index_fract_90 = (sample_index_88 - index_trunc_89);
			int index_trunc_91 = (index_trunc_89 - 1);
			int index_trunc_92 = (index_trunc_89 + 1);
			int index_trunc_93 = (index_trunc_89 + 2);
			bool index_ignore_94 = ((index_trunc_91 >= loop3_dim) || (index_trunc_91 < 0));
			bool index_ignore_95 = ((index_trunc_89 >= loop3_dim) || (index_trunc_89 < 0));
			bool index_ignore_96 = ((index_trunc_92 >= loop3_dim) || (index_trunc_92 < 0));
			bool index_ignore_97 = ((index_trunc_93 >= loop3_dim) || (index_trunc_93 < 0));
			// phase loop3 channel 1;
			double read_loop_99 = ((chan_ignore_98 || index_ignore_94) ? 0 : m_loop_36.read(index_trunc_91, 1));
			double read_loop_100 = ((chan_ignore_98 || index_ignore_95) ? 0 : m_loop_36.read(index_trunc_89, 1));
			double read_loop_101 = ((chan_ignore_98 || index_ignore_96) ? 0 : m_loop_36.read(index_trunc_92, 1));
			double read_loop_102 = ((chan_ignore_98 || index_ignore_97) ? 0 : m_loop_36.read(index_trunc_93, 1));
			double readinterp_103 = spline_interp(index_fract_90, read_loop_99, read_loop_100, read_loop_101, read_loop_102);
			t_sample sample_loop_102 = readinterp_103;
			t_sample index_loop_103 = sample_index_88;
			t_sample mul_97 = (sample_loop_102 * clamp_106);
			t_sample mix_26598 = (in2 + (gen_208 * (mul_97 - in2)));
			t_sample clamp_45 = ((mix_26598 <= min_104) ? min_104 : ((mix_26598 >= ((int)1)) ? ((int)1) : mix_26598));
			t_sample mul_72 = (clamp_45 * slide_78);
			t_sample clamp_50 = ((mul_72 <= min_105) ? min_105 : ((mul_72 >= ((int)1)) ? ((int)1) : mul_72));
			int index_trunc_107 = fixnan(floor(switch_63));
			int index_wrap_108 = ((index_trunc_107 < 0) ? ((loop3_dim - 1) + ((index_trunc_107 + 1) % loop3_dim)) : (index_trunc_107 % loop3_dim));
			if ((!chan_ignore_106)) {
				m_loop_36.write((clamp_50 + (m_loop_36.read(index_wrap_108, ((int)1)) * slide_93)), index_wrap_108, ((int)1));
				
			};
			t_sample mix_26599 = (m_history_6 + (((t_sample)0.0042742627044161) * (m_ctrl_34 - m_history_6)));
			t_sample mix_26365 = mix_26599;
			t_sample mix_26600 = (m_history_5 + (((t_sample)0.0042742627044161) * (mix_26365 - m_history_5)));
			t_sample mix_26364 = mix_26600;
			t_sample mix_26601 = (m_history_4 + (((t_sample)0.0042742627044161) * (mix_26364 - m_history_4)));
			t_sample mix_26373 = mix_26601;
			t_sample gen_213 = mix_26373;
			t_sample history_203_next_26370 = fixdenorm(mix_26365);
			t_sample history_201_next_26372 = fixdenorm(mix_26364);
			t_sample history_199_next_26368 = fixdenorm(mix_26373);
			t_sample sub_26605 = (gen_213 - ((int)0));
			t_sample scale_26602 = ((safepow((sub_26605 * ((t_sample)1)), ((int)1)) * ((int)2)) + (-1));
			t_sample abs_41 = fabs(scale_26602);
			t_sample sub_26609 = (abs_41 - ((int)1));
			t_sample scale_26606 = ((safepow((sub_26609 * ((t_sample)-1)), ((t_sample)2.5)) * ((t_sample)3.5)) + ((t_sample)0.5));
			__m_slide_109 = fixdenorm((__m_slide_109 + (((scale_26606 > __m_slide_109) ? iup_110 : idown_111) * (scale_26606 - __m_slide_109))));
			t_sample slide_39 = __m_slide_109;
			t_sample rdiv_181 = safediv(((int)1), slide_39);
			t_sample phasor_182 = __m_phasor_112(rdiv_181, samples_to_seconds);
			t_sample mul_170 = (phasor_182 * ((int)2));
			t_sample sub_169 = (mul_170 - ((int)1));
			t_sample cos_168 = cos(sub_169);
			t_sample sub_167 = (cos_168 - ((t_sample)0.5));
			t_sample mul_166 = (sub_167 * ((int)10));
			t_sample clamp_165 = ((mul_166 <= ((int)0)) ? ((int)0) : ((mul_166 >= ((int)1)) ? ((int)1) : mul_166));
			t_sample fold_172 = fold(phasor_182, ((int)0), ((int)1));
			double sample_index_113 = (fold_172 * (loop1_dim - 1));
			int index_trunc_114 = fixnan(floor(sample_index_113));
			double index_fract_115 = (sample_index_113 - index_trunc_114);
			int index_trunc_116 = (index_trunc_114 - 1);
			int index_trunc_117 = (index_trunc_114 + 1);
			int index_trunc_118 = (index_trunc_114 + 2);
			bool index_ignore_119 = ((index_trunc_116 >= loop1_dim) || (index_trunc_116 < 0));
			bool index_ignore_120 = ((index_trunc_114 >= loop1_dim) || (index_trunc_114 < 0));
			bool index_ignore_121 = ((index_trunc_117 >= loop1_dim) || (index_trunc_117 < 0));
			bool index_ignore_122 = ((index_trunc_118 >= loop1_dim) || (index_trunc_118 < 0));
			// phase loop1 channel 1;
			double read_loop_124 = ((chan_ignore_123 || index_ignore_119) ? 0 : m_loop_32.read(index_trunc_116, 1));
			double read_loop_125 = ((chan_ignore_123 || index_ignore_120) ? 0 : m_loop_32.read(index_trunc_114, 1));
			double read_loop_126 = ((chan_ignore_123 || index_ignore_121) ? 0 : m_loop_32.read(index_trunc_117, 1));
			double read_loop_127 = ((chan_ignore_123 || index_ignore_122) ? 0 : m_loop_32.read(index_trunc_118, 1));
			double readinterp_128 = spline_interp(index_fract_115, read_loop_124, read_loop_125, read_loop_126, read_loop_127);
			t_sample sample_loop_176 = readinterp_128;
			t_sample index_loop_177 = sample_index_113;
			t_sample mul_164 = (sample_loop_176 * clamp_165);
			t_sample mix_26610 = (in2 + (gen_208 * (mul_164 - in2)));
			t_sample clamp_49 = ((mix_26610 <= min_129) ? min_129 : ((mix_26610 >= ((int)1)) ? ((int)1) : mix_26610));
			t_sample mul_74 = (clamp_49 * slide_80);
			t_sample clamp_52 = ((mul_74 <= min_130) ? min_130 : ((mul_74 >= ((int)1)) ? ((int)1) : mul_74));
			int index_trunc_132 = fixnan(floor(switch_67));
			int index_wrap_133 = ((index_trunc_132 < 0) ? ((loop1_dim - 1) + ((index_trunc_132 + 1) % loop1_dim)) : (index_trunc_132 % loop1_dim));
			if ((!chan_ignore_131)) {
				m_loop_32.write((clamp_52 + (m_loop_32.read(index_wrap_133, ((int)1)) * slide_93)), index_wrap_133, ((int)1));
				
			};
			double sample_index_134 = (fold_172 * (loop1_dim - 1));
			int index_trunc_135 = fixnan(floor(sample_index_134));
			double index_fract_136 = (sample_index_134 - index_trunc_135);
			int index_trunc_137 = (index_trunc_135 - 1);
			int index_trunc_138 = (index_trunc_135 + 1);
			int index_trunc_139 = (index_trunc_135 + 2);
			bool index_ignore_140 = ((index_trunc_137 >= loop1_dim) || (index_trunc_137 < 0));
			bool index_ignore_141 = ((index_trunc_135 >= loop1_dim) || (index_trunc_135 < 0));
			bool index_ignore_142 = ((index_trunc_138 >= loop1_dim) || (index_trunc_138 < 0));
			bool index_ignore_143 = ((index_trunc_139 >= loop1_dim) || (index_trunc_139 < 0));
			// phase loop1 channel 1;
			double read_loop_144 = (index_ignore_140 ? 0 : m_loop_32.read(index_trunc_137, 0));
			double read_loop_145 = (index_ignore_141 ? 0 : m_loop_32.read(index_trunc_135, 0));
			double read_loop_146 = (index_ignore_142 ? 0 : m_loop_32.read(index_trunc_138, 0));
			double read_loop_147 = (index_ignore_143 ? 0 : m_loop_32.read(index_trunc_139, 0));
			double readinterp_148 = spline_interp(index_fract_136, read_loop_144, read_loop_145, read_loop_146, read_loop_147);
			t_sample sample_loop_178 = readinterp_148;
			t_sample index_loop_179 = sample_index_134;
			t_sample mul_163 = (sample_loop_178 * clamp_165);
			t_sample mix_26611 = (in1 + (gen_208 * (mul_163 - in1)));
			t_sample clamp_58 = ((mix_26611 <= min_149) ? min_149 : ((mix_26611 >= ((int)1)) ? ((int)1) : mix_26611));
			t_sample mul_77 = (clamp_58 * slide_80);
			t_sample clamp_55 = ((mul_77 <= min_150) ? min_150 : ((mul_77 >= ((int)1)) ? ((int)1) : mul_77));
			int index_trunc_151 = fixnan(floor(switch_69));
			int index_wrap_152 = ((index_trunc_151 < 0) ? ((loop1_dim - 1) + ((index_trunc_151 + 1) % loop1_dim)) : (index_trunc_151 % loop1_dim));
			m_loop_32.write((clamp_55 + (m_loop_32.read(index_wrap_152, 0) * slide_93)), index_wrap_152, 0);
			t_sample mix_26612 = (m_history_3 + (((t_sample)0.0042742627044161) * (m_ctrl_28 - m_history_3)));
			t_sample mix_26379 = mix_26612;
			t_sample mix_26613 = (m_history_2 + (((t_sample)0.0042742627044161) * (mix_26379 - m_history_2)));
			t_sample mix_26377 = mix_26613;
			t_sample mix_26614 = (m_history_1 + (((t_sample)0.0042742627044161) * (mix_26377 - m_history_1)));
			t_sample mix_26386 = mix_26614;
			t_sample gen_212 = mix_26386;
			t_sample history_203_next_26384 = fixdenorm(mix_26379);
			t_sample history_201_next_26378 = fixdenorm(mix_26377);
			t_sample history_199_next_26382 = fixdenorm(mix_26386);
			t_sample sub_26618 = (gen_212 - ((int)0));
			t_sample scale_26615 = ((safepow((sub_26618 * ((t_sample)1)), ((int)1)) * ((int)2)) + (-1));
			t_sample abs_29 = fabs(scale_26615);
			t_sample sub_26622 = (abs_29 - ((int)1));
			t_sample scale_26619 = ((safepow((sub_26622 * ((t_sample)-1)), ((t_sample)2.5)) * ((t_sample)3.5)) + ((t_sample)0.5));
			__m_slide_153 = fixdenorm((__m_slide_153 + (((scale_26619 > __m_slide_153) ? iup_154 : idown_155) * (scale_26619 - __m_slide_153))));
			t_sample slide_27 = __m_slide_153;
			t_sample rdiv_134 = safediv(((int)1), slide_27);
			t_sample phasor_135 = __m_phasor_156(rdiv_134, samples_to_seconds);
			t_sample mul_132 = (phasor_135 * ((int)2));
			t_sample sub_131 = (mul_132 - ((int)1));
			t_sample cos_130 = cos(sub_131);
			t_sample sub_129 = (cos_130 - ((t_sample)0.5));
			t_sample mul_128 = (sub_129 * ((int)10));
			t_sample clamp_127 = ((mul_128 <= ((int)0)) ? ((int)0) : ((mul_128 >= ((int)1)) ? ((int)1) : mul_128));
			t_sample fold_120 = fold(phasor_135, ((int)0), ((int)1));
			double sample_index_157 = (fold_120 * (loop2_dim - 1));
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
			double read_loop_167 = (index_ignore_163 ? 0 : m_loop_33.read(index_trunc_160, 0));
			double read_loop_168 = (index_ignore_164 ? 0 : m_loop_33.read(index_trunc_158, 0));
			double read_loop_169 = (index_ignore_165 ? 0 : m_loop_33.read(index_trunc_161, 0));
			double read_loop_170 = (index_ignore_166 ? 0 : m_loop_33.read(index_trunc_162, 0));
			double readinterp_171 = spline_interp(index_fract_159, read_loop_167, read_loop_168, read_loop_169, read_loop_170);
			t_sample sample_loop_125 = readinterp_171;
			t_sample index_loop_126 = sample_index_157;
			t_sample mul_119 = (sample_loop_125 * clamp_127);
			t_sample mix_26623 = (in1 + (gen_208 * (mul_119 - in1)));
			t_sample clamp_57 = ((mix_26623 <= min_172) ? min_172 : ((mix_26623 >= ((int)1)) ? ((int)1) : mix_26623));
			t_sample mul_76 = (clamp_57 * slide_79);
			t_sample clamp_54 = ((mul_76 <= min_173) ? min_173 : ((mul_76 >= ((int)1)) ? ((int)1) : mul_76));
			int index_trunc_174 = fixnan(floor(switch_65));
			int index_wrap_175 = ((index_trunc_174 < 0) ? ((loop2_dim - 1) + ((index_trunc_174 + 1) % loop2_dim)) : (index_trunc_174 % loop2_dim));
			m_loop_33.write((clamp_54 + (m_loop_33.read(index_wrap_175, 0) * slide_93)), index_wrap_175, 0);
			t_sample mix_26624 = (mul_163 + (((t_sample)0.5) * (mul_119 - mul_163)));
			t_sample mix_26625 = (mix_26624 + (((t_sample)0.66) * (mul_98 - mix_26624)));
			t_sample mul_26150 = (mix_26625 * ((int)4));
			t_sample mix_26626 = (in1 + (gen_214 * (mul_26150 - in1)));
			t_sample clamp_91 = ((mix_26626 <= min_176) ? min_176 : ((mix_26626 >= ((int)1)) ? ((int)1) : mix_26626));
			t_sample out1 = clamp_91;
			t_sample fold_33 = fold(clamp_91, (-1), ((int)0));
			t_sample out5 = fold_33;
			double sample_index_177 = (fold_120 * (loop2_dim - 1));
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
			double read_loop_188 = ((chan_ignore_187 || index_ignore_183) ? 0 : m_loop_33.read(index_trunc_180, 1));
			double read_loop_189 = ((chan_ignore_187 || index_ignore_184) ? 0 : m_loop_33.read(index_trunc_178, 1));
			double read_loop_190 = ((chan_ignore_187 || index_ignore_185) ? 0 : m_loop_33.read(index_trunc_181, 1));
			double read_loop_191 = ((chan_ignore_187 || index_ignore_186) ? 0 : m_loop_33.read(index_trunc_182, 1));
			double readinterp_192 = spline_interp(index_fract_179, read_loop_188, read_loop_189, read_loop_190, read_loop_191);
			t_sample sample_loop_123 = readinterp_192;
			t_sample index_loop_124 = sample_index_177;
			t_sample mul_118 = (sample_loop_123 * clamp_127);
			t_sample mix_26627 = (in2 + (gen_208 * (mul_118 - in2)));
			t_sample clamp_47 = ((mix_26627 <= min_193) ? min_193 : ((mix_26627 >= ((int)1)) ? ((int)1) : mix_26627));
			t_sample mul_73 = (clamp_47 * slide_79);
			t_sample clamp_51 = ((mul_73 <= min_194) ? min_194 : ((mul_73 >= ((int)1)) ? ((int)1) : mul_73));
			int index_trunc_196 = fixnan(floor(switch_64));
			int index_wrap_197 = ((index_trunc_196 < 0) ? ((loop2_dim - 1) + ((index_trunc_196 + 1) % loop2_dim)) : (index_trunc_196 % loop2_dim));
			if ((!chan_ignore_195)) {
				m_loop_33.write((clamp_51 + (m_loop_33.read(index_wrap_197, ((int)1)) * slide_93)), index_wrap_197, ((int)1));
				
			};
			t_sample mix_26628 = (mul_164 + (((t_sample)0.5) * (mul_118 - mul_164)));
			t_sample mix_26629 = (mix_26628 + (((t_sample)0.66) * (mul_97 - mix_26628)));
			t_sample mul_26311 = (mix_26629 * ((int)4));
			t_sample mix_26630 = (in2 + (gen_214 * (mul_26311 - in2)));
			t_sample clamp_90 = ((mix_26630 <= min_198) ? min_198 : ((mix_26630 >= ((int)1)) ? ((int)1) : mix_26630));
			t_sample out2 = clamp_90;
			t_sample fold_32 = fold(clamp_90, (-1), ((int)0));
			t_sample out6 = fold_32;
			m_history_22 = history_203_next_205;
			m_history_20 = history_199_next_207;
			m_history_21 = history_201_next_206;
			m_history_19 = history_223_next_227;
			m_history_18 = history_203_next_26315;
			m_history_16 = history_199_next_26312;
			m_history_17 = history_201_next_26316;
			m_history_15 = history_203_next_26330;
			m_history_13 = history_199_next_26328;
			m_history_14 = history_201_next_26333;
			m_history_12 = history_203_next_26343;
			m_history_10 = history_199_next_26341;
			m_history_11 = history_201_next_26344;
			m_history_9 = history_203_next_26357;
			m_history_7 = history_199_next_26355;
			m_history_8 = history_201_next_26360;
			m_history_6 = history_203_next_26370;
			m_history_4 = history_199_next_26368;
			m_history_5 = history_201_next_26372;
			m_history_3 = history_203_next_26384;
			m_history_1 = history_199_next_26382;
			m_history_2 = history_201_next_26378;
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
	inline void set_sw1(t_param _value) {
		m_sw_23 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_gate(t_param _value) {
		m_gate_24 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_ctrl7(t_param _value) {
		m_ctrl_25 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_ctrl6(t_param _value) {
		m_ctrl_26 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_ctrl2(t_param _value) {
		m_ctrl_27 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_ctrl3(t_param _value) {
		m_ctrl_28 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_ctrl1(t_param _value) {
		m_ctrl_29 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_button(t_param _value) {
		m_button_30 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw2(t_param _value) {
		m_sw_31 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_loop1(void * _value) {
		m_loop_32.setbuffer(_value);
	};
	inline void set_loop2(void * _value) {
		m_loop_33.setbuffer(_value);
	};
	inline void set_ctrl5(t_param _value) {
		m_ctrl_34 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_ctrl4(t_param _value) {
		m_ctrl_35 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_loop3(void * _value) {
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
		case 0: *value = self->m_button_30; break;
		case 1: *value = self->m_ctrl_29; break;
		case 2: *value = self->m_ctrl_27; break;
		case 3: *value = self->m_ctrl_28; break;
		case 4: *value = self->m_ctrl_35; break;
		case 5: *value = self->m_ctrl_34; break;
		case 6: *value = self->m_ctrl_26; break;
		case 7: *value = self->m_ctrl_25; break;
		case 8: *value = self->m_gate_24; break;
		
		
		
		case 12: *value = self->m_sw_23; break;
		case 13: *value = self->m_sw_31; break;
		
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
	// initialize parameter 0 ("m_button_30")
	pi = self->__commonstate.params + 0;
	pi->name = "button";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_button_30;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 1 ("m_ctrl_29")
	pi = self->__commonstate.params + 1;
	pi->name = "ctrl1";
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
	// initialize parameter 2 ("m_ctrl_27")
	pi = self->__commonstate.params + 2;
	pi->name = "ctrl2";
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
	// initialize parameter 3 ("m_ctrl_28")
	pi = self->__commonstate.params + 3;
	pi->name = "ctrl3";
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
	// initialize parameter 4 ("m_ctrl_35")
	pi = self->__commonstate.params + 4;
	pi->name = "ctrl4";
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
	// initialize parameter 5 ("m_ctrl_34")
	pi = self->__commonstate.params + 5;
	pi->name = "ctrl5";
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
	// initialize parameter 6 ("m_ctrl_26")
	pi = self->__commonstate.params + 6;
	pi->name = "ctrl6";
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
	// initialize parameter 7 ("m_ctrl_25")
	pi = self->__commonstate.params + 7;
	pi->name = "ctrl7";
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
	// initialize parameter 8 ("m_gate_24")
	pi = self->__commonstate.params + 8;
	pi->name = "gate";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_gate_24;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 9 ("m_loop_32")
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
	// initialize parameter 10 ("m_loop_33")
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
	// initialize parameter 11 ("m_loop_36")
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
	// initialize parameter 12 ("m_sw_23")
	pi = self->__commonstate.params + 12;
	pi->name = "sw1";
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
	// initialize parameter 13 ("m_sw_31")
	pi = self->__commonstate.params + 13;
	pi->name = "sw2";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_31;
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
