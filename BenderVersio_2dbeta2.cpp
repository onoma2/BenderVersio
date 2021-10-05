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
	Data m_loop_29;
	Data m_loop_36;
	Data m_loop_30;
	Delta __m_delta_40;
	Phasor __m_phasor_155;
	Phasor __m_phasor_114;
	Phasor __m_phasor_72;
	PlusEquals __m_pluseq_41;
	int __exception;
	int vectorsize;
	t_sample m_history_7;
	t_sample m_history_1;
	t_sample __m_slide_42;
	t_sample m_history_2;
	t_sample __m_slide_37;
	t_sample m_history_3;
	t_sample m_ctrl_35;
	t_sample __m_slide_45;
	t_sample m_gate_33;
	t_sample m_ctrl_34;
	t_sample __m_slide_48;
	t_sample __m_count_55;
	t_sample __m_carry_57;
	t_sample samples_to_seconds;
	t_sample samplerate;
	t_sample __m_slide_111;
	t_sample m_ctrl_32;
	t_sample __m_slide_69;
	t_sample __m_count_65;
	t_sample __m_carry_67;
	t_sample __m_count_60;
	t_sample __m_carry_62;
	t_sample m_history_6;
	t_sample m_ctrl_31;
	t_sample m_history_5;
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
	t_sample m_history_4;
	t_sample m_history_18;
	t_sample m_history_20;
	t_sample __m_slide_152;
	t_sample m_sw_27;
	t_sample m_ctrl_28;
	t_sample m_history_19;
	t_sample m_ctrl_25;
	t_sample m_sw_23;
	t_sample m_ctrl_24;
	t_sample m_history_21;
	t_sample m_history_22;
	t_sample m_button_26;
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
		m_button_26 = ((int)0);
		m_sw_27 = ((int)0);
		m_ctrl_28 = ((int)0);
		m_loop_29.reset("loop2", ((int)96000), ((int)2));
		m_loop_30.reset("loop1", ((int)48000), ((int)2));
		m_ctrl_31 = ((int)0);
		m_ctrl_32 = ((int)0);
		m_gate_33 = ((int)0);
		m_ctrl_34 = ((int)0);
		m_ctrl_35 = ((int)0);
		m_loop_36.reset("loop3", ((int)192000), ((int)2));
		__m_slide_37 = 0;
		__m_delta_40.reset(0);
		__m_pluseq_41.reset(0);
		__m_slide_42 = 0;
		__m_slide_45 = 0;
		__m_slide_48 = 0;
		__m_count_55 = 0;
		__m_carry_57 = 0;
		__m_count_60 = 0;
		__m_carry_62 = 0;
		__m_count_65 = 0;
		__m_carry_67 = 0;
		__m_slide_69 = 0;
		samples_to_seconds = (1 / samplerate);
		__m_phasor_72.reset(0);
		__m_slide_111 = 0;
		__m_phasor_114.reset(0);
		__m_slide_152 = 0;
		__m_phasor_155.reset(0);
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
		t_sample iup_38 = (1 / maximum(1, abs(((int)4000))));
		t_sample idown_39 = (1 / maximum(1, abs(((int)4000))));
		int or_233 = (m_gate_33 || m_button_26);
		int gt_361 = (or_233 > ((int)0));
		int eq_183 = (m_sw_27 == ((int)0));
		t_sample iup_43 = (1 / maximum(1, abs(((int)4000))));
		t_sample idown_44 = (1 / maximum(1, abs(((int)4000))));
		t_sample iup_46 = (1 / maximum(1, abs(((int)4000))));
		t_sample idown_47 = (1 / maximum(1, abs(((int)4000))));
		t_sample iup_49 = (1 / maximum(1, abs(((int)4000))));
		t_sample idown_50 = (1 / maximum(1, abs(((int)4000))));
		int eq_187 = (m_sw_27 == ((t_sample)0.5));
		t_sample switch_186 = (eq_187 ? ((int)0) : m_sw_27);
		t_sample switch_184 = (eq_183 ? ((t_sample)0.5) : switch_186);
		t_sample sub_21042 = (switch_184 - ((int)0));
		t_sample scale_21039 = ((safepow((sub_21042 * ((t_sample)1)), ((int)1)) * ((int)2)) + ((int)1));
		t_sample choice_51 = int(scale_21039);
		t_sample choice_52 = int(scale_21039);
		t_sample choice_53 = int(scale_21039);
		int eq_177 = (m_sw_23 == ((int)0));
		int eq_181 = (m_sw_23 == ((t_sample)0.5));
		t_sample switch_180 = (eq_181 ? ((int)0) : m_sw_23);
		t_sample switch_178 = (eq_177 ? ((t_sample)0.5) : switch_180);
		t_sample sub_21046 = (switch_178 - ((int)0));
		t_sample scale_21043 = ((safepow((sub_21046 * ((t_sample)1)), ((int)1)) * ((int)2)) + ((int)1));
		t_sample choice_54 = int(scale_21043);
		t_sample selector_10028 = ((choice_54 >= 3) ? ((int)48000) : ((choice_54 >= 2) ? ((int)192000) : ((choice_54 >= 1) ? ((int)48000) : 0)));
		t_sample choice_59 = int(scale_21043);
		t_sample selector_9782 = ((choice_59 >= 3) ? ((int)96000) : ((choice_59 >= 2) ? ((int)96000) : ((choice_59 >= 1) ? ((int)96000) : 0)));
		t_sample choice_64 = int(scale_21043);
		t_sample selector_405 = ((choice_64 >= 3) ? ((int)192000) : ((choice_64 >= 2) ? ((int)48000) : ((choice_64 >= 1) ? ((int)48000) : 0)));
		t_sample iup_70 = (1 / maximum(1, abs(((int)4000))));
		t_sample idown_71 = (1 / maximum(1, abs(((int)4000))));
		samples_to_seconds = (1 / samplerate);
		int loop1_dim = m_loop_30.dim;
		int loop1_channels = m_loop_30.channels;
		bool chan_ignore_83 = ((1 < 0) || (1 >= loop1_channels));
		int min_89 = (-1);
		int min_90 = (-1);
		bool chan_ignore_91 = ((((int)1) < 0) || (((int)1) >= loop1_channels));
		int min_108 = (-1);
		int min_109 = (-1);
		t_sample iup_112 = (1 / maximum(1, abs(((int)4000))));
		t_sample idown_113 = (1 / maximum(1, abs(((int)4000))));
		int loop3_dim = m_loop_36.dim;
		int loop3_channels = m_loop_36.channels;
		int min_130 = (-1);
		bool chan_ignore_142 = ((1 < 0) || (1 >= loop3_channels));
		int min_148 = (-1);
		int min_149 = (-1);
		bool chan_ignore_150 = ((((int)1) < 0) || (((int)1) >= loop3_channels));
		t_sample iup_153 = (1 / maximum(1, abs(((int)4000))));
		t_sample idown_154 = (1 / maximum(1, abs(((int)4000))));
		int loop2_dim = m_loop_29.dim;
		int loop2_channels = m_loop_29.channels;
		bool chan_ignore_166 = ((1 < 0) || (1 >= loop2_channels));
		int min_172 = (-1);
		int min_173 = (-1);
		bool chan_ignore_174 = ((((int)1) < 0) || (((int)1) >= loop2_channels));
		int min_176 = (-1);
		int min_192 = (-1);
		int min_193 = (-1);
		int min_195 = (-1);
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			const t_sample in2 = (*(__in2++));
			t_sample out9 = ((int)0);
			t_sample out7 = ((int)0);
			t_sample out10 = ((int)0);
			t_sample mix_21011 = (m_history_22 + (((t_sample)0.0042742627044161) * (m_ctrl_32 - m_history_22)));
			t_sample mix_192 = mix_21011;
			t_sample mix_21012 = (m_history_21 + (((t_sample)0.0042742627044161) * (mix_192 - m_history_21)));
			t_sample mix_190 = mix_21012;
			t_sample mix_21013 = (m_history_20 + (((t_sample)0.0042742627044161) * (mix_190 - m_history_20)));
			t_sample mix_188 = mix_21013;
			t_sample gen_207 = mix_188;
			t_sample history_193_next_199 = fixdenorm(mix_192);
			t_sample history_191_next_200 = fixdenorm(mix_190);
			t_sample history_189_next_201 = fixdenorm(mix_188);
			__m_slide_37 = fixdenorm((__m_slide_37 + (((gen_207 > __m_slide_37) ? iup_38 : idown_39) * (gen_207 - __m_slide_37))));
			t_sample slide_391 = __m_slide_37;
			t_sample fold_9 = fold(in2, (-1), ((int)0));
			t_sample fold_374 = fold(in1, (-1), ((int)0));
			int delta_226 = __m_delta_40(or_233);
			int gtep_225 = ((delta_226 >= ((int)1)) ? delta_226 : 0);
			t_sample plusequals_224 = __m_pluseq_41.post(gtep_225, m_history_19, 0);
			t_sample gen_232 = plusequals_224;
			int eq_222 = (plusequals_224 == ((int)2));
			t_sample history_223_next_230 = fixdenorm(eq_222);
			int gt_362 = (gen_232 > ((int)0));
			t_sample abs_11 = fabs(in2);
			t_sample add_10 = (abs_11 + ((t_sample)0.0001));
			t_sample rsub_13 = (((int)1) - add_10);
			t_sample abs_371 = fabs(in1);
			t_sample add_372 = (abs_371 + ((t_sample)0.0001));
			t_sample rsub_373 = (((int)1) - add_372);
			t_sample mix_21014 = (m_history_18 + (((t_sample)0.0042742627044161) * (m_ctrl_25 - m_history_18)));
			t_sample mix_20680 = mix_21014;
			t_sample mix_21015 = (m_history_17 + (((t_sample)0.0042742627044161) * (mix_20680 - m_history_17)));
			t_sample mix_20683 = mix_21015;
			t_sample mix_21016 = (m_history_16 + (((t_sample)0.0042742627044161) * (mix_20683 - m_history_16)));
			t_sample mix_20679 = mix_21016;
			t_sample gen_213 = mix_20679;
			t_sample history_193_next_20676 = fixdenorm(mix_20680);
			t_sample history_191_next_20675 = fixdenorm(mix_20683);
			t_sample history_189_next_20681 = fixdenorm(mix_20679);
			t_sample mix_21017 = (m_history_15 + (((t_sample)0.0042742627044161) * (m_ctrl_28 - m_history_15)));
			t_sample mix_20690 = mix_21017;
			t_sample mix_21018 = (m_history_14 + (((t_sample)0.0042742627044161) * (mix_20690 - m_history_14)));
			t_sample mix_20696 = mix_21018;
			t_sample mix_21019 = (m_history_13 + (((t_sample)0.0042742627044161) * (mix_20696 - m_history_13)));
			t_sample mix_20689 = mix_21019;
			t_sample gen_249 = mix_20689;
			t_sample history_193_next_20693 = fixdenorm(mix_20690);
			t_sample history_191_next_20692 = fixdenorm(mix_20696);
			t_sample history_189_next_20695 = fixdenorm(mix_20689);
			t_sample mix_21020 = (m_history_12 + (((t_sample)0.0042742627044161) * (m_ctrl_24 - m_history_12)));
			t_sample mix_20703 = mix_21020;
			t_sample mix_21021 = (m_history_11 + (((t_sample)0.0042742627044161) * (mix_20703 - m_history_11)));
			t_sample mix_20710 = mix_21021;
			t_sample mix_21022 = (m_history_10 + (((t_sample)0.0042742627044161) * (mix_20710 - m_history_10)));
			t_sample mix_20702 = mix_21022;
			t_sample gen_203 = mix_20702;
			t_sample history_193_next_20706 = fixdenorm(mix_20703);
			t_sample history_191_next_20705 = fixdenorm(mix_20710);
			t_sample history_189_next_20708 = fixdenorm(mix_20702);
			t_sample sub_21026 = (gen_203 - ((int)0));
			t_sample scale_21023 = ((safepow((sub_21026 * ((t_sample)1)), ((int)1)) * ((int)2)) + (-1));
			t_sample gtep_68 = ((scale_21023 >= ((int)0)) ? scale_21023 : 0);
			__m_slide_42 = fixdenorm((__m_slide_42 + (((gtep_68 > __m_slide_42) ? iup_43 : idown_44) * (gtep_68 - __m_slide_42))));
			t_sample slide_65 = __m_slide_42;
			t_sample sub_21030 = (gen_203 - ((int)0));
			t_sample scale_21027 = ((safepow((sub_21030 * ((t_sample)1)), ((int)1)) * ((int)2)) + (-1));
			t_sample abs_73 = fabs(scale_21027);
			t_sample sub_21034 = (abs_73 - ((int)1));
			t_sample scale_21031 = ((safepow((sub_21034 * ((t_sample)-1)), ((int)1)) * ((int)1)) + ((int)0));
			__m_slide_45 = fixdenorm((__m_slide_45 + (((scale_21031 > __m_slide_45) ? iup_46 : idown_47) * (scale_21031 - __m_slide_45))));
			t_sample slide_66 = __m_slide_45;
			t_sample sub_21038 = (gen_203 - ((int)0));
			t_sample scale_21035 = ((safepow((sub_21038 * ((t_sample)1)), ((int)1)) * ((int)2)) + (-1));
			t_sample ltep_70 = ((scale_21035 <= ((int)0)) ? scale_21035 : 0);
			t_sample abs_71 = fabs(ltep_70);
			__m_slide_48 = fixdenorm((__m_slide_48 + (((abs_71 > __m_slide_48) ? iup_49 : idown_50) * (abs_71 - __m_slide_48))));
			t_sample slide_67 = __m_slide_48;
			t_sample selector_355 = ((choice_51 >= 3) ? gt_362 : ((choice_51 >= 2) ? ((int)1) : ((choice_51 >= 1) ? gt_361 : 0)));
			t_sample selector_12 = ((choice_52 >= 3) ? gt_362 : ((choice_52 >= 2) ? ((int)1) : ((choice_52 >= 1) ? gt_361 : 0)));
			t_sample switch_14 = (selector_12 ? rsub_13 : fold_9);
			t_sample out4 = switch_14;
			t_sample selector_368 = ((choice_53 >= 3) ? gt_362 : ((choice_53 >= 2) ? ((int)1) : ((choice_53 >= 1) ? gt_361 : 0)));
			t_sample switch_363 = (selector_368 ? rsub_373 : fold_374);
			t_sample out3 = switch_363;
			__m_count_55 = (((int)0) ? 0 : (fixdenorm(__m_count_55 + ((int)1))));
			int carry_56 = 0;
			if ((((int)0) != 0)) {
				__m_count_55 = 0;
				__m_carry_57 = 0;
				
			} else if (((selector_10028 > 0) && (__m_count_55 >= selector_10028))) {
				int wraps_58 = (__m_count_55 / selector_10028);
				__m_carry_57 = (__m_carry_57 + wraps_58);
				__m_count_55 = (__m_count_55 - (wraps_58 * selector_10028));
				carry_56 = 1;
				
			};
			int counter_132 = __m_count_55;
			int counter_133 = carry_56;
			int counter_134 = __m_carry_57;
			int switch_53 = (selector_355 ? counter_132 : ((int)0));
			int switch_50 = (selector_355 ? counter_132 : ((int)0));
			__m_count_60 = (((int)0) ? 0 : (fixdenorm(__m_count_60 + ((int)1))));
			int carry_61 = 0;
			if ((((int)0) != 0)) {
				__m_count_60 = 0;
				__m_carry_62 = 0;
				
			} else if (((selector_9782 > 0) && (__m_count_60 >= selector_9782))) {
				int wraps_63 = (__m_count_60 / selector_9782);
				__m_carry_62 = (__m_carry_62 + wraps_63);
				__m_count_60 = (__m_count_60 - (wraps_63 * selector_9782));
				carry_61 = 1;
				
			};
			int counter_136 = __m_count_60;
			int counter_137 = carry_61;
			int counter_138 = __m_carry_62;
			int switch_51 = (selector_355 ? counter_136 : ((int)0));
			int switch_52 = (selector_355 ? counter_136 : ((int)0));
			__m_count_65 = (((int)0) ? 0 : (fixdenorm(__m_count_65 + ((int)1))));
			int carry_66 = 0;
			if ((((int)0) != 0)) {
				__m_count_65 = 0;
				__m_carry_67 = 0;
				
			} else if (((selector_405 > 0) && (__m_count_65 >= selector_405))) {
				int wraps_68 = (__m_count_65 / selector_405);
				__m_carry_67 = (__m_carry_67 + wraps_68);
				__m_count_65 = (__m_count_65 - (wraps_68 * selector_405));
				carry_66 = 1;
				
			};
			int counter_144 = __m_count_65;
			int counter_145 = carry_66;
			int counter_146 = __m_carry_67;
			int switch_54 = (selector_355 ? counter_144 : ((int)0));
			int switch_56 = (selector_355 ? counter_144 : ((int)0));
			t_sample mix_21047 = (m_history_9 + (((t_sample)0.0042742627044161) * (m_ctrl_34 - m_history_9)));
			t_sample mix_20721 = mix_21047;
			t_sample mix_21048 = (m_history_8 + (((t_sample)0.0042742627044161) * (mix_20721 - m_history_8)));
			t_sample mix_20722 = mix_21048;
			t_sample mix_21049 = (m_history_7 + (((t_sample)0.0042742627044161) * (mix_20722 - m_history_7)));
			t_sample mix_20717 = mix_21049;
			t_sample gen_211 = mix_20717;
			t_sample history_193_next_20715 = fixdenorm(mix_20721);
			t_sample history_191_next_20719 = fixdenorm(mix_20722);
			t_sample history_189_next_20716 = fixdenorm(mix_20717);
			t_sample sub_21053 = (gen_211 - ((int)0));
			t_sample scale_21050 = ((safepow((sub_21053 * ((t_sample)1)), ((int)1)) * ((int)2)) + (-1));
			t_sample abs_28 = fabs(scale_21050);
			t_sample sub_21057 = (abs_28 - ((int)1));
			t_sample scale_21054 = ((safepow((sub_21057 * ((t_sample)-1)), ((int)1)) * ((t_sample)1.5)) + ((t_sample)0.5));
			__m_slide_69 = fixdenorm((__m_slide_69 + (((scale_21054 > __m_slide_69) ? iup_70 : idown_71) * (scale_21054 - __m_slide_69))));
			t_sample slide_26 = __m_slide_69;
			t_sample rdiv_171 = safediv(((int)1), slide_26);
			t_sample phasor_172 = __m_phasor_72(rdiv_171, samples_to_seconds);
			t_sample out8 = phasor_172;
			t_sample mul_159 = (phasor_172 * ((int)2));
			t_sample sub_158 = (mul_159 - ((int)1));
			t_sample cos_157 = cos(sub_158);
			t_sample sub_156 = (cos_157 - ((t_sample)0.5));
			t_sample mul_155 = (sub_156 * ((int)10));
			t_sample clamp_154 = ((mul_155 <= ((int)0)) ? ((int)0) : ((mul_155 >= ((int)1)) ? ((int)1) : mul_155));
			t_sample fold_162 = fold(phasor_172, ((int)0), ((int)1));
			double sample_index_73 = (fold_162 * (loop1_dim - 1));
			int index_trunc_74 = fixnan(floor(sample_index_73));
			double index_fract_75 = (sample_index_73 - index_trunc_74);
			int index_trunc_76 = (index_trunc_74 - 1);
			int index_trunc_77 = (index_trunc_74 + 1);
			int index_trunc_78 = (index_trunc_74 + 2);
			bool index_ignore_79 = ((index_trunc_76 >= loop1_dim) || (index_trunc_76 < 0));
			bool index_ignore_80 = ((index_trunc_74 >= loop1_dim) || (index_trunc_74 < 0));
			bool index_ignore_81 = ((index_trunc_77 >= loop1_dim) || (index_trunc_77 < 0));
			bool index_ignore_82 = ((index_trunc_78 >= loop1_dim) || (index_trunc_78 < 0));
			// phase loop1 channel 1;
			double read_loop_84 = ((chan_ignore_83 || index_ignore_79) ? 0 : m_loop_30.read(index_trunc_76, 1));
			double read_loop_85 = ((chan_ignore_83 || index_ignore_80) ? 0 : m_loop_30.read(index_trunc_74, 1));
			double read_loop_86 = ((chan_ignore_83 || index_ignore_81) ? 0 : m_loop_30.read(index_trunc_77, 1));
			double read_loop_87 = ((chan_ignore_83 || index_ignore_82) ? 0 : m_loop_30.read(index_trunc_78, 1));
			double readinterp_88 = spline_interp(index_fract_75, read_loop_84, read_loop_85, read_loop_86, read_loop_87);
			t_sample sample_loop_166 = readinterp_88;
			t_sample index_loop_167 = sample_index_73;
			t_sample mul_153 = (sample_loop_166 * clamp_154);
			t_sample mix_21058 = (in2 + (gen_249 * (mul_153 - in2)));
			t_sample clamp_36 = ((mix_21058 <= min_89) ? min_89 : ((mix_21058 >= ((int)1)) ? ((int)1) : mix_21058));
			t_sample mul_61 = (clamp_36 * slide_67);
			t_sample clamp_39 = ((mul_61 <= min_90) ? min_90 : ((mul_61 >= ((int)1)) ? ((int)1) : mul_61));
			int index_wrap_92 = ((switch_54 < 0) ? ((loop1_dim - 1) + ((switch_54 + 1) % loop1_dim)) : (switch_54 % loop1_dim));
			if ((!chan_ignore_91)) {
				m_loop_30.write((clamp_39 + (m_loop_30.read(index_wrap_92, ((int)1)) * slide_391)), index_wrap_92, ((int)1));
				
			};
			double sample_index_93 = (fold_162 * (loop1_dim - 1));
			int index_trunc_94 = fixnan(floor(sample_index_93));
			double index_fract_95 = (sample_index_93 - index_trunc_94);
			int index_trunc_96 = (index_trunc_94 - 1);
			int index_trunc_97 = (index_trunc_94 + 1);
			int index_trunc_98 = (index_trunc_94 + 2);
			bool index_ignore_99 = ((index_trunc_96 >= loop1_dim) || (index_trunc_96 < 0));
			bool index_ignore_100 = ((index_trunc_94 >= loop1_dim) || (index_trunc_94 < 0));
			bool index_ignore_101 = ((index_trunc_97 >= loop1_dim) || (index_trunc_97 < 0));
			bool index_ignore_102 = ((index_trunc_98 >= loop1_dim) || (index_trunc_98 < 0));
			// phase loop1 channel 1;
			double read_loop_103 = (index_ignore_99 ? 0 : m_loop_30.read(index_trunc_96, 0));
			double read_loop_104 = (index_ignore_100 ? 0 : m_loop_30.read(index_trunc_94, 0));
			double read_loop_105 = (index_ignore_101 ? 0 : m_loop_30.read(index_trunc_97, 0));
			double read_loop_106 = (index_ignore_102 ? 0 : m_loop_30.read(index_trunc_98, 0));
			double readinterp_107 = spline_interp(index_fract_95, read_loop_103, read_loop_104, read_loop_105, read_loop_106);
			t_sample sample_loop_168 = readinterp_107;
			t_sample index_loop_169 = sample_index_93;
			t_sample mul_152 = (sample_loop_168 * clamp_154);
			t_sample mix_21059 = (in1 + (gen_249 * (mul_152 - in1)));
			t_sample clamp_45 = ((mix_21059 <= min_108) ? min_108 : ((mix_21059 >= ((int)1)) ? ((int)1) : mix_21059));
			t_sample mul_64 = (clamp_45 * slide_67);
			t_sample clamp_42 = ((mul_64 <= min_109) ? min_109 : ((mul_64 >= ((int)1)) ? ((int)1) : mul_64));
			int index_wrap_110 = ((switch_56 < 0) ? ((loop1_dim - 1) + ((switch_56 + 1) % loop1_dim)) : (switch_56 % loop1_dim));
			m_loop_30.write((clamp_42 + (m_loop_30.read(index_wrap_110, 0) * slide_391)), index_wrap_110, 0);
			t_sample mix_21060 = (m_history_6 + (((t_sample)0.0042742627044161) * (m_ctrl_35 - m_history_6)));
			t_sample mix_20735 = mix_21060;
			t_sample mix_21061 = (m_history_5 + (((t_sample)0.0042742627044161) * (mix_20735 - m_history_5)));
			t_sample mix_20736 = mix_21061;
			t_sample mix_21062 = (m_history_4 + (((t_sample)0.0042742627044161) * (mix_20736 - m_history_4)));
			t_sample mix_20730 = mix_21062;
			t_sample gen_205 = mix_20730;
			t_sample history_193_next_20728 = fixdenorm(mix_20735);
			t_sample history_191_next_20733 = fixdenorm(mix_20736);
			t_sample history_189_next_20729 = fixdenorm(mix_20730);
			t_sample sub_21066 = (gen_205 - ((int)0));
			t_sample scale_21063 = ((safepow((sub_21066 * ((t_sample)1)), ((int)1)) * ((int)2)) + (-1));
			t_sample abs_3 = fabs(scale_21063);
			t_sample sub_21070 = (abs_3 - ((int)1));
			t_sample scale_21067 = ((safepow((sub_21070 * ((t_sample)-1)), ((int)1)) * ((t_sample)1.5)) + ((t_sample)0.5));
			__m_slide_111 = fixdenorm((__m_slide_111 + (((scale_21067 > __m_slide_111) ? iup_112 : idown_113) * (scale_21067 - __m_slide_111))));
			t_sample slide_1 = __m_slide_111;
			t_sample rdiv_101 = safediv(((int)1), slide_1);
			t_sample phasor_102 = __m_phasor_114(rdiv_101, samples_to_seconds);
			t_sample mul_98 = (phasor_102 * ((int)2));
			t_sample sub_97 = (mul_98 - ((int)1));
			t_sample cos_96 = cos(sub_97);
			t_sample sub_95 = (cos_96 - ((t_sample)0.5));
			t_sample mul_94 = (sub_95 * ((int)10));
			t_sample clamp_93 = ((mul_94 <= ((int)0)) ? ((int)0) : ((mul_94 >= ((int)1)) ? ((int)1) : mul_94));
			t_sample fold_86 = fold(phasor_102, ((int)0), ((int)1));
			double sample_index_115 = (fold_86 * (loop3_dim - 1));
			int index_trunc_116 = fixnan(floor(sample_index_115));
			double index_fract_117 = (sample_index_115 - index_trunc_116);
			int index_trunc_118 = (index_trunc_116 - 1);
			int index_trunc_119 = (index_trunc_116 + 1);
			int index_trunc_120 = (index_trunc_116 + 2);
			bool index_ignore_121 = ((index_trunc_118 >= loop3_dim) || (index_trunc_118 < 0));
			bool index_ignore_122 = ((index_trunc_116 >= loop3_dim) || (index_trunc_116 < 0));
			bool index_ignore_123 = ((index_trunc_119 >= loop3_dim) || (index_trunc_119 < 0));
			bool index_ignore_124 = ((index_trunc_120 >= loop3_dim) || (index_trunc_120 < 0));
			// phase loop3 channel 1;
			double read_loop_125 = (index_ignore_121 ? 0 : m_loop_36.read(index_trunc_118, 0));
			double read_loop_126 = (index_ignore_122 ? 0 : m_loop_36.read(index_trunc_116, 0));
			double read_loop_127 = (index_ignore_123 ? 0 : m_loop_36.read(index_trunc_119, 0));
			double read_loop_128 = (index_ignore_124 ? 0 : m_loop_36.read(index_trunc_120, 0));
			double readinterp_129 = spline_interp(index_fract_117, read_loop_125, read_loop_126, read_loop_127, read_loop_128);
			t_sample sample_loop_91 = readinterp_129;
			t_sample index_loop_92 = sample_index_115;
			t_sample mul_85 = (sample_loop_91 * clamp_93);
			t_sample mix_21071 = (in1 + (gen_249 * (mul_85 - in1)));
			t_sample mul_62 = (mix_21071 * slide_65);
			t_sample clamp_40 = ((mul_62 <= min_130) ? min_130 : ((mul_62 >= ((int)1)) ? ((int)1) : mul_62));
			int index_wrap_131 = ((switch_53 < 0) ? ((loop3_dim - 1) + ((switch_53 + 1) % loop3_dim)) : (switch_53 % loop3_dim));
			m_loop_36.write((clamp_40 + (m_loop_36.read(index_wrap_131, 0) * slide_391)), index_wrap_131, 0);
			double sample_index_132 = (fold_86 * (loop3_dim - 1));
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
			double read_loop_143 = ((chan_ignore_142 || index_ignore_138) ? 0 : m_loop_36.read(index_trunc_135, 1));
			double read_loop_144 = ((chan_ignore_142 || index_ignore_139) ? 0 : m_loop_36.read(index_trunc_133, 1));
			double read_loop_145 = ((chan_ignore_142 || index_ignore_140) ? 0 : m_loop_36.read(index_trunc_136, 1));
			double read_loop_146 = ((chan_ignore_142 || index_ignore_141) ? 0 : m_loop_36.read(index_trunc_137, 1));
			double readinterp_147 = spline_interp(index_fract_134, read_loop_143, read_loop_144, read_loop_145, read_loop_146);
			t_sample sample_loop_89 = readinterp_147;
			t_sample index_loop_90 = sample_index_132;
			t_sample mul_84 = (sample_loop_89 * clamp_93);
			t_sample mix_21072 = (in2 + (gen_249 * (mul_84 - in2)));
			t_sample clamp_32 = ((mix_21072 <= min_148) ? min_148 : ((mix_21072 >= ((int)1)) ? ((int)1) : mix_21072));
			t_sample mul_59 = (clamp_32 * slide_65);
			t_sample clamp_37 = ((mul_59 <= min_149) ? min_149 : ((mul_59 >= ((int)1)) ? ((int)1) : mul_59));
			int index_wrap_151 = ((switch_50 < 0) ? ((loop3_dim - 1) + ((switch_50 + 1) % loop3_dim)) : (switch_50 % loop3_dim));
			if ((!chan_ignore_150)) {
				m_loop_36.write((clamp_37 + (m_loop_36.read(index_wrap_151, ((int)1)) * slide_391)), index_wrap_151, ((int)1));
				
			};
			t_sample mix_21073 = (m_history_3 + (((t_sample)0.0042742627044161) * (m_ctrl_31 - m_history_3)));
			t_sample mix_20743 = mix_21073;
			t_sample mix_21074 = (m_history_2 + (((t_sample)0.0042742627044161) * (mix_20743 - m_history_2)));
			t_sample mix_20749 = mix_21074;
			t_sample mix_21075 = (m_history_1 + (((t_sample)0.0042742627044161) * (mix_20749 - m_history_1)));
			t_sample mix_20744 = mix_21075;
			t_sample gen_209 = mix_20744;
			t_sample history_193_next_20741 = fixdenorm(mix_20743);
			t_sample history_191_next_20747 = fixdenorm(mix_20749);
			t_sample history_189_next_20742 = fixdenorm(mix_20744);
			t_sample sub_21079 = (gen_209 - ((int)0));
			t_sample scale_21076 = ((safepow((sub_21079 * ((t_sample)1)), ((int)1)) * ((int)2)) + (-1));
			t_sample abs_7 = fabs(scale_21076);
			t_sample sub_21083 = (abs_7 - ((int)1));
			t_sample scale_21080 = ((safepow((sub_21083 * ((t_sample)-1)), ((int)1)) * ((t_sample)1.5)) + ((t_sample)0.5));
			__m_slide_152 = fixdenorm((__m_slide_152 + (((scale_21080 > __m_slide_152) ? iup_153 : idown_154) * (scale_21080 - __m_slide_152))));
			t_sample slide_5 = __m_slide_152;
			t_sample rdiv_123 = safediv(((int)1), slide_5);
			t_sample phasor_124 = __m_phasor_155(rdiv_123, samples_to_seconds);
			t_sample mul_120 = (phasor_124 * ((int)2));
			t_sample sub_119 = (mul_120 - ((int)1));
			t_sample cos_118 = cos(sub_119);
			t_sample sub_117 = (cos_118 - ((t_sample)0.5));
			t_sample mul_116 = (sub_117 * ((int)10));
			t_sample clamp_115 = ((mul_116 <= ((int)0)) ? ((int)0) : ((mul_116 >= ((int)1)) ? ((int)1) : mul_116));
			t_sample fold_108 = fold(phasor_124, ((int)0), ((int)1));
			double sample_index_156 = (fold_108 * (loop2_dim - 1));
			int index_trunc_157 = fixnan(floor(sample_index_156));
			double index_fract_158 = (sample_index_156 - index_trunc_157);
			int index_trunc_159 = (index_trunc_157 - 1);
			int index_trunc_160 = (index_trunc_157 + 1);
			int index_trunc_161 = (index_trunc_157 + 2);
			bool index_ignore_162 = ((index_trunc_159 >= loop2_dim) || (index_trunc_159 < 0));
			bool index_ignore_163 = ((index_trunc_157 >= loop2_dim) || (index_trunc_157 < 0));
			bool index_ignore_164 = ((index_trunc_160 >= loop2_dim) || (index_trunc_160 < 0));
			bool index_ignore_165 = ((index_trunc_161 >= loop2_dim) || (index_trunc_161 < 0));
			// phase loop2 channel 1;
			double read_loop_167 = ((chan_ignore_166 || index_ignore_162) ? 0 : m_loop_29.read(index_trunc_159, 1));
			double read_loop_168 = ((chan_ignore_166 || index_ignore_163) ? 0 : m_loop_29.read(index_trunc_157, 1));
			double read_loop_169 = ((chan_ignore_166 || index_ignore_164) ? 0 : m_loop_29.read(index_trunc_160, 1));
			double read_loop_170 = ((chan_ignore_166 || index_ignore_165) ? 0 : m_loop_29.read(index_trunc_161, 1));
			double readinterp_171 = spline_interp(index_fract_158, read_loop_167, read_loop_168, read_loop_169, read_loop_170);
			t_sample sample_loop_111 = readinterp_171;
			t_sample index_loop_112 = sample_index_156;
			t_sample mul_106 = (sample_loop_111 * clamp_115);
			t_sample mix_21084 = (in2 + (gen_249 * (mul_106 - in2)));
			t_sample clamp_34 = ((mix_21084 <= min_172) ? min_172 : ((mix_21084 >= ((int)1)) ? ((int)1) : mix_21084));
			t_sample mul_60 = (clamp_34 * slide_66);
			t_sample clamp_38 = ((mul_60 <= min_173) ? min_173 : ((mul_60 >= ((int)1)) ? ((int)1) : mul_60));
			int index_wrap_175 = ((switch_51 < 0) ? ((loop2_dim - 1) + ((switch_51 + 1) % loop2_dim)) : (switch_51 % loop2_dim));
			if ((!chan_ignore_174)) {
				m_loop_29.write((clamp_38 + (m_loop_29.read(index_wrap_175, ((int)1)) * slide_391)), index_wrap_175, ((int)1));
				
			};
			t_sample mix_21085 = (mul_153 + (((t_sample)0.5) * (mul_106 - mul_153)));
			t_sample mix_21086 = (mix_21085 + (((t_sample)0.66) * (mul_84 - mix_21085)));
			t_sample mul_393 = (mix_21086 * ((int)3));
			t_sample mix_21087 = (in2 + (gen_213 * (mul_393 - in2)));
			t_sample clamp_77 = ((mix_21087 <= min_176) ? min_176 : ((mix_21087 >= ((int)1)) ? ((int)1) : mix_21087));
			t_sample out2 = clamp_77;
			t_sample fold_995 = fold(clamp_77, (-1), ((int)0));
			t_sample out6 = fold_995;
			double sample_index_177 = (fold_108 * (loop2_dim - 1));
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
			double read_loop_187 = (index_ignore_183 ? 0 : m_loop_29.read(index_trunc_180, 0));
			double read_loop_188 = (index_ignore_184 ? 0 : m_loop_29.read(index_trunc_178, 0));
			double read_loop_189 = (index_ignore_185 ? 0 : m_loop_29.read(index_trunc_181, 0));
			double read_loop_190 = (index_ignore_186 ? 0 : m_loop_29.read(index_trunc_182, 0));
			double readinterp_191 = spline_interp(index_fract_179, read_loop_187, read_loop_188, read_loop_189, read_loop_190);
			t_sample sample_loop_113 = readinterp_191;
			t_sample index_loop_114 = sample_index_177;
			t_sample mul_107 = (sample_loop_113 * clamp_115);
			t_sample mix_21088 = (in1 + (gen_249 * (mul_107 - in1)));
			t_sample clamp_44 = ((mix_21088 <= min_192) ? min_192 : ((mix_21088 >= ((int)1)) ? ((int)1) : mix_21088));
			t_sample mul_63 = (clamp_44 * slide_66);
			t_sample clamp_41 = ((mul_63 <= min_193) ? min_193 : ((mul_63 >= ((int)1)) ? ((int)1) : mul_63));
			int index_wrap_194 = ((switch_52 < 0) ? ((loop2_dim - 1) + ((switch_52 + 1) % loop2_dim)) : (switch_52 % loop2_dim));
			m_loop_29.write((clamp_41 + (m_loop_29.read(index_wrap_194, 0) * slide_391)), index_wrap_194, 0);
			t_sample mix_21089 = (mul_152 + (((t_sample)0.5) * (mul_107 - mul_152)));
			t_sample mix_21090 = (mix_21089 + (((t_sample)0.66) * (mul_85 - mix_21089)));
			t_sample mul_392 = (mix_21090 * ((int)3));
			t_sample mix_21091 = (in1 + (gen_213 * (mul_392 - in1)));
			t_sample clamp_78 = ((mix_21091 <= min_195) ? min_195 : ((mix_21091 >= ((int)1)) ? ((int)1) : mix_21091));
			t_sample out1 = clamp_78;
			t_sample fold_400 = fold(clamp_78, (-1), ((int)0));
			t_sample out5 = fold_400;
			m_history_22 = history_193_next_199;
			m_history_20 = history_189_next_201;
			m_history_21 = history_191_next_200;
			m_history_19 = history_223_next_230;
			m_history_18 = history_193_next_20676;
			m_history_16 = history_189_next_20681;
			m_history_17 = history_191_next_20675;
			m_history_15 = history_193_next_20693;
			m_history_13 = history_189_next_20695;
			m_history_14 = history_191_next_20692;
			m_history_12 = history_193_next_20706;
			m_history_10 = history_189_next_20708;
			m_history_11 = history_191_next_20705;
			m_history_9 = history_193_next_20715;
			m_history_7 = history_189_next_20716;
			m_history_8 = history_191_next_20719;
			m_history_6 = history_193_next_20728;
			m_history_4 = history_189_next_20729;
			m_history_5 = history_191_next_20733;
			m_history_3 = history_193_next_20741;
			m_history_1 = history_189_next_20742;
			m_history_2 = history_191_next_20747;
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
	inline void set_ctrl4(t_param _value) {
		m_ctrl_24 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_ctrl1(t_param _value) {
		m_ctrl_25 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_button(t_param _value) {
		m_button_26 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw1(t_param _value) {
		m_sw_27 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_ctrl7(t_param _value) {
		m_ctrl_28 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_loop2(void * _value) {
		m_loop_29.setbuffer(_value);
	};
	inline void set_loop1(void * _value) {
		m_loop_30.setbuffer(_value);
	};
	inline void set_ctrl3(t_param _value) {
		m_ctrl_31 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_ctrl2(t_param _value) {
		m_ctrl_32 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_gate(t_param _value) {
		m_gate_33 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_ctrl5(t_param _value) {
		m_ctrl_34 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_ctrl6(t_param _value) {
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
		case 1: *value = self->m_ctrl_25; break;
		case 2: *value = self->m_ctrl_32; break;
		case 3: *value = self->m_ctrl_31; break;
		case 4: *value = self->m_ctrl_24; break;
		case 5: *value = self->m_ctrl_34; break;
		case 6: *value = self->m_ctrl_35; break;
		case 7: *value = self->m_ctrl_28; break;
		case 8: *value = self->m_gate_33; break;
		
		
		
		case 12: *value = self->m_sw_27; break;
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
	// initialize parameter 1 ("m_ctrl_25")
	pi = self->__commonstate.params + 1;
	pi->name = "ctrl1";
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
	// initialize parameter 2 ("m_ctrl_32")
	pi = self->__commonstate.params + 2;
	pi->name = "ctrl2";
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
	// initialize parameter 3 ("m_ctrl_31")
	pi = self->__commonstate.params + 3;
	pi->name = "ctrl3";
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
	// initialize parameter 4 ("m_ctrl_24")
	pi = self->__commonstate.params + 4;
	pi->name = "ctrl4";
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
	// initialize parameter 6 ("m_ctrl_35")
	pi = self->__commonstate.params + 6;
	pi->name = "ctrl6";
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
	// initialize parameter 9 ("m_loop_30")
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
	// initialize parameter 10 ("m_loop_29")
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
	// initialize parameter 12 ("m_sw_27")
	pi = self->__commonstate.params + 12;
	pi->name = "sw1";
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
