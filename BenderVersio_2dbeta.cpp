#include "BenderVersio_2dbeta.h"

namespace BenderVersio_2dbeta {

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
	Data m_loop_28;
	Data m_loop_36;
	Data m_loop_31;
	Delta __m_delta_52;
	Phasor __m_phasor_152;
	Phasor __m_phasor_110;
	Phasor __m_phasor_69;
	PlusEquals __m_pluseq_53;
	int __exception;
	int vectorsize;
	t_sample m_history_7;
	t_sample __m_slide_41;
	t_sample __m_count_44;
	t_sample __m_carry_39;
	t_sample __m_count_37;
	t_sample m_history_3;
	t_sample m_ctrl_35;
	t_sample __m_carry_46;
	t_sample m_gate_33;
	t_sample m_ctrl_34;
	t_sample __m_count_48;
	t_sample __m_carry_50;
	t_sample m_history_2;
	t_sample samples_to_seconds;
	t_sample samplerate;
	t_sample __m_slide_107;
	t_sample m_ctrl_32;
	t_sample __m_slide_66;
	t_sample __m_slide_57;
	t_sample __m_slide_60;
	t_sample m_history_1;
	t_sample __m_slide_54;
	t_sample m_history_6;
	t_sample m_history_4;
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
	t_sample __m_slide_149;
	t_sample m_sw_27;
	t_sample m_history_5;
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
		m_loop_28.reset("loop3", ((int)96000), ((int)2));
		m_ctrl_29 = ((int)0);
		m_ctrl_30 = ((int)0);
		m_loop_31.reset("loop2", ((int)96000), ((int)2));
		m_ctrl_32 = ((int)0);
		m_gate_33 = ((int)0);
		m_ctrl_34 = ((int)0);
		m_ctrl_35 = ((int)0);
		m_loop_36.reset("loop1", ((int)96000), ((int)2));
		__m_count_37 = 0;
		__m_carry_39 = 0;
		__m_slide_41 = 0;
		__m_count_44 = 0;
		__m_carry_46 = 0;
		__m_count_48 = 0;
		__m_carry_50 = 0;
		__m_delta_52.reset(0);
		__m_pluseq_53.reset(0);
		__m_slide_54 = 0;
		__m_slide_57 = 0;
		__m_slide_60 = 0;
		__m_slide_66 = 0;
		samples_to_seconds = (1 / samplerate);
		__m_phasor_69.reset(0);
		__m_slide_107 = 0;
		__m_phasor_110.reset(0);
		__m_slide_149 = 0;
		__m_phasor_152.reset(0);
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
		int loop1_dim = m_loop_36.dim;
		int loop1_channels = m_loop_36.channels;
		int loop1_dim_833 = loop1_dim;
		int loop2_dim = m_loop_31.dim;
		int loop2_channels = m_loop_31.channels;
		int loop2_dim_753 = loop2_dim;
		int loop3_dim = m_loop_28.dim;
		int loop3_channels = m_loop_28.channels;
		int loop3_dim_673 = loop3_dim;
		t_sample iup_42 = (1 / maximum(1, abs(((int)4000))));
		t_sample idown_43 = (1 / maximum(1, abs(((int)4000))));
		int or_233 = (m_gate_33 || m_button_26);
		int gt_361 = (or_233 > ((int)0));
		int eq_183 = (m_sw_27 == ((int)0));
		t_sample iup_55 = (1 / maximum(1, abs(((int)4000))));
		t_sample idown_56 = (1 / maximum(1, abs(((int)4000))));
		t_sample iup_58 = (1 / maximum(1, abs(((int)4000))));
		t_sample idown_59 = (1 / maximum(1, abs(((int)4000))));
		t_sample iup_61 = (1 / maximum(1, abs(((int)4000))));
		t_sample idown_62 = (1 / maximum(1, abs(((int)4000))));
		int eq_187 = (m_sw_27 == ((t_sample)0.5));
		t_sample switch_186 = (eq_187 ? ((int)0) : m_sw_27);
		t_sample switch_184 = (eq_183 ? ((t_sample)0.5) : switch_186);
		t_sample sub_1269 = (switch_184 - ((int)0));
		t_sample scale_1266 = ((safepow((sub_1269 * ((t_sample)1)), ((int)1)) * ((int)2)) + ((int)1));
		t_sample choice_63 = int(scale_1266);
		t_sample choice_64 = int(scale_1266);
		t_sample choice_65 = int(scale_1266);
		t_sample iup_67 = (1 / maximum(1, abs(((int)4000))));
		t_sample idown_68 = (1 / maximum(1, abs(((int)4000))));
		samples_to_seconds = (1 / samplerate);
		int min_85 = (-1);
		bool chan_ignore_97 = ((1 < 0) || (1 >= loop3_channels));
		int min_103 = (-1);
		int min_104 = (-1);
		bool chan_ignore_105 = ((((int)1) < 0) || (((int)1) >= loop3_channels));
		t_sample iup_108 = (1 / maximum(1, abs(((int)4000))));
		t_sample idown_109 = (1 / maximum(1, abs(((int)4000))));
		bool chan_ignore_121 = ((1 < 0) || (1 >= loop2_channels));
		int min_127 = (-1);
		int min_128 = (-1);
		bool chan_ignore_129 = ((((int)1) < 0) || (((int)1) >= loop2_channels));
		int min_146 = (-1);
		int min_147 = (-1);
		t_sample iup_150 = (1 / maximum(1, abs(((int)4000))));
		t_sample idown_151 = (1 / maximum(1, abs(((int)4000))));
		bool chan_ignore_163 = ((1 < 0) || (1 >= loop1_channels));
		int min_169 = (-1);
		int min_170 = (-1);
		bool chan_ignore_171 = ((((int)1) < 0) || (((int)1) >= loop1_channels));
		int min_173 = (-1);
		int min_189 = (-1);
		int min_190 = (-1);
		int min_192 = (-1);
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			const t_sample in2 = (*(__in2++));
			t_sample out8 = ((int)0);
			t_sample out9 = ((int)0);
			t_sample out7 = ((int)0);
			t_sample out10 = ((int)0);
			__m_count_37 = (((int)0) ? 0 : (fixdenorm(__m_count_37 + ((int)1))));
			int carry_38 = 0;
			if ((((int)0) != 0)) {
				__m_count_37 = 0;
				__m_carry_39 = 0;
				
			} else if (((loop3_dim_673 > 0) && (__m_count_37 >= loop3_dim_673))) {
				int wraps_40 = (__m_count_37 / loop3_dim_673);
				__m_carry_39 = (__m_carry_39 + wraps_40);
				__m_count_37 = (__m_count_37 - (wraps_40 * loop3_dim_673));
				carry_38 = 1;
				
			};
			int counter_132 = __m_count_37;
			int counter_133 = carry_38;
			int counter_134 = __m_carry_39;
			t_sample mix_1238 = (m_history_22 + (((t_sample)0.0042742627044161) * (m_ctrl_32 - m_history_22)));
			t_sample mix_192 = mix_1238;
			t_sample mix_1239 = (m_history_21 + (((t_sample)0.0042742627044161) * (mix_192 - m_history_21)));
			t_sample mix_190 = mix_1239;
			t_sample mix_1240 = (m_history_20 + (((t_sample)0.0042742627044161) * (mix_190 - m_history_20)));
			t_sample mix_188 = mix_1240;
			t_sample gen_207 = mix_188;
			t_sample history_193_next_199 = fixdenorm(mix_192);
			t_sample history_191_next_200 = fixdenorm(mix_190);
			t_sample history_189_next_201 = fixdenorm(mix_188);
			__m_slide_41 = fixdenorm((__m_slide_41 + (((gen_207 > __m_slide_41) ? iup_42 : idown_43) * (gen_207 - __m_slide_41))));
			t_sample slide_391 = __m_slide_41;
			t_sample fold_9 = fold(in2, (-1), ((int)0));
			__m_count_44 = (((int)0) ? 0 : (fixdenorm(__m_count_44 + ((int)1))));
			int carry_45 = 0;
			if ((((int)0) != 0)) {
				__m_count_44 = 0;
				__m_carry_46 = 0;
				
			} else if (((loop2_dim_753 > 0) && (__m_count_44 >= loop2_dim_753))) {
				int wraps_47 = (__m_count_44 / loop2_dim_753);
				__m_carry_46 = (__m_carry_46 + wraps_47);
				__m_count_44 = (__m_count_44 - (wraps_47 * loop2_dim_753));
				carry_45 = 1;
				
			};
			int counter_136 = __m_count_44;
			int counter_137 = carry_45;
			int counter_138 = __m_carry_46;
			t_sample fold_374 = fold(in1, (-1), ((int)0));
			__m_count_48 = (((int)0) ? 0 : (fixdenorm(__m_count_48 + ((int)1))));
			int carry_49 = 0;
			if ((((int)0) != 0)) {
				__m_count_48 = 0;
				__m_carry_50 = 0;
				
			} else if (((loop1_dim_833 > 0) && (__m_count_48 >= loop1_dim_833))) {
				int wraps_51 = (__m_count_48 / loop1_dim_833);
				__m_carry_50 = (__m_carry_50 + wraps_51);
				__m_count_48 = (__m_count_48 - (wraps_51 * loop1_dim_833));
				carry_49 = 1;
				
			};
			int counter_144 = __m_count_48;
			int counter_145 = carry_49;
			int counter_146 = __m_carry_50;
			int delta_226 = __m_delta_52(or_233);
			int gtep_225 = ((delta_226 >= ((int)1)) ? delta_226 : 0);
			t_sample plusequals_224 = __m_pluseq_53.post(gtep_225, m_history_19, 0);
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
			t_sample mix_1241 = (m_history_18 + (((t_sample)0.0042742627044161) * (m_ctrl_25 - m_history_18)));
			t_sample mix_998 = mix_1241;
			t_sample mix_1242 = (m_history_17 + (((t_sample)0.0042742627044161) * (mix_998 - m_history_17)));
			t_sample mix_1003 = mix_1242;
			t_sample mix_1243 = (m_history_16 + (((t_sample)0.0042742627044161) * (mix_1003 - m_history_16)));
			t_sample mix_997 = mix_1243;
			t_sample gen_213 = mix_997;
			t_sample history_193_next_1001 = fixdenorm(mix_998);
			t_sample history_191_next_1000 = fixdenorm(mix_1003);
			t_sample history_189_next_1004 = fixdenorm(mix_997);
			t_sample mix_1244 = (m_history_15 + (((t_sample)0.0042742627044161) * (m_ctrl_29 - m_history_15)));
			t_sample mix_1011 = mix_1244;
			t_sample mix_1245 = (m_history_14 + (((t_sample)0.0042742627044161) * (mix_1011 - m_history_14)));
			t_sample mix_1016 = mix_1245;
			t_sample mix_1246 = (m_history_13 + (((t_sample)0.0042742627044161) * (mix_1016 - m_history_13)));
			t_sample mix_1010 = mix_1246;
			t_sample gen_249 = mix_1010;
			t_sample history_193_next_1014 = fixdenorm(mix_1011);
			t_sample history_191_next_1013 = fixdenorm(mix_1016);
			t_sample history_189_next_1017 = fixdenorm(mix_1010);
			t_sample mix_1247 = (m_history_12 + (((t_sample)0.0042742627044161) * (m_ctrl_24 - m_history_12)));
			t_sample mix_1024 = mix_1247;
			t_sample mix_1248 = (m_history_11 + (((t_sample)0.0042742627044161) * (mix_1024 - m_history_11)));
			t_sample mix_1031 = mix_1248;
			t_sample mix_1249 = (m_history_10 + (((t_sample)0.0042742627044161) * (mix_1031 - m_history_10)));
			t_sample mix_1023 = mix_1249;
			t_sample gen_203 = mix_1023;
			t_sample history_193_next_1028 = fixdenorm(mix_1024);
			t_sample history_191_next_1027 = fixdenorm(mix_1031);
			t_sample history_189_next_1030 = fixdenorm(mix_1023);
			t_sample sub_1253 = (gen_203 - ((int)0));
			t_sample scale_1250 = ((safepow((sub_1253 * ((t_sample)1)), ((int)1)) * ((int)2)) + (-1));
			t_sample gtep_68 = ((scale_1250 >= ((int)0)) ? scale_1250 : 0);
			__m_slide_54 = fixdenorm((__m_slide_54 + (((gtep_68 > __m_slide_54) ? iup_55 : idown_56) * (gtep_68 - __m_slide_54))));
			t_sample slide_65 = __m_slide_54;
			t_sample sub_1257 = (gen_203 - ((int)0));
			t_sample scale_1254 = ((safepow((sub_1257 * ((t_sample)1)), ((int)1)) * ((int)2)) + (-1));
			t_sample abs_73 = fabs(scale_1254);
			t_sample sub_1261 = (abs_73 - ((int)1));
			t_sample scale_1258 = ((safepow((sub_1261 * ((t_sample)-1)), ((int)1)) * ((int)1)) + ((int)0));
			__m_slide_57 = fixdenorm((__m_slide_57 + (((scale_1258 > __m_slide_57) ? iup_58 : idown_59) * (scale_1258 - __m_slide_57))));
			t_sample slide_66 = __m_slide_57;
			t_sample sub_1265 = (gen_203 - ((int)0));
			t_sample scale_1262 = ((safepow((sub_1265 * ((t_sample)1)), ((int)1)) * ((int)2)) + (-1));
			t_sample ltep_70 = ((scale_1262 <= ((int)0)) ? scale_1262 : 0);
			t_sample abs_71 = fabs(ltep_70);
			__m_slide_60 = fixdenorm((__m_slide_60 + (((abs_71 > __m_slide_60) ? iup_61 : idown_62) * (abs_71 - __m_slide_60))));
			t_sample slide_67 = __m_slide_60;
			t_sample selector_355 = ((choice_63 >= 3) ? gt_362 : ((choice_63 >= 2) ? ((int)1) : ((choice_63 >= 1) ? gt_361 : 0)));
			int switch_53 = (selector_355 ? counter_132 : ((int)0));
			int switch_51 = (selector_355 ? counter_136 : ((int)0));
			int switch_54 = (selector_355 ? counter_144 : ((int)0));
			int switch_56 = (selector_355 ? counter_144 : ((int)0));
			int switch_50 = (selector_355 ? counter_132 : ((int)0));
			int switch_52 = (selector_355 ? counter_136 : ((int)0));
			t_sample selector_12 = ((choice_64 >= 3) ? gt_362 : ((choice_64 >= 2) ? ((int)1) : ((choice_64 >= 1) ? gt_361 : 0)));
			t_sample switch_14 = (selector_12 ? rsub_13 : fold_9);
			t_sample out4 = switch_14;
			t_sample selector_368 = ((choice_65 >= 3) ? gt_362 : ((choice_65 >= 2) ? ((int)1) : ((choice_65 >= 1) ? gt_361 : 0)));
			t_sample switch_363 = (selector_368 ? rsub_373 : fold_374);
			t_sample out3 = switch_363;
			t_sample mix_1270 = (m_history_9 + (((t_sample)0.0042742627044161) * (m_ctrl_35 - m_history_9)));
			t_sample mix_1043 = mix_1270;
			t_sample mix_1271 = (m_history_8 + (((t_sample)0.0042742627044161) * (mix_1043 - m_history_8)));
			t_sample mix_1042 = mix_1271;
			t_sample mix_1272 = (m_history_7 + (((t_sample)0.0042742627044161) * (mix_1042 - m_history_7)));
			t_sample mix_1037 = mix_1272;
			t_sample gen_205 = mix_1037;
			t_sample history_193_next_1036 = fixdenorm(mix_1043);
			t_sample history_191_next_1040 = fixdenorm(mix_1042);
			t_sample history_189_next_1044 = fixdenorm(mix_1037);
			t_sample sub_1276 = (gen_205 - ((int)0));
			t_sample scale_1273 = ((safepow((sub_1276 * ((t_sample)1)), ((int)1)) * ((int)2)) + (-1));
			t_sample abs_3 = fabs(scale_1273);
			t_sample sub_1280 = (abs_3 - ((int)1));
			t_sample scale_1277 = ((safepow((sub_1280 * ((t_sample)-1)), ((int)1)) * ((t_sample)1.5)) + ((t_sample)0.5));
			__m_slide_66 = fixdenorm((__m_slide_66 + (((scale_1277 > __m_slide_66) ? iup_67 : idown_68) * (scale_1277 - __m_slide_66))));
			t_sample slide_1 = __m_slide_66;
			t_sample rdiv_101 = safediv(((int)1), slide_1);
			t_sample phasor_102 = __m_phasor_69(rdiv_101, samples_to_seconds);
			t_sample mul_98 = (phasor_102 * ((int)2));
			t_sample sub_97 = (mul_98 - ((int)1));
			t_sample cos_96 = cos(sub_97);
			t_sample sub_95 = (cos_96 - ((t_sample)0.5));
			t_sample mul_94 = (sub_95 * ((int)10));
			t_sample clamp_93 = ((mul_94 <= ((int)0)) ? ((int)0) : ((mul_94 >= ((int)1)) ? ((int)1) : mul_94));
			t_sample fold_86 = fold(phasor_102, ((int)0), ((int)1));
			double sample_index_70 = (fold_86 * (loop3_dim - 1));
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
			double read_loop_80 = (index_ignore_76 ? 0 : m_loop_28.read(index_trunc_73, 0));
			double read_loop_81 = (index_ignore_77 ? 0 : m_loop_28.read(index_trunc_71, 0));
			double read_loop_82 = (index_ignore_78 ? 0 : m_loop_28.read(index_trunc_74, 0));
			double read_loop_83 = (index_ignore_79 ? 0 : m_loop_28.read(index_trunc_75, 0));
			double readinterp_84 = spline_interp(index_fract_72, read_loop_80, read_loop_81, read_loop_82, read_loop_83);
			t_sample sample_loop_91 = readinterp_84;
			t_sample index_loop_92 = sample_index_70;
			t_sample mul_85 = (sample_loop_91 * clamp_93);
			t_sample mix_1281 = (in1 + (gen_249 * (mul_85 - in1)));
			t_sample mul_62 = (mix_1281 * slide_65);
			t_sample clamp_40 = ((mul_62 <= min_85) ? min_85 : ((mul_62 >= ((int)1)) ? ((int)1) : mul_62));
			int index_wrap_86 = ((switch_53 < 0) ? ((loop3_dim - 1) + ((switch_53 + 1) % loop3_dim)) : (switch_53 % loop3_dim));
			m_loop_28.write((clamp_40 + (m_loop_28.read(index_wrap_86, 0) * slide_391)), index_wrap_86, 0);
			double sample_index_87 = (fold_86 * (loop3_dim - 1));
			int index_trunc_88 = fixnan(floor(sample_index_87));
			double index_fract_89 = (sample_index_87 - index_trunc_88);
			int index_trunc_90 = (index_trunc_88 - 1);
			int index_trunc_91 = (index_trunc_88 + 1);
			int index_trunc_92 = (index_trunc_88 + 2);
			bool index_ignore_93 = ((index_trunc_90 >= loop3_dim) || (index_trunc_90 < 0));
			bool index_ignore_94 = ((index_trunc_88 >= loop3_dim) || (index_trunc_88 < 0));
			bool index_ignore_95 = ((index_trunc_91 >= loop3_dim) || (index_trunc_91 < 0));
			bool index_ignore_96 = ((index_trunc_92 >= loop3_dim) || (index_trunc_92 < 0));
			// phase loop3 channel 1;
			double read_loop_98 = ((chan_ignore_97 || index_ignore_93) ? 0 : m_loop_28.read(index_trunc_90, 1));
			double read_loop_99 = ((chan_ignore_97 || index_ignore_94) ? 0 : m_loop_28.read(index_trunc_88, 1));
			double read_loop_100 = ((chan_ignore_97 || index_ignore_95) ? 0 : m_loop_28.read(index_trunc_91, 1));
			double read_loop_101 = ((chan_ignore_97 || index_ignore_96) ? 0 : m_loop_28.read(index_trunc_92, 1));
			double readinterp_102 = spline_interp(index_fract_89, read_loop_98, read_loop_99, read_loop_100, read_loop_101);
			t_sample sample_loop_89 = readinterp_102;
			t_sample index_loop_90 = sample_index_87;
			t_sample mul_84 = (sample_loop_89 * clamp_93);
			t_sample mix_1282 = (in2 + (gen_249 * (mul_84 - in2)));
			t_sample clamp_32 = ((mix_1282 <= min_103) ? min_103 : ((mix_1282 >= ((int)1)) ? ((int)1) : mix_1282));
			t_sample mul_59 = (clamp_32 * slide_65);
			t_sample clamp_37 = ((mul_59 <= min_104) ? min_104 : ((mul_59 >= ((int)1)) ? ((int)1) : mul_59));
			int index_wrap_106 = ((switch_50 < 0) ? ((loop3_dim - 1) + ((switch_50 + 1) % loop3_dim)) : (switch_50 % loop3_dim));
			if ((!chan_ignore_105)) {
				m_loop_28.write((clamp_37 + (m_loop_28.read(index_wrap_106, ((int)1)) * slide_391)), index_wrap_106, ((int)1));
				
			};
			t_sample mix_1283 = (m_history_6 + (((t_sample)0.0042742627044161) * (m_ctrl_30 - m_history_6)));
			t_sample mix_1054 = mix_1283;
			t_sample mix_1284 = (m_history_5 + (((t_sample)0.0042742627044161) * (mix_1054 - m_history_5)));
			t_sample mix_1056 = mix_1284;
			t_sample mix_1285 = (m_history_4 + (((t_sample)0.0042742627044161) * (mix_1056 - m_history_4)));
			t_sample mix_1050 = mix_1285;
			t_sample gen_209 = mix_1050;
			t_sample history_193_next_1049 = fixdenorm(mix_1054);
			t_sample history_191_next_1053 = fixdenorm(mix_1056);
			t_sample history_189_next_1057 = fixdenorm(mix_1050);
			t_sample sub_1289 = (gen_209 - ((int)0));
			t_sample scale_1286 = ((safepow((sub_1289 * ((t_sample)1)), ((int)1)) * ((int)2)) + (-1));
			t_sample abs_7 = fabs(scale_1286);
			t_sample sub_1293 = (abs_7 - ((int)1));
			t_sample scale_1290 = ((safepow((sub_1293 * ((t_sample)-1)), ((int)1)) * ((t_sample)1.5)) + ((t_sample)0.5));
			__m_slide_107 = fixdenorm((__m_slide_107 + (((scale_1290 > __m_slide_107) ? iup_108 : idown_109) * (scale_1290 - __m_slide_107))));
			t_sample slide_5 = __m_slide_107;
			t_sample rdiv_123 = safediv(((int)1), slide_5);
			t_sample phasor_124 = __m_phasor_110(rdiv_123, samples_to_seconds);
			t_sample mul_120 = (phasor_124 * ((int)2));
			t_sample sub_119 = (mul_120 - ((int)1));
			t_sample cos_118 = cos(sub_119);
			t_sample sub_117 = (cos_118 - ((t_sample)0.5));
			t_sample mul_116 = (sub_117 * ((int)10));
			t_sample clamp_115 = ((mul_116 <= ((int)0)) ? ((int)0) : ((mul_116 >= ((int)1)) ? ((int)1) : mul_116));
			t_sample fold_108 = fold(phasor_124, ((int)0), ((int)1));
			double sample_index_111 = (fold_108 * (loop2_dim - 1));
			int index_trunc_112 = fixnan(floor(sample_index_111));
			double index_fract_113 = (sample_index_111 - index_trunc_112);
			int index_trunc_114 = (index_trunc_112 - 1);
			int index_trunc_115 = (index_trunc_112 + 1);
			int index_trunc_116 = (index_trunc_112 + 2);
			bool index_ignore_117 = ((index_trunc_114 >= loop2_dim) || (index_trunc_114 < 0));
			bool index_ignore_118 = ((index_trunc_112 >= loop2_dim) || (index_trunc_112 < 0));
			bool index_ignore_119 = ((index_trunc_115 >= loop2_dim) || (index_trunc_115 < 0));
			bool index_ignore_120 = ((index_trunc_116 >= loop2_dim) || (index_trunc_116 < 0));
			// phase loop2 channel 1;
			double read_loop_122 = ((chan_ignore_121 || index_ignore_117) ? 0 : m_loop_31.read(index_trunc_114, 1));
			double read_loop_123 = ((chan_ignore_121 || index_ignore_118) ? 0 : m_loop_31.read(index_trunc_112, 1));
			double read_loop_124 = ((chan_ignore_121 || index_ignore_119) ? 0 : m_loop_31.read(index_trunc_115, 1));
			double read_loop_125 = ((chan_ignore_121 || index_ignore_120) ? 0 : m_loop_31.read(index_trunc_116, 1));
			double readinterp_126 = spline_interp(index_fract_113, read_loop_122, read_loop_123, read_loop_124, read_loop_125);
			t_sample sample_loop_111 = readinterp_126;
			t_sample index_loop_112 = sample_index_111;
			t_sample mul_106 = (sample_loop_111 * clamp_115);
			t_sample mix_1294 = (in2 + (gen_249 * (mul_106 - in2)));
			t_sample clamp_34 = ((mix_1294 <= min_127) ? min_127 : ((mix_1294 >= ((int)1)) ? ((int)1) : mix_1294));
			t_sample mul_60 = (clamp_34 * slide_66);
			t_sample clamp_38 = ((mul_60 <= min_128) ? min_128 : ((mul_60 >= ((int)1)) ? ((int)1) : mul_60));
			int index_wrap_130 = ((switch_51 < 0) ? ((loop2_dim - 1) + ((switch_51 + 1) % loop2_dim)) : (switch_51 % loop2_dim));
			if ((!chan_ignore_129)) {
				m_loop_31.write((clamp_38 + (m_loop_31.read(index_wrap_130, ((int)1)) * slide_391)), index_wrap_130, ((int)1));
				
			};
			double sample_index_131 = (fold_108 * (loop2_dim - 1));
			int index_trunc_132 = fixnan(floor(sample_index_131));
			double index_fract_133 = (sample_index_131 - index_trunc_132);
			int index_trunc_134 = (index_trunc_132 - 1);
			int index_trunc_135 = (index_trunc_132 + 1);
			int index_trunc_136 = (index_trunc_132 + 2);
			bool index_ignore_137 = ((index_trunc_134 >= loop2_dim) || (index_trunc_134 < 0));
			bool index_ignore_138 = ((index_trunc_132 >= loop2_dim) || (index_trunc_132 < 0));
			bool index_ignore_139 = ((index_trunc_135 >= loop2_dim) || (index_trunc_135 < 0));
			bool index_ignore_140 = ((index_trunc_136 >= loop2_dim) || (index_trunc_136 < 0));
			// phase loop2 channel 1;
			double read_loop_141 = (index_ignore_137 ? 0 : m_loop_31.read(index_trunc_134, 0));
			double read_loop_142 = (index_ignore_138 ? 0 : m_loop_31.read(index_trunc_132, 0));
			double read_loop_143 = (index_ignore_139 ? 0 : m_loop_31.read(index_trunc_135, 0));
			double read_loop_144 = (index_ignore_140 ? 0 : m_loop_31.read(index_trunc_136, 0));
			double readinterp_145 = spline_interp(index_fract_133, read_loop_141, read_loop_142, read_loop_143, read_loop_144);
			t_sample sample_loop_113 = readinterp_145;
			t_sample index_loop_114 = sample_index_131;
			t_sample mul_107 = (sample_loop_113 * clamp_115);
			t_sample mix_1295 = (in1 + (gen_249 * (mul_107 - in1)));
			t_sample clamp_44 = ((mix_1295 <= min_146) ? min_146 : ((mix_1295 >= ((int)1)) ? ((int)1) : mix_1295));
			t_sample mul_63 = (clamp_44 * slide_66);
			t_sample clamp_41 = ((mul_63 <= min_147) ? min_147 : ((mul_63 >= ((int)1)) ? ((int)1) : mul_63));
			int index_wrap_148 = ((switch_52 < 0) ? ((loop2_dim - 1) + ((switch_52 + 1) % loop2_dim)) : (switch_52 % loop2_dim));
			m_loop_31.write((clamp_41 + (m_loop_31.read(index_wrap_148, 0) * slide_391)), index_wrap_148, 0);
			t_sample mix_1296 = (m_history_3 + (((t_sample)0.0042742627044161) * (m_ctrl_34 - m_history_3)));
			t_sample mix_1064 = mix_1296;
			t_sample mix_1297 = (m_history_2 + (((t_sample)0.0042742627044161) * (mix_1064 - m_history_2)));
			t_sample mix_1069 = mix_1297;
			t_sample mix_1298 = (m_history_1 + (((t_sample)0.0042742627044161) * (mix_1069 - m_history_1)));
			t_sample mix_1063 = mix_1298;
			t_sample gen_211 = mix_1063;
			t_sample history_193_next_1062 = fixdenorm(mix_1064);
			t_sample history_191_next_1067 = fixdenorm(mix_1069);
			t_sample history_189_next_1070 = fixdenorm(mix_1063);
			t_sample sub_1302 = (gen_211 - ((int)0));
			t_sample scale_1299 = ((safepow((sub_1302 * ((t_sample)1)), ((int)1)) * ((int)2)) + (-1));
			t_sample abs_28 = fabs(scale_1299);
			t_sample sub_1306 = (abs_28 - ((int)1));
			t_sample scale_1303 = ((safepow((sub_1306 * ((t_sample)-1)), ((int)1)) * ((t_sample)1.5)) + ((t_sample)0.5));
			__m_slide_149 = fixdenorm((__m_slide_149 + (((scale_1303 > __m_slide_149) ? iup_150 : idown_151) * (scale_1303 - __m_slide_149))));
			t_sample slide_26 = __m_slide_149;
			t_sample rdiv_171 = safediv(((int)1), slide_26);
			t_sample phasor_172 = __m_phasor_152(rdiv_171, samples_to_seconds);
			t_sample mul_159 = (phasor_172 * ((int)2));
			t_sample sub_158 = (mul_159 - ((int)1));
			t_sample cos_157 = cos(sub_158);
			t_sample sub_156 = (cos_157 - ((t_sample)0.5));
			t_sample mul_155 = (sub_156 * ((int)10));
			t_sample clamp_154 = ((mul_155 <= ((int)0)) ? ((int)0) : ((mul_155 >= ((int)1)) ? ((int)1) : mul_155));
			t_sample fold_162 = fold(phasor_172, ((int)0), ((int)1));
			double sample_index_153 = (fold_162 * (loop1_dim - 1));
			int index_trunc_154 = fixnan(floor(sample_index_153));
			double index_fract_155 = (sample_index_153 - index_trunc_154);
			int index_trunc_156 = (index_trunc_154 - 1);
			int index_trunc_157 = (index_trunc_154 + 1);
			int index_trunc_158 = (index_trunc_154 + 2);
			bool index_ignore_159 = ((index_trunc_156 >= loop1_dim) || (index_trunc_156 < 0));
			bool index_ignore_160 = ((index_trunc_154 >= loop1_dim) || (index_trunc_154 < 0));
			bool index_ignore_161 = ((index_trunc_157 >= loop1_dim) || (index_trunc_157 < 0));
			bool index_ignore_162 = ((index_trunc_158 >= loop1_dim) || (index_trunc_158 < 0));
			// phase loop1 channel 1;
			double read_loop_164 = ((chan_ignore_163 || index_ignore_159) ? 0 : m_loop_36.read(index_trunc_156, 1));
			double read_loop_165 = ((chan_ignore_163 || index_ignore_160) ? 0 : m_loop_36.read(index_trunc_154, 1));
			double read_loop_166 = ((chan_ignore_163 || index_ignore_161) ? 0 : m_loop_36.read(index_trunc_157, 1));
			double read_loop_167 = ((chan_ignore_163 || index_ignore_162) ? 0 : m_loop_36.read(index_trunc_158, 1));
			double readinterp_168 = spline_interp(index_fract_155, read_loop_164, read_loop_165, read_loop_166, read_loop_167);
			t_sample sample_loop_166 = readinterp_168;
			t_sample index_loop_167 = sample_index_153;
			t_sample mul_153 = (sample_loop_166 * clamp_154);
			t_sample mix_1307 = (in2 + (gen_249 * (mul_153 - in2)));
			t_sample clamp_36 = ((mix_1307 <= min_169) ? min_169 : ((mix_1307 >= ((int)1)) ? ((int)1) : mix_1307));
			t_sample mul_61 = (clamp_36 * slide_67);
			t_sample clamp_39 = ((mul_61 <= min_170) ? min_170 : ((mul_61 >= ((int)1)) ? ((int)1) : mul_61));
			int index_wrap_172 = ((switch_54 < 0) ? ((loop1_dim - 1) + ((switch_54 + 1) % loop1_dim)) : (switch_54 % loop1_dim));
			if ((!chan_ignore_171)) {
				m_loop_36.write((clamp_39 + (m_loop_36.read(index_wrap_172, ((int)1)) * slide_391)), index_wrap_172, ((int)1));
				
			};
			t_sample mix_1308 = (mul_153 + (((t_sample)0.5) * (mul_106 - mul_153)));
			t_sample mix_1309 = (mix_1308 + (((t_sample)0.66) * (mul_84 - mix_1308)));
			t_sample mul_393 = (mix_1309 * ((int)3));
			t_sample mix_1310 = (in2 + (gen_213 * (mul_393 - in2)));
			t_sample clamp_77 = ((mix_1310 <= min_173) ? min_173 : ((mix_1310 >= ((int)1)) ? ((int)1) : mix_1310));
			t_sample out2 = clamp_77;
			t_sample fold_995 = fold(clamp_77, (-1), ((int)0));
			t_sample out6 = fold_995;
			double sample_index_174 = (fold_162 * (loop1_dim - 1));
			int index_trunc_175 = fixnan(floor(sample_index_174));
			double index_fract_176 = (sample_index_174 - index_trunc_175);
			int index_trunc_177 = (index_trunc_175 - 1);
			int index_trunc_178 = (index_trunc_175 + 1);
			int index_trunc_179 = (index_trunc_175 + 2);
			bool index_ignore_180 = ((index_trunc_177 >= loop1_dim) || (index_trunc_177 < 0));
			bool index_ignore_181 = ((index_trunc_175 >= loop1_dim) || (index_trunc_175 < 0));
			bool index_ignore_182 = ((index_trunc_178 >= loop1_dim) || (index_trunc_178 < 0));
			bool index_ignore_183 = ((index_trunc_179 >= loop1_dim) || (index_trunc_179 < 0));
			// phase loop1 channel 1;
			double read_loop_184 = (index_ignore_180 ? 0 : m_loop_36.read(index_trunc_177, 0));
			double read_loop_185 = (index_ignore_181 ? 0 : m_loop_36.read(index_trunc_175, 0));
			double read_loop_186 = (index_ignore_182 ? 0 : m_loop_36.read(index_trunc_178, 0));
			double read_loop_187 = (index_ignore_183 ? 0 : m_loop_36.read(index_trunc_179, 0));
			double readinterp_188 = spline_interp(index_fract_176, read_loop_184, read_loop_185, read_loop_186, read_loop_187);
			t_sample sample_loop_168 = readinterp_188;
			t_sample index_loop_169 = sample_index_174;
			t_sample mul_152 = (sample_loop_168 * clamp_154);
			t_sample mix_1311 = (in1 + (gen_249 * (mul_152 - in1)));
			t_sample clamp_45 = ((mix_1311 <= min_189) ? min_189 : ((mix_1311 >= ((int)1)) ? ((int)1) : mix_1311));
			t_sample mul_64 = (clamp_45 * slide_67);
			t_sample clamp_42 = ((mul_64 <= min_190) ? min_190 : ((mul_64 >= ((int)1)) ? ((int)1) : mul_64));
			int index_wrap_191 = ((switch_56 < 0) ? ((loop1_dim - 1) + ((switch_56 + 1) % loop1_dim)) : (switch_56 % loop1_dim));
			m_loop_36.write((clamp_42 + (m_loop_36.read(index_wrap_191, 0) * slide_391)), index_wrap_191, 0);
			t_sample mix_1312 = (mul_152 + (((t_sample)0.5) * (mul_107 - mul_152)));
			t_sample mix_1313 = (mix_1312 + (((t_sample)0.66) * (mul_85 - mix_1312)));
			t_sample mul_392 = (mix_1313 * ((int)3));
			t_sample mix_1314 = (in1 + (gen_213 * (mul_392 - in1)));
			t_sample clamp_78 = ((mix_1314 <= min_192) ? min_192 : ((mix_1314 >= ((int)1)) ? ((int)1) : mix_1314));
			t_sample out1 = clamp_78;
			t_sample fold_400 = fold(clamp_78, (-1), ((int)0));
			t_sample out5 = fold_400;
			m_history_22 = history_193_next_199;
			m_history_20 = history_189_next_201;
			m_history_21 = history_191_next_200;
			m_history_19 = history_223_next_230;
			m_history_18 = history_193_next_1001;
			m_history_16 = history_189_next_1004;
			m_history_17 = history_191_next_1000;
			m_history_15 = history_193_next_1014;
			m_history_13 = history_189_next_1017;
			m_history_14 = history_191_next_1013;
			m_history_12 = history_193_next_1028;
			m_history_10 = history_189_next_1030;
			m_history_11 = history_191_next_1027;
			m_history_9 = history_193_next_1036;
			m_history_7 = history_189_next_1044;
			m_history_8 = history_191_next_1040;
			m_history_6 = history_193_next_1049;
			m_history_4 = history_189_next_1057;
			m_history_5 = history_191_next_1053;
			m_history_3 = history_193_next_1062;
			m_history_1 = history_189_next_1070;
			m_history_2 = history_191_next_1067;
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
	inline void set_loop3(void * _value) {
		m_loop_28.setbuffer(_value);
	};
	inline void set_ctrl7(t_param _value) {
		m_ctrl_29 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_ctrl3(t_param _value) {
		m_ctrl_30 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_loop2(void * _value) {
		m_loop_31.setbuffer(_value);
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
	inline void set_loop1(void * _value) {
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
		case 3: *value = self->m_ctrl_30; break;
		case 4: *value = self->m_ctrl_24; break;
		case 5: *value = self->m_ctrl_34; break;
		case 6: *value = self->m_ctrl_35; break;
		case 7: *value = self->m_ctrl_29; break;
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
	// initialize parameter 3 ("m_ctrl_30")
	pi = self->__commonstate.params + 3;
	pi->name = "ctrl3";
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
	// initialize parameter 9 ("m_loop_36")
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
	// initialize parameter 11 ("m_loop_28")
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


} // BenderVersio_2dbeta::
