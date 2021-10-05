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
	Data m_loop_31;
	Data m_loop_36;
	Data m_loop_34;
	Delta __m_delta_41;
	Phasor __m_phasor_73;
	Phasor __m_phasor_37;
	Phasor __m_phasor_116;
	Phasor __m_phasor_160;
	PlusEquals __m_pluseq_42;
	int __exception;
	int vectorsize;
	t_sample m_history_8;
	t_sample m_history_2;
	t_sample m_history_1;
	t_sample __m_slide_38;
	t_sample m_history_3;
	t_sample samples_to_seconds;
	t_sample m_history_4;
	t_sample __m_slide_43;
	t_sample m_history_5;
	t_sample m_ctrl_35;
	t_sample __m_slide_46;
	t_sample __m_slide_49;
	t_sample __m_count_56;
	t_sample __m_slide_70;
	t_sample samplerate;
	t_sample __m_slide_113;
	t_sample m_gate_33;
	t_sample __m_carry_68;
	t_sample __m_carry_63;
	t_sample __m_count_66;
	t_sample __m_carry_58;
	t_sample __m_count_61;
	t_sample m_history_7;
	t_sample m_ctrl_32;
	t_sample m_ctrl_30;
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
	t_sample m_history_6;
	t_sample m_history_19;
	t_sample m_history_21;
	t_sample __m_slide_157;
	t_sample m_ctrl_28;
	t_sample m_ctrl_29;
	t_sample m_history_20;
	t_sample m_button_26;
	t_sample m_ctrl_24;
	t_sample m_sw_25;
	t_sample m_history_22;
	t_sample m_ctrl_23;
	t_sample m_sw_27;
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
		m_ctrl_23 = ((int)0);
		m_ctrl_24 = ((int)0);
		m_sw_25 = ((int)0);
		m_button_26 = ((int)0);
		m_sw_27 = ((int)0);
		m_ctrl_28 = ((int)0);
		m_ctrl_29 = ((int)0);
		m_ctrl_30 = ((int)0);
		m_loop_31.reset("loop2", ((int)192000), ((int)2));
		m_ctrl_32 = ((int)0);
		m_gate_33 = ((int)0);
		m_loop_34.reset("loop1", ((int)192000), ((int)2));
		m_ctrl_35 = ((int)0);
		m_loop_36.reset("loop3", ((int)192000), ((int)2));
		samples_to_seconds = (1 / samplerate);
		__m_phasor_37.reset(0);
		__m_slide_38 = 0;
		__m_delta_41.reset(0);
		__m_pluseq_42.reset(0);
		__m_slide_43 = 0;
		__m_slide_46 = 0;
		__m_slide_49 = 0;
		__m_count_56 = 0;
		__m_carry_58 = 0;
		__m_count_61 = 0;
		__m_carry_63 = 0;
		__m_count_66 = 0;
		__m_carry_68 = 0;
		__m_slide_70 = 0;
		__m_phasor_73.reset(0);
		__m_slide_113 = 0;
		__m_phasor_116.reset(0);
		__m_slide_157 = 0;
		__m_phasor_160.reset(0);
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
		int loop3_dim_3674 = loop3_dim;
		int loop1_dim = m_loop_34.dim;
		int loop1_channels = m_loop_34.channels;
		int loop1_dim_3342 = loop1_dim;
		int loop2_dim = m_loop_31.dim;
		int loop2_channels = m_loop_31.channels;
		int loop2_dim_3508 = loop2_dim;
		samples_to_seconds = (1 / samplerate);
		t_sample iup_39 = (1 / maximum(1, abs(((int)4000))));
		t_sample idown_40 = (1 / maximum(1, abs(((int)4000))));
		int or_239 = (m_gate_33 || m_button_26);
		int gt_29 = (or_239 > ((int)0));
		t_sample div_16033 = (loop1_dim_3342 * ((t_sample)0.25));
		t_sample div_16362 = (loop2_dim_3508 * ((t_sample)1));
		t_sample div_16527 = (loop3_dim_3674 * ((t_sample)0.5));
		t_sample iup_44 = (1 / maximum(1, abs(((int)4000))));
		t_sample idown_45 = (1 / maximum(1, abs(((int)4000))));
		t_sample iup_47 = (1 / maximum(1, abs(((int)4000))));
		t_sample idown_48 = (1 / maximum(1, abs(((int)4000))));
		t_sample iup_50 = (1 / maximum(1, abs(((int)4000))));
		t_sample idown_51 = (1 / maximum(1, abs(((int)4000))));
		int eq_202 = (m_sw_25 == ((int)0));
		int eq_206 = (m_sw_25 == ((t_sample)0.5));
		t_sample switch_205 = (eq_206 ? ((int)0) : m_sw_25);
		t_sample switch_203 = (eq_202 ? ((t_sample)0.5) : switch_205);
		t_sample sub_16809 = (switch_203 - ((int)0));
		t_sample scale_16806 = ((safepow((sub_16809 * ((t_sample)1)), ((int)1)) * ((int)2)) + ((int)1));
		t_sample choice_52 = int(scale_16806);
		t_sample choice_53 = int(scale_16806);
		t_sample choice_54 = int(scale_16806);
		int neq_1 = (scale_16806 != ((int)2));
		int eq_196 = (m_sw_27 == ((int)0));
		int eq_200 = (m_sw_27 == ((t_sample)0.5));
		t_sample switch_199 = (eq_200 ? ((int)0) : m_sw_27);
		t_sample switch_197 = (eq_196 ? ((t_sample)0.5) : switch_199);
		t_sample sub_16813 = (switch_197 - ((int)0));
		t_sample scale_16810 = ((safepow((sub_16813 * ((t_sample)1)), ((int)1)) * ((int)2)) + ((int)1));
		t_sample choice_55 = int(scale_16810);
		t_sample selector_2028 = ((choice_55 >= 3) ? ((int)0) : ((choice_55 >= 2) ? div_16362 : ((choice_55 >= 1) ? div_16033 : 0)));
		t_sample choice_60 = int(scale_16810);
		t_sample selector_903 = ((choice_60 >= 3) ? div_16033 : ((choice_60 >= 2) ? div_16362 : ((choice_60 >= 1) ? div_16033 : 0)));
		t_sample choice_65 = int(scale_16810);
		t_sample selector_2193 = ((choice_65 >= 3) ? div_16527 : ((choice_65 >= 2) ? div_16362 : ((choice_65 >= 1) ? div_16033 : 0)));
		t_sample iup_71 = (1 / maximum(1, abs(((int)4000))));
		t_sample idown_72 = (1 / maximum(1, abs(((int)4000))));
		int min_89 = (-1);
		bool chan_ignore_102 = ((1 < 0) || (1 >= loop3_channels));
		int min_108 = (-1);
		int min_109 = (-1);
		bool chan_ignore_110 = ((((int)1) < 0) || (((int)1) >= loop3_channels));
		t_sample iup_114 = (1 / maximum(1, abs(((int)4000))));
		t_sample idown_115 = (1 / maximum(1, abs(((int)4000))));
		bool chan_ignore_127 = ((1 < 0) || (1 >= loop2_channels));
		int min_133 = (-1);
		int min_134 = (-1);
		bool chan_ignore_135 = ((((int)1) < 0) || (((int)1) >= loop2_channels));
		int min_153 = (-1);
		int min_154 = (-1);
		t_sample iup_158 = (1 / maximum(1, abs(((int)4000))));
		t_sample idown_159 = (1 / maximum(1, abs(((int)4000))));
		bool chan_ignore_171 = ((1 < 0) || (1 >= loop1_channels));
		int min_177 = (-1);
		int min_178 = (-1);
		bool chan_ignore_179 = ((((int)1) < 0) || (((int)1) >= loop1_channels));
		int min_182 = (-1);
		int min_198 = (-1);
		int min_199 = (-1);
		int min_202 = (-1);
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			const t_sample in2 = (*(__in2++));
			t_sample out7 = ((int)0);
			t_sample fold_20 = fold(in1, (-1), ((int)0));
			t_sample fold_40 = fold(in2, (-1), ((int)0));
			t_sample phasor_11264 = __m_phasor_37(((int)1), samples_to_seconds);
			t_sample mix_16778 = (m_history_22 + (((t_sample)0.0042742627044161) * (m_ctrl_24 - m_history_22)));
			t_sample mix_211 = mix_16778;
			t_sample mix_16779 = (m_history_21 + (((t_sample)0.0042742627044161) * (mix_211 - m_history_21)));
			t_sample mix_209 = mix_16779;
			t_sample mix_16780 = (m_history_20 + (((t_sample)0.0042742627044161) * (mix_209 - m_history_20)));
			t_sample mix_207 = mix_16780;
			t_sample gen_220 = mix_207;
			t_sample history_212_next_214 = fixdenorm(mix_211);
			t_sample history_210_next_215 = fixdenorm(mix_209);
			t_sample history_208_next_216 = fixdenorm(mix_207);
			__m_slide_38 = fixdenorm((__m_slide_38 + (((gen_220 > __m_slide_38) ? iup_39 : idown_40) * (gen_220 - __m_slide_38))));
			t_sample slide_102 = __m_slide_38;
			int delta_235 = __m_delta_41(or_239);
			int gtep_234 = ((delta_235 >= ((int)1)) ? delta_235 : 0);
			t_sample plusequals_233 = __m_pluseq_42.post(gtep_234, m_history_19, 0);
			t_sample gen_238 = plusequals_233;
			int eq_231 = (plusequals_233 == ((int)2));
			t_sample history_232_next_236 = fixdenorm(eq_231);
			int gt_26 = (gen_238 > ((int)0));
			t_sample abs_22 = fabs(in1);
			t_sample add_21 = (abs_22 + ((t_sample)0.0001));
			t_sample rsub_24 = (((int)1) - add_21);
			t_sample abs_44 = fabs(in2);
			t_sample add_43 = (abs_44 + ((t_sample)0.0001));
			t_sample rsub_46 = (((int)1) - add_43);
			t_sample mix_16781 = (m_history_18 + (((t_sample)0.0042742627044161) * (m_ctrl_30 - m_history_18)));
			t_sample mix_16536 = mix_16781;
			t_sample mix_16782 = (m_history_17 + (((t_sample)0.0042742627044161) * (mix_16536 - m_history_17)));
			t_sample mix_16532 = mix_16782;
			t_sample mix_16783 = (m_history_16 + (((t_sample)0.0042742627044161) * (mix_16532 - m_history_16)));
			t_sample mix_16529 = mix_16783;
			t_sample gen_223 = mix_16529;
			t_sample history_212_next_16531 = fixdenorm(mix_16536);
			t_sample history_210_next_16535 = fixdenorm(mix_16532);
			t_sample history_208_next_16533 = fixdenorm(mix_16529);
			t_sample mix_16784 = (m_history_15 + (((t_sample)0.0042742627044161) * (m_ctrl_32 - m_history_15)));
			t_sample mix_16543 = mix_16784;
			t_sample mix_16785 = (m_history_14 + (((t_sample)0.0042742627044161) * (mix_16543 - m_history_14)));
			t_sample mix_16546 = mix_16785;
			t_sample mix_16786 = (m_history_13 + (((t_sample)0.0042742627044161) * (mix_16546 - m_history_13)));
			t_sample mix_16548 = mix_16786;
			t_sample gen_218 = mix_16548;
			t_sample history_212_next_16547 = fixdenorm(mix_16543);
			t_sample history_210_next_16549 = fixdenorm(mix_16546);
			t_sample history_208_next_16542 = fixdenorm(mix_16548);
			t_sample sub_16790 = (gen_218 - ((int)0));
			t_sample scale_16787 = ((safepow((sub_16790 * ((t_sample)1)), ((int)1)) * ((int)2)) + (-1));
			t_sample gtep_90 = ((scale_16787 >= ((int)0)) ? scale_16787 : 0);
			__m_slide_43 = fixdenorm((__m_slide_43 + (((gtep_90 > __m_slide_43) ? iup_44 : idown_45) * (gtep_90 - __m_slide_43))));
			t_sample slide_87 = __m_slide_43;
			t_sample out10 = slide_87;
			t_sample ceil_5 = ceil(slide_87);
			t_sample sub_16794 = (gen_218 - ((int)0));
			t_sample scale_16791 = ((safepow((sub_16794 * ((t_sample)1)), ((int)1)) * ((int)2)) + (-1));
			t_sample ltep_92 = ((scale_16791 <= ((int)0)) ? scale_16791 : 0);
			t_sample abs_93 = fabs(ltep_92);
			__m_slide_46 = fixdenorm((__m_slide_46 + (((abs_93 > __m_slide_46) ? iup_47 : idown_48) * (abs_93 - __m_slide_46))));
			t_sample slide_89 = __m_slide_46;
			t_sample out8 = slide_89;
			t_sample ceil_7 = ceil(slide_89);
			t_sample sub_16798 = (gen_218 - ((int)0));
			t_sample scale_16795 = ((safepow((sub_16798 * ((t_sample)1)), ((int)1)) * ((int)2)) + (-1));
			t_sample abs_95 = fabs(scale_16795);
			t_sample sub_16802 = (abs_95 - ((int)1));
			t_sample scale_16799 = ((safepow((sub_16802 * ((t_sample)-1)), ((int)1)) * ((int)1)) + ((int)0));
			__m_slide_49 = fixdenorm((__m_slide_49 + (((scale_16799 > __m_slide_49) ? iup_50 : idown_51) * (scale_16799 - __m_slide_49))));
			t_sample slide_88 = __m_slide_49;
			t_sample NM_28 = (phasor_11264 + slide_88);
			t_sample out9 = NM_28;
			t_sample ceil_6 = ceil(slide_88);
			t_sample mix_16803 = (m_history_12 + (((t_sample)0.0042742627044161) * (m_ctrl_28 - m_history_12)));
			t_sample mix_16556 = mix_16803;
			t_sample mix_16804 = (m_history_11 + (((t_sample)0.0042742627044161) * (mix_16556 - m_history_11)));
			t_sample mix_16558 = mix_16804;
			t_sample mix_16805 = (m_history_10 + (((t_sample)0.0042742627044161) * (mix_16558 - m_history_10)));
			t_sample mix_16561 = mix_16805;
			t_sample gen_217 = mix_16561;
			t_sample history_212_next_16559 = fixdenorm(mix_16556);
			t_sample history_210_next_16563 = fixdenorm(mix_16558);
			t_sample history_208_next_16555 = fixdenorm(mix_16561);
			t_sample selector_23 = ((choice_52 >= 3) ? gt_26 : ((choice_52 >= 2) ? ((int)1) : ((choice_52 >= 1) ? gt_29 : 0)));
			t_sample switch_25 = (selector_23 ? rsub_24 : fold_20);
			t_sample out3 = switch_25;
			t_sample selector_45 = ((choice_53 >= 3) ? gt_26 : ((choice_53 >= 2) ? ((int)1) : ((choice_53 >= 1) ? gt_29 : 0)));
			t_sample switch_47 = (selector_45 ? rsub_46 : fold_40);
			t_sample out4 = switch_47;
			t_sample selector_77 = ((choice_54 >= 3) ? gt_26 : ((choice_54 >= 2) ? ((int)1) : ((choice_54 >= 1) ? gt_29 : 0)));
			t_sample switch_12 = (neq_1 ? ceil_6 : ((int)1));
			t_sample switch_15 = (neq_1 ? ceil_7 : ((int)1));
			t_sample switch_10 = (neq_1 ? ceil_5 : ((int)1));
			__m_count_56 = (((int)0) ? 0 : (fixdenorm(__m_count_56 + ((int)1))));
			int carry_57 = 0;
			if ((((int)0) != 0)) {
				__m_count_56 = 0;
				__m_carry_58 = 0;
				
			} else if (((selector_2028 > 0) && (__m_count_56 >= selector_2028))) {
				int wraps_59 = (__m_count_56 / selector_2028);
				__m_carry_58 = (__m_carry_58 + wraps_59);
				__m_count_56 = (__m_count_56 - (wraps_59 * selector_2028));
				carry_57 = 1;
				
			};
			int counter_156 = __m_count_56;
			int counter_157 = carry_57;
			int counter_158 = __m_carry_58;
			t_sample mul_11 = (switch_12 * counter_156);
			t_sample switch_73 = (selector_77 ? mul_11 : ((int)0));
			t_sample mul_13 = (switch_12 * counter_156);
			t_sample switch_74 = (selector_77 ? mul_13 : ((int)0));
			__m_count_61 = (((int)0) ? 0 : (fixdenorm(__m_count_61 + ((int)1))));
			int carry_62 = 0;
			if ((((int)0) != 0)) {
				__m_count_61 = 0;
				__m_carry_63 = 0;
				
			} else if (((selector_903 > 0) && (__m_count_61 >= selector_903))) {
				int wraps_64 = (__m_count_61 / selector_903);
				__m_carry_63 = (__m_carry_63 + wraps_64);
				__m_count_61 = (__m_count_61 - (wraps_64 * selector_903));
				carry_62 = 1;
				
			};
			int counter_164 = __m_count_61;
			int counter_165 = carry_62;
			int counter_166 = __m_carry_63;
			t_sample mul_14 = (switch_15 * counter_164);
			t_sample switch_76 = (selector_77 ? mul_14 : ((int)0));
			t_sample mul_16 = (switch_15 * counter_164);
			t_sample switch_78 = (selector_77 ? mul_16 : ((int)0));
			__m_count_66 = (((int)0) ? 0 : (fixdenorm(__m_count_66 + ((int)1))));
			int carry_67 = 0;
			if ((((int)0) != 0)) {
				__m_count_66 = 0;
				__m_carry_68 = 0;
				
			} else if (((selector_2193 > 0) && (__m_count_66 >= selector_2193))) {
				int wraps_69 = (__m_count_66 / selector_2193);
				__m_carry_68 = (__m_carry_68 + wraps_69);
				__m_count_66 = (__m_count_66 - (wraps_69 * selector_2193));
				carry_67 = 1;
				
			};
			int counter_152 = __m_count_66;
			int counter_153 = carry_67;
			int counter_154 = __m_carry_68;
			t_sample mul_9 = (counter_152 * switch_10);
			t_sample switch_75 = (selector_77 ? mul_9 : ((int)0));
			t_sample mul_8 = (counter_152 * switch_10);
			t_sample switch_72 = (selector_77 ? mul_8 : ((int)0));
			t_sample mix_16814 = (m_history_9 + (((t_sample)0.0042742627044161) * (m_ctrl_29 - m_history_9)));
			t_sample mix_16572 = mix_16814;
			t_sample mix_16815 = (m_history_8 + (((t_sample)0.0042742627044161) * (mix_16572 - m_history_8)));
			t_sample mix_16575 = mix_16815;
			t_sample mix_16816 = (m_history_7 + (((t_sample)0.0042742627044161) * (mix_16575 - m_history_7)));
			t_sample mix_16571 = mix_16816;
			t_sample gen_219 = mix_16571;
			t_sample history_212_next_16573 = fixdenorm(mix_16572);
			t_sample history_210_next_16574 = fixdenorm(mix_16575);
			t_sample history_208_next_16570 = fixdenorm(mix_16571);
			t_sample sub_16820 = (gen_219 - ((int)0));
			t_sample scale_16817 = ((safepow((sub_16820 * ((t_sample)1)), ((int)1)) * ((int)2)) + (-1));
			t_sample abs_34 = fabs(scale_16817);
			t_sample sub_16824 = (abs_34 - ((int)1));
			t_sample scale_16821 = ((safepow((sub_16824 * ((t_sample)-1)), ((int)1)) * ((t_sample)7.5)) + ((t_sample)0.5));
			__m_slide_70 = fixdenorm((__m_slide_70 + (((scale_16821 > __m_slide_70) ? iup_71 : idown_72) * (scale_16821 - __m_slide_70))));
			t_sample slide_32 = __m_slide_70;
			t_sample rdiv_122 = safediv(((int)1), slide_32);
			t_sample phasor_123 = __m_phasor_73(rdiv_122, samples_to_seconds);
			t_sample mul_120 = (phasor_123 * ((int)2));
			t_sample sub_119 = (mul_120 - ((int)1));
			t_sample cos_118 = cos(sub_119);
			t_sample sub_117 = (cos_118 - ((t_sample)0.5));
			t_sample mul_116 = (sub_117 * ((int)10));
			t_sample clamp_115 = ((mul_116 <= ((int)0)) ? ((int)0) : ((mul_116 >= ((int)1)) ? ((int)1) : mul_116));
			t_sample fold_108 = fold(phasor_123, ((int)0), ((int)1));
			double sample_index_74 = (fold_108 * (loop3_dim - 1));
			int index_trunc_75 = fixnan(floor(sample_index_74));
			double index_fract_76 = (sample_index_74 - index_trunc_75);
			int index_trunc_77 = (index_trunc_75 - 1);
			int index_trunc_78 = (index_trunc_75 + 1);
			int index_trunc_79 = (index_trunc_75 + 2);
			bool index_ignore_80 = ((index_trunc_77 >= loop3_dim) || (index_trunc_77 < 0));
			bool index_ignore_81 = ((index_trunc_75 >= loop3_dim) || (index_trunc_75 < 0));
			bool index_ignore_82 = ((index_trunc_78 >= loop3_dim) || (index_trunc_78 < 0));
			bool index_ignore_83 = ((index_trunc_79 >= loop3_dim) || (index_trunc_79 < 0));
			// phase loop3 channel 1;
			double read_loop_84 = (index_ignore_80 ? 0 : m_loop_36.read(index_trunc_77, 0));
			double read_loop_85 = (index_ignore_81 ? 0 : m_loop_36.read(index_trunc_75, 0));
			double read_loop_86 = (index_ignore_82 ? 0 : m_loop_36.read(index_trunc_78, 0));
			double read_loop_87 = (index_ignore_83 ? 0 : m_loop_36.read(index_trunc_79, 0));
			double readinterp_88 = spline_interp(index_fract_76, read_loop_84, read_loop_85, read_loop_86, read_loop_87);
			t_sample sample_loop_113 = readinterp_88;
			t_sample index_loop_114 = sample_index_74;
			t_sample mul_107 = (sample_loop_113 * clamp_115);
			t_sample mix_16825 = (in1 + (gen_217 * (mul_107 - in1)));
			t_sample mul_84 = (mix_16825 * slide_87);
			t_sample clamp_62 = ((mul_84 <= min_89) ? min_89 : ((mul_84 >= ((int)1)) ? ((int)1) : mul_84));
			int index_trunc_90 = fixnan(floor(switch_75));
			int index_wrap_91 = ((index_trunc_90 < 0) ? ((loop3_dim - 1) + ((index_trunc_90 + 1) % loop3_dim)) : (index_trunc_90 % loop3_dim));
			m_loop_36.write((clamp_62 + (m_loop_36.read(index_wrap_91, 0) * slide_102)), index_wrap_91, 0);
			double sample_index_92 = (fold_108 * (loop3_dim - 1));
			int index_trunc_93 = fixnan(floor(sample_index_92));
			double index_fract_94 = (sample_index_92 - index_trunc_93);
			int index_trunc_95 = (index_trunc_93 - 1);
			int index_trunc_96 = (index_trunc_93 + 1);
			int index_trunc_97 = (index_trunc_93 + 2);
			bool index_ignore_98 = ((index_trunc_95 >= loop3_dim) || (index_trunc_95 < 0));
			bool index_ignore_99 = ((index_trunc_93 >= loop3_dim) || (index_trunc_93 < 0));
			bool index_ignore_100 = ((index_trunc_96 >= loop3_dim) || (index_trunc_96 < 0));
			bool index_ignore_101 = ((index_trunc_97 >= loop3_dim) || (index_trunc_97 < 0));
			// phase loop3 channel 1;
			double read_loop_103 = ((chan_ignore_102 || index_ignore_98) ? 0 : m_loop_36.read(index_trunc_95, 1));
			double read_loop_104 = ((chan_ignore_102 || index_ignore_99) ? 0 : m_loop_36.read(index_trunc_93, 1));
			double read_loop_105 = ((chan_ignore_102 || index_ignore_100) ? 0 : m_loop_36.read(index_trunc_96, 1));
			double read_loop_106 = ((chan_ignore_102 || index_ignore_101) ? 0 : m_loop_36.read(index_trunc_97, 1));
			double readinterp_107 = spline_interp(index_fract_94, read_loop_103, read_loop_104, read_loop_105, read_loop_106);
			t_sample sample_loop_111 = readinterp_107;
			t_sample index_loop_112 = sample_index_92;
			t_sample mul_106 = (sample_loop_111 * clamp_115);
			t_sample mix_16826 = (in2 + (gen_217 * (mul_106 - in2)));
			t_sample clamp_54 = ((mix_16826 <= min_108) ? min_108 : ((mix_16826 >= ((int)1)) ? ((int)1) : mix_16826));
			t_sample mul_81 = (clamp_54 * slide_87);
			t_sample clamp_59 = ((mul_81 <= min_109) ? min_109 : ((mul_81 >= ((int)1)) ? ((int)1) : mul_81));
			int index_trunc_111 = fixnan(floor(switch_72));
			int index_wrap_112 = ((index_trunc_111 < 0) ? ((loop3_dim - 1) + ((index_trunc_111 + 1) % loop3_dim)) : (index_trunc_111 % loop3_dim));
			if ((!chan_ignore_110)) {
				m_loop_36.write((clamp_59 + (m_loop_36.read(index_wrap_112, ((int)1)) * slide_102)), index_wrap_112, ((int)1));
				
			};
			t_sample mix_16827 = (m_history_6 + (((t_sample)0.0042742627044161) * (m_ctrl_23 - m_history_6)));
			t_sample mix_16585 = mix_16827;
			t_sample mix_16828 = (m_history_5 + (((t_sample)0.0042742627044161) * (mix_16585 - m_history_5)));
			t_sample mix_16587 = mix_16828;
			t_sample mix_16829 = (m_history_4 + (((t_sample)0.0042742627044161) * (mix_16587 - m_history_4)));
			t_sample mix_16586 = mix_16829;
			t_sample gen_222 = mix_16586;
			t_sample history_212_next_16588 = fixdenorm(mix_16585);
			t_sample history_210_next_16589 = fixdenorm(mix_16587);
			t_sample history_208_next_16584 = fixdenorm(mix_16586);
			t_sample sub_16833 = (gen_222 - ((int)0));
			t_sample scale_16830 = ((safepow((sub_16833 * ((t_sample)1)), ((int)1)) * ((int)2)) + (-1));
			t_sample abs_38 = fabs(scale_16830);
			t_sample sub_16837 = (abs_38 - ((int)1));
			t_sample scale_16834 = ((safepow((sub_16837 * ((t_sample)-1)), ((int)1)) * ((t_sample)7.5)) + ((t_sample)0.5));
			__m_slide_113 = fixdenorm((__m_slide_113 + (((scale_16834 > __m_slide_113) ? iup_114 : idown_115) * (scale_16834 - __m_slide_113))));
			t_sample slide_36 = __m_slide_113;
			t_sample rdiv_143 = safediv(((int)1), slide_36);
			t_sample phasor_144 = __m_phasor_116(rdiv_143, samples_to_seconds);
			t_sample mul_141 = (phasor_144 * ((int)2));
			t_sample sub_140 = (mul_141 - ((int)1));
			t_sample cos_139 = cos(sub_140);
			t_sample sub_138 = (cos_139 - ((t_sample)0.5));
			t_sample mul_137 = (sub_138 * ((int)10));
			t_sample clamp_136 = ((mul_137 <= ((int)0)) ? ((int)0) : ((mul_137 >= ((int)1)) ? ((int)1) : mul_137));
			t_sample fold_129 = fold(phasor_144, ((int)0), ((int)1));
			double sample_index_117 = (fold_129 * (loop2_dim - 1));
			int index_trunc_118 = fixnan(floor(sample_index_117));
			double index_fract_119 = (sample_index_117 - index_trunc_118);
			int index_trunc_120 = (index_trunc_118 - 1);
			int index_trunc_121 = (index_trunc_118 + 1);
			int index_trunc_122 = (index_trunc_118 + 2);
			bool index_ignore_123 = ((index_trunc_120 >= loop2_dim) || (index_trunc_120 < 0));
			bool index_ignore_124 = ((index_trunc_118 >= loop2_dim) || (index_trunc_118 < 0));
			bool index_ignore_125 = ((index_trunc_121 >= loop2_dim) || (index_trunc_121 < 0));
			bool index_ignore_126 = ((index_trunc_122 >= loop2_dim) || (index_trunc_122 < 0));
			// phase loop2 channel 1;
			double read_loop_128 = ((chan_ignore_127 || index_ignore_123) ? 0 : m_loop_31.read(index_trunc_120, 1));
			double read_loop_129 = ((chan_ignore_127 || index_ignore_124) ? 0 : m_loop_31.read(index_trunc_118, 1));
			double read_loop_130 = ((chan_ignore_127 || index_ignore_125) ? 0 : m_loop_31.read(index_trunc_121, 1));
			double read_loop_131 = ((chan_ignore_127 || index_ignore_126) ? 0 : m_loop_31.read(index_trunc_122, 1));
			double readinterp_132 = spline_interp(index_fract_119, read_loop_128, read_loop_129, read_loop_130, read_loop_131);
			t_sample sample_loop_132 = readinterp_132;
			t_sample index_loop_133 = sample_index_117;
			t_sample mul_127 = (sample_loop_132 * clamp_136);
			t_sample mix_16838 = (in2 + (gen_217 * (mul_127 - in2)));
			t_sample clamp_56 = ((mix_16838 <= min_133) ? min_133 : ((mix_16838 >= ((int)1)) ? ((int)1) : mix_16838));
			t_sample mul_82 = (clamp_56 * slide_88);
			t_sample clamp_60 = ((mul_82 <= min_134) ? min_134 : ((mul_82 >= ((int)1)) ? ((int)1) : mul_82));
			int index_trunc_136 = fixnan(floor(switch_73));
			int index_wrap_137 = ((index_trunc_136 < 0) ? ((loop2_dim - 1) + ((index_trunc_136 + 1) % loop2_dim)) : (index_trunc_136 % loop2_dim));
			if ((!chan_ignore_135)) {
				m_loop_31.write((clamp_60 + (m_loop_31.read(index_wrap_137, ((int)1)) * slide_102)), index_wrap_137, ((int)1));
				
			};
			double sample_index_138 = (fold_129 * (loop2_dim - 1));
			int index_trunc_139 = fixnan(floor(sample_index_138));
			double index_fract_140 = (sample_index_138 - index_trunc_139);
			int index_trunc_141 = (index_trunc_139 - 1);
			int index_trunc_142 = (index_trunc_139 + 1);
			int index_trunc_143 = (index_trunc_139 + 2);
			bool index_ignore_144 = ((index_trunc_141 >= loop2_dim) || (index_trunc_141 < 0));
			bool index_ignore_145 = ((index_trunc_139 >= loop2_dim) || (index_trunc_139 < 0));
			bool index_ignore_146 = ((index_trunc_142 >= loop2_dim) || (index_trunc_142 < 0));
			bool index_ignore_147 = ((index_trunc_143 >= loop2_dim) || (index_trunc_143 < 0));
			// phase loop2 channel 1;
			double read_loop_148 = (index_ignore_144 ? 0 : m_loop_31.read(index_trunc_141, 0));
			double read_loop_149 = (index_ignore_145 ? 0 : m_loop_31.read(index_trunc_139, 0));
			double read_loop_150 = (index_ignore_146 ? 0 : m_loop_31.read(index_trunc_142, 0));
			double read_loop_151 = (index_ignore_147 ? 0 : m_loop_31.read(index_trunc_143, 0));
			double readinterp_152 = spline_interp(index_fract_140, read_loop_148, read_loop_149, read_loop_150, read_loop_151);
			t_sample sample_loop_134 = readinterp_152;
			t_sample index_loop_135 = sample_index_138;
			t_sample mul_128 = (sample_loop_134 * clamp_136);
			t_sample mix_16839 = (in1 + (gen_217 * (mul_128 - in1)));
			t_sample clamp_66 = ((mix_16839 <= min_153) ? min_153 : ((mix_16839 >= ((int)1)) ? ((int)1) : mix_16839));
			t_sample mul_85 = (clamp_66 * slide_88);
			t_sample clamp_63 = ((mul_85 <= min_154) ? min_154 : ((mul_85 >= ((int)1)) ? ((int)1) : mul_85));
			int index_trunc_155 = fixnan(floor(switch_74));
			int index_wrap_156 = ((index_trunc_155 < 0) ? ((loop2_dim - 1) + ((index_trunc_155 + 1) % loop2_dim)) : (index_trunc_155 % loop2_dim));
			m_loop_31.write((clamp_63 + (m_loop_31.read(index_wrap_156, 0) * slide_102)), index_wrap_156, 0);
			t_sample mix_16840 = (m_history_3 + (((t_sample)0.0042742627044161) * (m_ctrl_35 - m_history_3)));
			t_sample mix_16595 = mix_16840;
			t_sample mix_16841 = (m_history_2 + (((t_sample)0.0042742627044161) * (mix_16595 - m_history_2)));
			t_sample mix_16599 = mix_16841;
			t_sample mix_16842 = (m_history_1 + (((t_sample)0.0042742627044161) * (mix_16599 - m_history_1)));
			t_sample mix_16600 = mix_16842;
			t_sample gen_221 = mix_16600;
			t_sample history_212_next_16596 = fixdenorm(mix_16595);
			t_sample history_210_next_16602 = fixdenorm(mix_16599);
			t_sample history_208_next_16598 = fixdenorm(mix_16600);
			t_sample sub_16846 = (gen_221 - ((int)0));
			t_sample scale_16843 = ((safepow((sub_16846 * ((t_sample)1)), ((int)1)) * ((int)2)) + (-1));
			t_sample abs_50 = fabs(scale_16843);
			t_sample sub_16850 = (abs_50 - ((int)1));
			t_sample scale_16847 = ((safepow((sub_16850 * ((t_sample)-1)), ((int)1)) * ((t_sample)7.5)) + ((t_sample)0.5));
			__m_slide_157 = fixdenorm((__m_slide_157 + (((scale_16847 > __m_slide_157) ? iup_158 : idown_159) * (scale_16847 - __m_slide_157))));
			t_sample slide_48 = __m_slide_157;
			t_sample rdiv_190 = safediv(((int)1), slide_48);
			t_sample phasor_191 = __m_phasor_160(rdiv_190, samples_to_seconds);
			t_sample mul_179 = (phasor_191 * ((int)2));
			t_sample sub_178 = (mul_179 - ((int)1));
			t_sample cos_177 = cos(sub_178);
			t_sample sub_176 = (cos_177 - ((t_sample)0.5));
			t_sample mul_175 = (sub_176 * ((int)10));
			t_sample clamp_174 = ((mul_175 <= ((int)0)) ? ((int)0) : ((mul_175 >= ((int)1)) ? ((int)1) : mul_175));
			t_sample fold_181 = fold(phasor_191, ((int)0), ((int)1));
			double sample_index_161 = (fold_181 * (loop1_dim - 1));
			int index_trunc_162 = fixnan(floor(sample_index_161));
			double index_fract_163 = (sample_index_161 - index_trunc_162);
			int index_trunc_164 = (index_trunc_162 - 1);
			int index_trunc_165 = (index_trunc_162 + 1);
			int index_trunc_166 = (index_trunc_162 + 2);
			bool index_ignore_167 = ((index_trunc_164 >= loop1_dim) || (index_trunc_164 < 0));
			bool index_ignore_168 = ((index_trunc_162 >= loop1_dim) || (index_trunc_162 < 0));
			bool index_ignore_169 = ((index_trunc_165 >= loop1_dim) || (index_trunc_165 < 0));
			bool index_ignore_170 = ((index_trunc_166 >= loop1_dim) || (index_trunc_166 < 0));
			// phase loop1 channel 1;
			double read_loop_172 = ((chan_ignore_171 || index_ignore_167) ? 0 : m_loop_34.read(index_trunc_164, 1));
			double read_loop_173 = ((chan_ignore_171 || index_ignore_168) ? 0 : m_loop_34.read(index_trunc_162, 1));
			double read_loop_174 = ((chan_ignore_171 || index_ignore_169) ? 0 : m_loop_34.read(index_trunc_165, 1));
			double read_loop_175 = ((chan_ignore_171 || index_ignore_170) ? 0 : m_loop_34.read(index_trunc_166, 1));
			double readinterp_176 = spline_interp(index_fract_163, read_loop_172, read_loop_173, read_loop_174, read_loop_175);
			t_sample sample_loop_185 = readinterp_176;
			t_sample index_loop_186 = sample_index_161;
			t_sample mul_173 = (sample_loop_185 * clamp_174);
			t_sample mix_16851 = (in2 + (gen_217 * (mul_173 - in2)));
			t_sample clamp_58 = ((mix_16851 <= min_177) ? min_177 : ((mix_16851 >= ((int)1)) ? ((int)1) : mix_16851));
			t_sample mul_83 = (clamp_58 * slide_89);
			t_sample clamp_61 = ((mul_83 <= min_178) ? min_178 : ((mul_83 >= ((int)1)) ? ((int)1) : mul_83));
			int index_trunc_180 = fixnan(floor(switch_76));
			int index_wrap_181 = ((index_trunc_180 < 0) ? ((loop1_dim - 1) + ((index_trunc_180 + 1) % loop1_dim)) : (index_trunc_180 % loop1_dim));
			if ((!chan_ignore_179)) {
				m_loop_34.write((clamp_61 + (m_loop_34.read(index_wrap_181, ((int)1)) * slide_102)), index_wrap_181, ((int)1));
				
			};
			t_sample mix_16852 = (mul_173 + (((t_sample)0.5) * (mul_127 - mul_173)));
			t_sample mix_16853 = (mix_16852 + (((t_sample)0.66) * (mul_106 - mix_16852)));
			t_sample mul_79 = (mix_16853 * ((int)4));
			t_sample mix_16854 = (in2 + (gen_223 * (mul_79 - in2)));
			t_sample clamp_99 = ((mix_16854 <= min_182) ? min_182 : ((mix_16854 >= ((int)1)) ? ((int)1) : mix_16854));
			t_sample out2 = clamp_99;
			t_sample fold_41 = fold(clamp_99, (-1), ((int)0));
			t_sample out6 = fold_41;
			double sample_index_183 = (fold_181 * (loop1_dim - 1));
			int index_trunc_184 = fixnan(floor(sample_index_183));
			double index_fract_185 = (sample_index_183 - index_trunc_184);
			int index_trunc_186 = (index_trunc_184 - 1);
			int index_trunc_187 = (index_trunc_184 + 1);
			int index_trunc_188 = (index_trunc_184 + 2);
			bool index_ignore_189 = ((index_trunc_186 >= loop1_dim) || (index_trunc_186 < 0));
			bool index_ignore_190 = ((index_trunc_184 >= loop1_dim) || (index_trunc_184 < 0));
			bool index_ignore_191 = ((index_trunc_187 >= loop1_dim) || (index_trunc_187 < 0));
			bool index_ignore_192 = ((index_trunc_188 >= loop1_dim) || (index_trunc_188 < 0));
			// phase loop1 channel 1;
			double read_loop_193 = (index_ignore_189 ? 0 : m_loop_34.read(index_trunc_186, 0));
			double read_loop_194 = (index_ignore_190 ? 0 : m_loop_34.read(index_trunc_184, 0));
			double read_loop_195 = (index_ignore_191 ? 0 : m_loop_34.read(index_trunc_187, 0));
			double read_loop_196 = (index_ignore_192 ? 0 : m_loop_34.read(index_trunc_188, 0));
			double readinterp_197 = spline_interp(index_fract_185, read_loop_193, read_loop_194, read_loop_195, read_loop_196);
			t_sample sample_loop_187 = readinterp_197;
			t_sample index_loop_188 = sample_index_183;
			t_sample mul_172 = (sample_loop_187 * clamp_174);
			t_sample mix_16855 = (in1 + (gen_217 * (mul_172 - in1)));
			t_sample clamp_67 = ((mix_16855 <= min_198) ? min_198 : ((mix_16855 >= ((int)1)) ? ((int)1) : mix_16855));
			t_sample mul_86 = (clamp_67 * slide_89);
			t_sample clamp_64 = ((mul_86 <= min_199) ? min_199 : ((mul_86 >= ((int)1)) ? ((int)1) : mul_86));
			int index_trunc_200 = fixnan(floor(switch_78));
			int index_wrap_201 = ((index_trunc_200 < 0) ? ((loop1_dim - 1) + ((index_trunc_200 + 1) % loop1_dim)) : (index_trunc_200 % loop1_dim));
			m_loop_34.write((clamp_64 + (m_loop_34.read(index_wrap_201, 0) * slide_102)), index_wrap_201, 0);
			t_sample mix_16856 = (mul_172 + (((t_sample)0.5) * (mul_128 - mul_172)));
			t_sample mix_16857 = (mix_16856 + (((t_sample)0.66) * (mul_107 - mix_16856)));
			t_sample mul_80 = (mix_16857 * ((int)4));
			t_sample mix_16858 = (in1 + (gen_223 * (mul_80 - in1)));
			t_sample clamp_100 = ((mix_16858 <= min_202) ? min_202 : ((mix_16858 >= ((int)1)) ? ((int)1) : mix_16858));
			t_sample out1 = clamp_100;
			t_sample fold_42 = fold(clamp_100, (-1), ((int)0));
			t_sample out5 = fold_42;
			m_history_22 = history_212_next_214;
			m_history_20 = history_208_next_216;
			m_history_21 = history_210_next_215;
			m_history_19 = history_232_next_236;
			m_history_18 = history_212_next_16531;
			m_history_16 = history_208_next_16533;
			m_history_17 = history_210_next_16535;
			m_history_15 = history_212_next_16547;
			m_history_13 = history_208_next_16542;
			m_history_14 = history_210_next_16549;
			m_history_12 = history_212_next_16559;
			m_history_10 = history_208_next_16555;
			m_history_11 = history_210_next_16563;
			m_history_9 = history_212_next_16573;
			m_history_7 = history_208_next_16570;
			m_history_8 = history_210_next_16574;
			m_history_6 = history_212_next_16588;
			m_history_4 = history_208_next_16584;
			m_history_5 = history_210_next_16589;
			m_history_3 = history_212_next_16596;
			m_history_1 = history_208_next_16598;
			m_history_2 = history_210_next_16602;
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
	inline void set_ctrl5(t_param _value) {
		m_ctrl_23 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_ctrl2(t_param _value) {
		m_ctrl_24 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw1(t_param _value) {
		m_sw_25 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_button(t_param _value) {
		m_button_26 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw2(t_param _value) {
		m_sw_27 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_ctrl7(t_param _value) {
		m_ctrl_28 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_ctrl6(t_param _value) {
		m_ctrl_29 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_ctrl1(t_param _value) {
		m_ctrl_30 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_loop2(void * _value) {
		m_loop_31.setbuffer(_value);
	};
	inline void set_ctrl4(t_param _value) {
		m_ctrl_32 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_gate(t_param _value) {
		m_gate_33 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_loop1(void * _value) {
		m_loop_34.setbuffer(_value);
	};
	inline void set_ctrl3(t_param _value) {
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
		case 0: *value = self->m_button_26; break;
		case 1: *value = self->m_ctrl_30; break;
		case 2: *value = self->m_ctrl_24; break;
		case 3: *value = self->m_ctrl_35; break;
		case 4: *value = self->m_ctrl_32; break;
		case 5: *value = self->m_ctrl_23; break;
		case 6: *value = self->m_ctrl_29; break;
		case 7: *value = self->m_ctrl_28; break;
		case 8: *value = self->m_gate_33; break;
		
		
		
		case 12: *value = self->m_sw_25; break;
		case 13: *value = self->m_sw_27; break;
		
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
	// initialize parameter 0 ("m_button_26")
	pi = self->__commonstate.params + 0;
	pi->name = "button";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_button_26;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 1 ("m_ctrl_30")
	pi = self->__commonstate.params + 1;
	pi->name = "ctrl1";
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
	// initialize parameter 2 ("m_ctrl_24")
	pi = self->__commonstate.params + 2;
	pi->name = "ctrl2";
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
	// initialize parameter 3 ("m_ctrl_35")
	pi = self->__commonstate.params + 3;
	pi->name = "ctrl3";
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
	// initialize parameter 4 ("m_ctrl_32")
	pi = self->__commonstate.params + 4;
	pi->name = "ctrl4";
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
	// initialize parameter 5 ("m_ctrl_23")
	pi = self->__commonstate.params + 5;
	pi->name = "ctrl5";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_ctrl_23;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 6 ("m_ctrl_29")
	pi = self->__commonstate.params + 6;
	pi->name = "ctrl6";
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
	// initialize parameter 7 ("m_ctrl_28")
	pi = self->__commonstate.params + 7;
	pi->name = "ctrl7";
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
	// initialize parameter 8 ("m_gate_33")
	pi = self->__commonstate.params + 8;
	pi->name = "gate";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_gate_33;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 9 ("m_loop_34")
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
	// initialize parameter 10 ("m_loop_31")
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
	// initialize parameter 13 ("m_sw_27")
	pi = self->__commonstate.params + 13;
	pi->name = "sw2";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_27;
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
