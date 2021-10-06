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
	Data m_loopL_33;
	Data m_loopM_24;
	Data m_loopR_36;
	Delta __m_delta_40;
	Phasor __m_phasor_136;
	Phasor __m_phasor_45;
	Phasor __m_phasor_98;
	Phasor __m_phasor_47;
	PlusEquals __m_pluseq_41;
	Rate __m_rate_46;
	int __exception;
	int vectorsize;
	t_sample __m_slide_87;
	t_sample m_ctrl_34;
	t_sample m_button_35;
	t_sample __m_carry_187;
	t_sample m_ctrl_32;
	t_sample m_ctrl_31;
	t_sample __m_count_185;
	t_sample m_ctrl_30;
	t_sample __m_slide_90;
	t_sample __m_slide_37;
	t_sample __m_count_175;
	t_sample __m_slide_95;
	t_sample __m_slide_84;
	t_sample __m_carry_177;
	t_sample __m_slide_133;
	t_sample samples_to_seconds;
	t_sample m_ctrl_29;
	t_sample __m_slide_42;
	t_sample m_gate_28;
	t_sample m_sw_27;
	t_sample m_sw_26;
	t_sample m_history_7;
	t_sample m_history_6;
	t_sample m_history_8;
	t_sample m_history_10;
	t_sample m_history_9;
	t_sample m_history_11;
	t_sample m_history_5;
	t_sample m_history_3;
	t_sample samplerate;
	t_sample m_history_4;
	t_sample m_history_1;
	t_sample m_history_2;
	t_sample __m_count_195;
	t_sample m_history_12;
	t_sample m_history_14;
	t_sample m_history_22;
	t_sample m_history_21;
	t_sample m_ctrl_23;
	t_sample m_ctrl_25;
	t_sample m_history_13;
	t_sample m_history_20;
	t_sample m_history_18;
	t_sample m_history_15;
	t_sample m_history_19;
	t_sample m_history_16;
	t_sample m_history_17;
	t_sample __m_carry_197;
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
		m_loopM_24.reset("loopM", ((int)192000), ((int)2));
		m_ctrl_25 = ((int)0);
		m_sw_26 = ((int)0);
		m_sw_27 = ((int)0);
		m_gate_28 = ((int)0);
		m_ctrl_29 = ((int)0);
		m_ctrl_30 = ((int)0);
		m_ctrl_31 = ((int)0);
		m_ctrl_32 = ((int)0);
		m_loopL_33.reset("loopL", ((int)192000), ((int)2));
		m_ctrl_34 = ((int)0);
		m_button_35 = ((int)0);
		m_loopR_36.reset("loopR", ((int)192000), ((int)2));
		__m_slide_37 = 0;
		__m_delta_40.reset(0);
		__m_pluseq_41.reset(0);
		__m_slide_42 = 0;
		samples_to_seconds = (1 / samplerate);
		__m_phasor_45.reset(0);
		__m_rate_46.reset();
		__m_phasor_47.reset(0);
		__m_slide_84 = 0;
		__m_slide_87 = 0;
		__m_slide_90 = 0;
		__m_slide_95 = 0;
		__m_phasor_98.reset(0);
		__m_slide_133 = 0;
		__m_phasor_136.reset(0);
		__m_count_175 = 0;
		__m_carry_177 = 0;
		__m_count_185 = 0;
		__m_carry_187 = 0;
		__m_count_195 = 0;
		__m_carry_197 = 0;
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
		int loopR_dim = m_loopR_36.dim;
		int loopR_channels = m_loopR_36.channels;
		int loopR_dim_184 = loopR_dim;
		int loopL_dim = m_loopL_33.dim;
		int loopL_channels = m_loopL_33.channels;
		int loopL_dim_194 = loopL_dim;
		int loopM_dim = m_loopM_24.dim;
		int loopM_channels = m_loopM_24.channels;
		int loopM_dim_186 = loopM_dim;
		t_sample iup_38 = (1 / maximum(1, abs(((int)4000))));
		t_sample idown_39 = (1 / maximum(1, abs(((int)4000))));
		int or_263 = (m_gate_28 || m_button_35);
		int gt_54 = (or_263 > ((int)0));
		t_sample div_22 = (loopL_dim_194 * ((t_sample)0.25));
		t_sample div_24 = (loopM_dim_186 * ((t_sample)1));
		int mul_21 = (loopR_dim_184 * ((int)2));
		int eq_226 = (m_sw_26 == ((int)0));
		t_sample iup_43 = (1 / maximum(1, abs(((int)4000))));
		t_sample idown_44 = (1 / maximum(1, abs(((int)4000))));
		samples_to_seconds = (1 / samplerate);
		int eq_230 = (m_sw_26 == ((t_sample)0.5));
		t_sample switch_229 = (eq_230 ? ((int)0) : m_sw_26);
		t_sample switch_227 = (eq_226 ? ((t_sample)0.5) : switch_229);
		t_sample sub_724 = (switch_227 - ((int)0));
		t_sample scale_721 = ((safepow((sub_724 * ((t_sample)1)), ((int)1)) * ((int)2)) + ((int)1));
		t_sample choice_48 = int(scale_721);
		t_sample choice_49 = int(scale_721);
		t_sample choice_50 = int(scale_721);
		int neq_28 = (scale_721 != ((int)2));
		int min_66 = (-1);
		bool chan_ignore_77 = ((1 < 0) || (1 >= loopL_channels));
		int min_83 = (-1);
		t_sample iup_85 = (1 / maximum(1, abs(((int)4000))));
		t_sample idown_86 = (1 / maximum(1, abs(((int)4000))));
		t_sample iup_88 = (1 / maximum(1, abs(((int)4000))));
		t_sample idown_89 = (1 / maximum(1, abs(((int)4000))));
		t_sample iup_91 = (1 / maximum(1, abs(((int)4000))));
		t_sample idown_92 = (1 / maximum(1, abs(((int)4000))));
		int min_93 = (-1);
		int min_94 = (-1);
		int eq_220 = (m_sw_27 == ((int)0));
		t_sample iup_96 = (1 / maximum(1, abs(((int)4000))));
		t_sample idown_97 = (1 / maximum(1, abs(((int)4000))));
		int min_114 = (-1);
		bool chan_ignore_125 = ((1 < 0) || (1 >= loopR_channels));
		int min_131 = (-1);
		int min_132 = (-1);
		t_sample iup_134 = (1 / maximum(1, abs(((int)4000))));
		t_sample idown_135 = (1 / maximum(1, abs(((int)4000))));
		bool chan_ignore_147 = ((1 < 0) || (1 >= loopM_channels));
		int min_153 = (-1);
		int min_154 = (-1);
		int min_155 = (-1);
		int min_171 = (-1);
		int min_172 = (-1);
		int min_173 = (-1);
		int eq_224 = (m_sw_27 == ((t_sample)0.5));
		t_sample switch_223 = (eq_224 ? ((int)0) : m_sw_27);
		t_sample switch_221 = (eq_220 ? ((t_sample)0.5) : switch_223);
		t_sample sub_781 = (switch_221 - ((int)0));
		t_sample scale_778 = ((safepow((sub_781 * ((t_sample)1)), ((int)1)) * ((int)2)) + ((int)1));
		t_sample choice_174 = int(scale_778);
		t_sample selector_26 = ((choice_174 >= 3) ? mul_21 : ((choice_174 >= 2) ? div_24 : ((choice_174 >= 1) ? div_22 : 0)));
		bool chan_ignore_179 = ((((int)1) < 0) || (((int)1) >= loopM_channels));
		t_sample choice_184 = int(scale_778);
		t_sample selector_27 = ((choice_184 >= 3) ? mul_21 : ((choice_184 >= 2) ? div_24 : ((choice_184 >= 1) ? div_22 : 0)));
		bool chan_ignore_191 = ((((int)1) < 0) || (((int)1) >= loopL_channels));
		t_sample choice_194 = int(scale_778);
		t_sample selector_25 = ((choice_194 >= 3) ? mul_21 : ((choice_194 >= 2) ? div_24 : ((choice_194 >= 1) ? div_22 : 0)));
		bool chan_ignore_201 = ((((int)1) < 0) || (((int)1) >= loopR_channels));
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			const t_sample in2 = (*(__in2++));
			t_sample out8 = ((int)0);
			t_sample fold_45 = fold(in1, (-1), ((int)0));
			t_sample mix_701 = (m_history_22 + (((t_sample)0.0042742627044161) * (m_ctrl_29 - m_history_22)));
			t_sample mix_235 = mix_701;
			t_sample mix_702 = (m_history_21 + (((t_sample)0.0042742627044161) * (mix_235 - m_history_21)));
			t_sample mix_233 = mix_702;
			t_sample mix_703 = (m_history_20 + (((t_sample)0.0042742627044161) * (mix_233 - m_history_20)));
			t_sample mix_231 = mix_703;
			t_sample gen_241 = mix_231;
			t_sample history_236_next_238 = fixdenorm(mix_235);
			t_sample history_234_next_239 = fixdenorm(mix_233);
			t_sample history_232_next_240 = fixdenorm(mix_231);
			__m_slide_37 = fixdenorm((__m_slide_37 + (((gen_241 > __m_slide_37) ? iup_38 : idown_39) * (gen_241 - __m_slide_37))));
			t_sample slide_127 = __m_slide_37;
			t_sample fold_65 = fold(in2, (-1), ((int)0));
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
			t_sample mix_704 = (m_history_18 + (((t_sample)0.0042742627044161) * (m_ctrl_25 - m_history_18)));
			t_sample mix_458 = mix_704;
			t_sample mix_705 = (m_history_17 + (((t_sample)0.0042742627044161) * (mix_458 - m_history_17)));
			t_sample mix_452 = mix_705;
			t_sample mix_706 = (m_history_16 + (((t_sample)0.0042742627044161) * (mix_452 - m_history_16)));
			t_sample mix_459 = mix_706;
			t_sample gen_247 = mix_459;
			t_sample history_236_next_460 = fixdenorm(mix_458);
			t_sample history_234_next_454 = fixdenorm(mix_452);
			t_sample history_232_next_451 = fixdenorm(mix_459);
			t_sample abs_69 = fabs(in2);
			t_sample add_68 = (abs_69 + ((t_sample)0.0001));
			t_sample rsub_71 = (((int)1) - add_68);
			t_sample mix_707 = (m_history_15 + (((t_sample)0.0042742627044161) * (m_ctrl_34 - m_history_15)));
			t_sample mix_466 = mix_707;
			t_sample mix_708 = (m_history_14 + (((t_sample)0.0042742627044161) * (mix_466 - m_history_14)));
			t_sample mix_469 = mix_708;
			t_sample mix_709 = (m_history_13 + (((t_sample)0.0042742627044161) * (mix_469 - m_history_13)));
			t_sample mix_473 = mix_709;
			t_sample gen_246 = mix_473;
			t_sample history_236_next_467 = fixdenorm(mix_466);
			t_sample history_234_next_465 = fixdenorm(mix_469);
			t_sample history_232_next_468 = fixdenorm(mix_473);
			t_sample mix_710 = (m_history_12 + (((t_sample)0.0042742627044161) * (m_ctrl_23 - m_history_12)));
			t_sample mix_479 = mix_710;
			t_sample mix_711 = (m_history_11 + (((t_sample)0.0042742627044161) * (mix_479 - m_history_11)));
			t_sample mix_482 = mix_711;
			t_sample mix_712 = (m_history_10 + (((t_sample)0.0042742627044161) * (mix_482 - m_history_10)));
			t_sample mix_486 = mix_712;
			t_sample gen_244 = mix_486;
			t_sample history_236_next_480 = fixdenorm(mix_479);
			t_sample history_234_next_478 = fixdenorm(mix_482);
			t_sample history_232_next_481 = fixdenorm(mix_486);
			t_sample sub_716 = (gen_244 - ((int)0));
			t_sample scale_713 = ((safepow((sub_716 * ((t_sample)1)), ((int)1)) * ((int)2)) + (-1));
			t_sample abs_75 = fabs(scale_713);
			t_sample sub_720 = (abs_75 - ((int)1));
			t_sample scale_717 = ((safepow((sub_720 * ((t_sample)-1)), ((int)1)) * ((t_sample)3.5)) + ((t_sample)0.5));
			t_sample out9 = scale_717;
			int gt_14 = (scale_717 > ((int)2));
			t_sample rdiv_215 = safediv(((int)1), scale_717);
			__m_slide_42 = fixdenorm((__m_slide_42 + (((rdiv_215 > __m_slide_42) ? iup_43 : idown_44) * (rdiv_215 - __m_slide_42))));
			t_sample slide_73 = __m_slide_42;
			t_sample phasor_216 = __m_phasor_45(slide_73, samples_to_seconds);
			t_sample out7 = phasor_216;
			t_sample rate_20 = __m_rate_46.perform_off(phasor_216, ((t_sample)0.5));
			t_sample out10 = rate_20;
			t_sample mul_204 = (phasor_216 * ((int)2));
			t_sample sub_203 = (mul_204 - ((int)1));
			t_sample cos_202 = cos(sub_203);
			t_sample sub_201 = (cos_202 - ((t_sample)0.5));
			t_sample mul_200 = (sub_201 * ((int)10));
			t_sample clamp_199 = ((mul_200 <= ((int)0)) ? ((int)0) : ((mul_200 >= ((int)1)) ? ((int)1) : mul_200));
			t_sample phasor_6 = __m_phasor_47(((int)1), samples_to_seconds);
			t_sample mul_3 = (phasor_6 * ((t_sample)0.2));
			t_sample selector_48 = ((choice_48 >= 3) ? gt_51 : ((choice_48 >= 2) ? ((int)1) : ((choice_48 >= 1) ? gt_54 : 0)));
			t_sample switch_50 = (selector_48 ? rsub_49 : fold_45);
			t_sample out3 = switch_50;
			t_sample selector_102 = ((choice_49 >= 3) ? gt_51 : ((choice_49 >= 2) ? ((int)1) : ((choice_49 >= 1) ? gt_54 : 0)));
			t_sample selector_70 = ((choice_50 >= 3) ? gt_51 : ((choice_50 >= 2) ? ((int)1) : ((choice_50 >= 1) ? gt_54 : 0)));
			t_sample switch_72 = (selector_70 ? rsub_71 : fold_65);
			t_sample out4 = switch_72;
			t_sample fold_206 = fold(phasor_216, ((int)0), ((int)1));
			double sample_index_51 = (fold_206 * (loopL_dim - 1));
			int index_trunc_52 = fixnan(floor(sample_index_51));
			double index_fract_53 = (sample_index_51 - index_trunc_52);
			int index_trunc_54 = (index_trunc_52 - 1);
			int index_trunc_55 = (index_trunc_52 + 1);
			int index_trunc_56 = (index_trunc_52 + 2);
			int index_clamp_57 = ((index_trunc_54 < 0) ? 0 : ((index_trunc_54 > loopL_dim) ? loopL_dim : index_trunc_54));
			int index_clamp_58 = ((index_trunc_52 < 0) ? 0 : ((index_trunc_52 > loopL_dim) ? loopL_dim : index_trunc_52));
			int index_clamp_59 = ((index_trunc_55 < 0) ? 0 : ((index_trunc_55 > loopL_dim) ? loopL_dim : index_trunc_55));
			int index_clamp_60 = ((index_trunc_56 < 0) ? 0 : ((index_trunc_56 > loopL_dim) ? loopL_dim : index_trunc_56));
			// phase loopL channel 1;
			double read_loopL_61 = m_loopL_33.read(index_clamp_57, 0);
			double read_loopL_62 = m_loopL_33.read(index_clamp_58, 0);
			double read_loopL_63 = m_loopL_33.read(index_clamp_59, 0);
			double read_loopL_64 = m_loopL_33.read(index_clamp_60, 0);
			double readinterp_65 = spline_interp(index_fract_53, read_loopL_61, read_loopL_62, read_loopL_63, read_loopL_64);
			t_sample sample_loopL_212 = readinterp_65;
			t_sample index_loopL_213 = sample_index_51;
			t_sample mul_197 = (sample_loopL_212 * clamp_199);
			t_sample mix_725 = (in1 + (gen_246 * (mul_197 - in1)));
			t_sample clamp_92 = ((mix_725 <= min_66) ? min_66 : ((mix_725 >= ((int)1)) ? ((int)1) : mix_725));
			t_sample mix_726 = (m_history_9 + (((t_sample)0.0042742627044161) * (m_ctrl_30 - m_history_9)));
			t_sample mix_491 = mix_726;
			t_sample mix_727 = (m_history_8 + (((t_sample)0.0042742627044161) * (mix_491 - m_history_8)));
			t_sample mix_493 = mix_727;
			t_sample mix_728 = (m_history_7 + (((t_sample)0.0042742627044161) * (mix_493 - m_history_7)));
			t_sample mix_499 = mix_728;
			t_sample gen_243 = mix_499;
			t_sample history_236_next_498 = fixdenorm(mix_491);
			t_sample history_234_next_490 = fixdenorm(mix_493);
			t_sample history_232_next_492 = fixdenorm(mix_499);
			t_sample sub_732 = (gen_243 - ((int)0));
			t_sample scale_729 = ((safepow((sub_732 * ((t_sample)1)), ((int)1)) * ((int)2)) + (-1));
			t_sample abs_59 = fabs(scale_729);
			t_sample sub_736 = (abs_59 - ((int)1));
			t_sample scale_733 = ((safepow((sub_736 * ((t_sample)-1)), ((int)1)) * ((t_sample)3.5)) + ((t_sample)0.5));
			int gt_9 = (scale_733 > ((int)2));
			double sample_index_67 = (fold_206 * (loopL_dim - 1));
			int index_trunc_68 = fixnan(floor(sample_index_67));
			double index_fract_69 = (sample_index_67 - index_trunc_68);
			int index_trunc_70 = (index_trunc_68 - 1);
			int index_trunc_71 = (index_trunc_68 + 1);
			int index_trunc_72 = (index_trunc_68 + 2);
			int index_clamp_73 = ((index_trunc_70 < 0) ? 0 : ((index_trunc_70 > loopL_dim) ? loopL_dim : index_trunc_70));
			int index_clamp_74 = ((index_trunc_68 < 0) ? 0 : ((index_trunc_68 > loopL_dim) ? loopL_dim : index_trunc_68));
			int index_clamp_75 = ((index_trunc_71 < 0) ? 0 : ((index_trunc_71 > loopL_dim) ? loopL_dim : index_trunc_71));
			int index_clamp_76 = ((index_trunc_72 < 0) ? 0 : ((index_trunc_72 > loopL_dim) ? loopL_dim : index_trunc_72));
			// phase loopL channel 1;
			double read_loopL_78 = (chan_ignore_77 ? 0 : m_loopL_33.read(index_clamp_73, 1));
			double read_loopL_79 = (chan_ignore_77 ? 0 : m_loopL_33.read(index_clamp_74, 1));
			double read_loopL_80 = (chan_ignore_77 ? 0 : m_loopL_33.read(index_clamp_75, 1));
			double read_loopL_81 = (chan_ignore_77 ? 0 : m_loopL_33.read(index_clamp_76, 1));
			double readinterp_82 = spline_interp(index_fract_69, read_loopL_78, read_loopL_79, read_loopL_80, read_loopL_81);
			t_sample sample_loopL_210 = readinterp_82;
			t_sample index_loopL_211 = sample_index_67;
			t_sample mul_198 = (sample_loopL_210 * clamp_199);
			t_sample mix_737 = (in2 + (gen_246 * (mul_198 - in2)));
			t_sample clamp_83 = ((mix_737 <= min_83) ? min_83 : ((mix_737 >= ((int)1)) ? ((int)1) : mix_737));
			t_sample mix_738 = (m_history_6 + (((t_sample)0.0042742627044161) * (m_ctrl_32 - m_history_6)));
			t_sample mix_504 = mix_738;
			t_sample mix_739 = (m_history_5 + (((t_sample)0.0042742627044161) * (mix_504 - m_history_5)));
			t_sample mix_506 = mix_739;
			t_sample mix_740 = (m_history_4 + (((t_sample)0.0042742627044161) * (mix_506 - m_history_4)));
			t_sample mix_512 = mix_740;
			t_sample gen_245 = mix_512;
			t_sample history_236_next_510 = fixdenorm(mix_504);
			t_sample history_234_next_503 = fixdenorm(mix_506);
			t_sample history_232_next_505 = fixdenorm(mix_512);
			t_sample sub_744 = (gen_245 - ((int)0));
			t_sample scale_741 = ((safepow((sub_744 * ((t_sample)1)), ((int)1)) * ((int)2)) + (-1));
			t_sample gtep_115 = ((scale_741 >= ((int)0)) ? scale_741 : 0);
			__m_slide_84 = fixdenorm((__m_slide_84 + (((gtep_115 > __m_slide_84) ? iup_85 : idown_86) * (gtep_115 - __m_slide_84))));
			t_sample slide_112 = __m_slide_84;
			t_sample ceil_32 = ceil(slide_112);
			t_sample switch_37 = (neq_28 ? ceil_32 : ((int)1));
			t_sample sub_748 = (gen_245 - ((int)0));
			t_sample scale_745 = ((safepow((sub_748 * ((t_sample)1)), ((int)1)) * ((int)2)) + (-1));
			t_sample abs_120 = fabs(scale_745);
			t_sample sub_752 = (abs_120 - ((int)1));
			t_sample scale_749 = ((safepow((sub_752 * ((t_sample)-1)), ((int)1)) * ((int)1)) + ((int)0));
			__m_slide_87 = fixdenorm((__m_slide_87 + (((scale_749 > __m_slide_87) ? iup_88 : idown_89) * (scale_749 - __m_slide_87))));
			t_sample slide_113 = __m_slide_87;
			t_sample ceil_33 = ceil(slide_113);
			t_sample switch_39 = (neq_28 ? ceil_33 : ((int)1));
			t_sample sub_756 = (gen_245 - ((int)0));
			t_sample scale_753 = ((safepow((sub_756 * ((t_sample)1)), ((int)1)) * ((int)2)) + (-1));
			t_sample ltep_117 = ((scale_753 <= ((int)0)) ? scale_753 : 0);
			t_sample abs_118 = fabs(ltep_117);
			__m_slide_90 = fixdenorm((__m_slide_90 + (((abs_118 > __m_slide_90) ? iup_91 : idown_92) * (abs_118 - __m_slide_90))));
			t_sample slide_114 = __m_slide_90;
			t_sample mul_111 = (clamp_92 * slide_114);
			t_sample clamp_89 = ((mul_111 <= min_93) ? min_93 : ((mul_111 >= ((int)1)) ? ((int)1) : mul_111));
			t_sample mul_108 = (clamp_83 * slide_114);
			t_sample clamp_86 = ((mul_108 <= min_94) ? min_94 : ((mul_108 >= ((int)1)) ? ((int)1) : mul_108));
			t_sample ceil_34 = ceil(slide_114);
			t_sample switch_42 = (neq_28 ? ceil_34 : ((int)1));
			t_sample mix_757 = (m_history_3 + (((t_sample)0.0042742627044161) * (m_ctrl_31 - m_history_3)));
			t_sample mix_517 = mix_757;
			t_sample mix_758 = (m_history_2 + (((t_sample)0.0042742627044161) * (mix_517 - m_history_2)));
			t_sample mix_519 = mix_758;
			t_sample mix_759 = (m_history_1 + (((t_sample)0.0042742627044161) * (mix_519 - m_history_1)));
			t_sample mix_525 = mix_759;
			t_sample gen_242 = mix_525;
			t_sample history_236_next_524 = fixdenorm(mix_517);
			t_sample history_234_next_516 = fixdenorm(mix_519);
			t_sample history_232_next_518 = fixdenorm(mix_525);
			t_sample sub_763 = (gen_242 - ((int)0));
			t_sample scale_760 = ((safepow((sub_763 * ((t_sample)1)), ((int)1)) * ((int)2)) + (-1));
			t_sample abs_63 = fabs(scale_760);
			t_sample sub_767 = (abs_63 - ((int)1));
			t_sample scale_764 = ((safepow((sub_767 * ((t_sample)-1)), ((int)1)) * ((t_sample)3.5)) + ((t_sample)0.5));
			int lt_8 = (scale_764 < ((int)2));
			t_sample rdiv_147 = safediv(((int)1), scale_733);
			__m_slide_95 = fixdenorm((__m_slide_95 + (((rdiv_147 > __m_slide_95) ? iup_96 : idown_97) * (rdiv_147 - __m_slide_95))));
			t_sample slide_57 = __m_slide_95;
			t_sample phasor_148 = __m_phasor_98(slide_57, samples_to_seconds);
			t_sample mul_145 = (phasor_148 * ((int)2));
			t_sample sub_144 = (mul_145 - ((int)1));
			t_sample cos_143 = cos(sub_144);
			t_sample sub_142 = (cos_143 - ((t_sample)0.5));
			t_sample mul_141 = (sub_142 * ((int)10));
			t_sample clamp_140 = ((mul_141 <= ((int)0)) ? ((int)0) : ((mul_141 >= ((int)1)) ? ((int)1) : mul_141));
			t_sample fold_133 = fold(phasor_148, ((int)0), ((int)1));
			double sample_index_99 = (fold_133 * (loopR_dim - 1));
			int index_trunc_100 = fixnan(floor(sample_index_99));
			double index_fract_101 = (sample_index_99 - index_trunc_100);
			int index_trunc_102 = (index_trunc_100 - 1);
			int index_trunc_103 = (index_trunc_100 + 1);
			int index_trunc_104 = (index_trunc_100 + 2);
			bool index_ignore_105 = ((index_trunc_102 >= loopR_dim) || (index_trunc_102 < 0));
			bool index_ignore_106 = ((index_trunc_100 >= loopR_dim) || (index_trunc_100 < 0));
			bool index_ignore_107 = ((index_trunc_103 >= loopR_dim) || (index_trunc_103 < 0));
			bool index_ignore_108 = ((index_trunc_104 >= loopR_dim) || (index_trunc_104 < 0));
			// phase loopR channel 1;
			double read_loopR_109 = (index_ignore_105 ? 0 : m_loopR_36.read(index_trunc_102, 0));
			double read_loopR_110 = (index_ignore_106 ? 0 : m_loopR_36.read(index_trunc_100, 0));
			double read_loopR_111 = (index_ignore_107 ? 0 : m_loopR_36.read(index_trunc_103, 0));
			double read_loopR_112 = (index_ignore_108 ? 0 : m_loopR_36.read(index_trunc_104, 0));
			double readinterp_113 = spline_interp(index_fract_101, read_loopR_109, read_loopR_110, read_loopR_111, read_loopR_112);
			t_sample sample_loopR_138 = readinterp_113;
			t_sample index_loopR_139 = sample_index_99;
			t_sample mul_132 = (sample_loopR_138 * clamp_140);
			t_sample mix_768 = (in1 + (gen_246 * (mul_132 - in1)));
			t_sample mul_109 = (mix_768 * slide_112);
			t_sample clamp_87 = ((mul_109 <= min_114) ? min_114 : ((mul_109 >= ((int)1)) ? ((int)1) : mul_109));
			double sample_index_115 = (fold_133 * (loopR_dim - 1));
			int index_trunc_116 = fixnan(floor(sample_index_115));
			double index_fract_117 = (sample_index_115 - index_trunc_116);
			int index_trunc_118 = (index_trunc_116 - 1);
			int index_trunc_119 = (index_trunc_116 + 1);
			int index_trunc_120 = (index_trunc_116 + 2);
			bool index_ignore_121 = ((index_trunc_118 >= loopR_dim) || (index_trunc_118 < 0));
			bool index_ignore_122 = ((index_trunc_116 >= loopR_dim) || (index_trunc_116 < 0));
			bool index_ignore_123 = ((index_trunc_119 >= loopR_dim) || (index_trunc_119 < 0));
			bool index_ignore_124 = ((index_trunc_120 >= loopR_dim) || (index_trunc_120 < 0));
			// phase loopR channel 1;
			double read_loopR_126 = ((chan_ignore_125 || index_ignore_121) ? 0 : m_loopR_36.read(index_trunc_118, 1));
			double read_loopR_127 = ((chan_ignore_125 || index_ignore_122) ? 0 : m_loopR_36.read(index_trunc_116, 1));
			double read_loopR_128 = ((chan_ignore_125 || index_ignore_123) ? 0 : m_loopR_36.read(index_trunc_119, 1));
			double read_loopR_129 = ((chan_ignore_125 || index_ignore_124) ? 0 : m_loopR_36.read(index_trunc_120, 1));
			double readinterp_130 = spline_interp(index_fract_117, read_loopR_126, read_loopR_127, read_loopR_128, read_loopR_129);
			t_sample sample_loopR_136 = readinterp_130;
			t_sample index_loopR_137 = sample_index_115;
			t_sample mul_131 = (sample_loopR_136 * clamp_140);
			t_sample mix_769 = (in2 + (gen_246 * (mul_131 - in2)));
			t_sample clamp_79 = ((mix_769 <= min_131) ? min_131 : ((mix_769 >= ((int)1)) ? ((int)1) : mix_769));
			t_sample mul_106 = (clamp_79 * slide_112);
			t_sample clamp_84 = ((mul_106 <= min_132) ? min_132 : ((mul_106 >= ((int)1)) ? ((int)1) : mul_106));
			t_sample rdiv_168 = safediv(((int)1), scale_764);
			__m_slide_133 = fixdenorm((__m_slide_133 + (((rdiv_168 > __m_slide_133) ? iup_134 : idown_135) * (rdiv_168 - __m_slide_133))));
			t_sample slide_61 = __m_slide_133;
			t_sample phasor_169 = __m_phasor_136(slide_61, samples_to_seconds);
			t_sample mul_166 = (phasor_169 * ((int)2));
			t_sample sub_165 = (mul_166 - ((int)1));
			t_sample cos_164 = cos(sub_165);
			t_sample sub_163 = (cos_164 - ((t_sample)0.5));
			t_sample mul_162 = (sub_163 * ((int)10));
			t_sample clamp_161 = ((mul_162 <= ((int)0)) ? ((int)0) : ((mul_162 >= ((int)1)) ? ((int)1) : mul_162));
			t_sample fold_154 = fold(phasor_169, ((int)0), ((int)1));
			double sample_index_137 = (fold_154 * (loopM_dim - 1));
			int index_trunc_138 = fixnan(floor(sample_index_137));
			double index_fract_139 = (sample_index_137 - index_trunc_138);
			int index_trunc_140 = (index_trunc_138 - 1);
			int index_trunc_141 = (index_trunc_138 + 1);
			int index_trunc_142 = (index_trunc_138 + 2);
			bool index_ignore_143 = ((index_trunc_140 >= loopM_dim) || (index_trunc_140 < 0));
			bool index_ignore_144 = ((index_trunc_138 >= loopM_dim) || (index_trunc_138 < 0));
			bool index_ignore_145 = ((index_trunc_141 >= loopM_dim) || (index_trunc_141 < 0));
			bool index_ignore_146 = ((index_trunc_142 >= loopM_dim) || (index_trunc_142 < 0));
			// phase loopM channel 1;
			double read_loopM_148 = ((chan_ignore_147 || index_ignore_143) ? 0 : m_loopM_24.read(index_trunc_140, 1));
			double read_loopM_149 = ((chan_ignore_147 || index_ignore_144) ? 0 : m_loopM_24.read(index_trunc_138, 1));
			double read_loopM_150 = ((chan_ignore_147 || index_ignore_145) ? 0 : m_loopM_24.read(index_trunc_141, 1));
			double read_loopM_151 = ((chan_ignore_147 || index_ignore_146) ? 0 : m_loopM_24.read(index_trunc_142, 1));
			double readinterp_152 = spline_interp(index_fract_139, read_loopM_148, read_loopM_149, read_loopM_150, read_loopM_151);
			t_sample sample_loopM_157 = readinterp_152;
			t_sample index_loopM_158 = sample_index_137;
			t_sample mul_152 = (sample_loopM_157 * clamp_161);
			t_sample mix_770 = (in2 + (gen_246 * (mul_152 - in2)));
			t_sample clamp_81 = ((mix_770 <= min_153) ? min_153 : ((mix_770 >= ((int)1)) ? ((int)1) : mix_770));
			t_sample mul_107 = (clamp_81 * slide_113);
			t_sample clamp_85 = ((mul_107 <= min_154) ? min_154 : ((mul_107 >= ((int)1)) ? ((int)1) : mul_107));
			t_sample mix_771 = (mul_198 + (((t_sample)0.5) * (mul_152 - mul_198)));
			t_sample mix_772 = (mix_771 + (((t_sample)0.33) * (mul_131 - mix_771)));
			t_sample mul_104 = (mix_772 * ((int)3));
			t_sample mix_773 = (in2 + (gen_247 * (mul_104 - in2)));
			t_sample clamp_124 = ((mix_773 <= min_155) ? min_155 : ((mix_773 >= ((int)1)) ? ((int)1) : mix_773));
			t_sample out2 = clamp_124;
			t_sample fold_66 = fold(clamp_124, (-1), ((int)0));
			t_sample abs_11 = fabs(clamp_124);
			t_sample add_10 = (abs_11 + ((t_sample)0.0001));
			t_sample rsub_12 = (((int)1) - add_10);
			t_sample mul_1 = (rsub_12 * mul_3);
			t_sample switch_2 = (lt_8 ? rsub_12 : mul_1);
			t_sample switch_13 = (gt_9 ? switch_2 : fold_66);
			t_sample out6 = switch_13;
			double sample_index_156 = (fold_154 * (loopM_dim - 1));
			int index_trunc_157 = fixnan(floor(sample_index_156));
			double index_fract_158 = (sample_index_156 - index_trunc_157);
			int index_trunc_159 = (index_trunc_157 - 1);
			int index_trunc_160 = (index_trunc_157 + 1);
			int index_trunc_161 = (index_trunc_157 + 2);
			bool index_ignore_162 = ((index_trunc_159 >= loopM_dim) || (index_trunc_159 < 0));
			bool index_ignore_163 = ((index_trunc_157 >= loopM_dim) || (index_trunc_157 < 0));
			bool index_ignore_164 = ((index_trunc_160 >= loopM_dim) || (index_trunc_160 < 0));
			bool index_ignore_165 = ((index_trunc_161 >= loopM_dim) || (index_trunc_161 < 0));
			// phase loopM channel 1;
			double read_loopM_166 = (index_ignore_162 ? 0 : m_loopM_24.read(index_trunc_159, 0));
			double read_loopM_167 = (index_ignore_163 ? 0 : m_loopM_24.read(index_trunc_157, 0));
			double read_loopM_168 = (index_ignore_164 ? 0 : m_loopM_24.read(index_trunc_160, 0));
			double read_loopM_169 = (index_ignore_165 ? 0 : m_loopM_24.read(index_trunc_161, 0));
			double readinterp_170 = spline_interp(index_fract_158, read_loopM_166, read_loopM_167, read_loopM_168, read_loopM_169);
			t_sample sample_loopM_159 = readinterp_170;
			t_sample index_loopM_160 = sample_index_156;
			t_sample mul_153 = (sample_loopM_159 * clamp_161);
			t_sample mix_774 = (in1 + (gen_246 * (mul_153 - in1)));
			t_sample clamp_91 = ((mix_774 <= min_171) ? min_171 : ((mix_774 >= ((int)1)) ? ((int)1) : mix_774));
			t_sample mul_110 = (clamp_91 * slide_113);
			t_sample clamp_88 = ((mul_110 <= min_172) ? min_172 : ((mul_110 >= ((int)1)) ? ((int)1) : mul_110));
			t_sample mix_775 = (mul_197 + (((t_sample)0.5) * (mul_153 - mul_197)));
			t_sample mix_776 = (mix_775 + (((t_sample)0.33) * (mul_132 - mix_775)));
			t_sample mul_105 = (mix_776 * ((int)3));
			t_sample mix_777 = (in1 + (gen_247 * (mul_105 - in1)));
			t_sample clamp_125 = ((mix_777 <= min_173) ? min_173 : ((mix_777 >= ((int)1)) ? ((int)1) : mix_777));
			t_sample out1 = clamp_125;
			t_sample fold_67 = fold(clamp_125, (-1), ((int)0));
			t_sample abs_16 = fabs(clamp_125);
			t_sample add_15 = (abs_16 + ((t_sample)0.0001));
			t_sample rsub_17 = (((int)1) - add_15);
			t_sample mul_4 = (mul_3 * rsub_17);
			t_sample switch_7 = (lt_8 ? rsub_17 : mul_4);
			t_sample switch_18 = (gt_14 ? switch_7 : fold_67);
			t_sample out5 = switch_18;
			__m_count_175 = (((int)0) ? 0 : (fixdenorm(__m_count_175 + ((int)1))));
			int carry_176 = 0;
			if ((((int)0) != 0)) {
				__m_count_175 = 0;
				__m_carry_177 = 0;
				
			} else if (((selector_26 > 0) && (__m_count_175 >= selector_26))) {
				int wraps_178 = (__m_count_175 / selector_26);
				__m_carry_177 = (__m_carry_177 + wraps_178);
				__m_count_175 = (__m_count_175 - (wraps_178 * selector_26));
				carry_176 = 1;
				
			};
			int counter_181 = __m_count_175;
			int counter_182 = carry_176;
			int counter_183 = __m_carry_177;
			t_sample mul_38 = (switch_39 * counter_181);
			t_sample switch_98 = (selector_102 ? mul_38 : ((int)0));
			int index_trunc_180 = fixnan(floor(switch_98));
			int index_wrap_181 = ((index_trunc_180 < 0) ? ((loopM_dim - 1) + ((index_trunc_180 + 1) % loopM_dim)) : (index_trunc_180 % loopM_dim));
			if ((!chan_ignore_179)) {
				m_loopM_24.write((clamp_85 + (m_loopM_24.read(index_wrap_181, ((int)1)) * slide_127)), index_wrap_181, ((int)1));
				
			};
			t_sample mul_40 = (switch_39 * counter_181);
			t_sample switch_99 = (selector_102 ? mul_40 : ((int)0));
			int index_trunc_182 = fixnan(floor(switch_99));
			int index_wrap_183 = ((index_trunc_182 < 0) ? ((loopM_dim - 1) + ((index_trunc_182 + 1) % loopM_dim)) : (index_trunc_182 % loopM_dim));
			m_loopM_24.write((clamp_88 + (m_loopM_24.read(index_wrap_183, 0) * slide_127)), index_wrap_183, 0);
			__m_count_185 = (((int)0) ? 0 : (fixdenorm(__m_count_185 + ((int)1))));
			int carry_186 = 0;
			if ((((int)0) != 0)) {
				__m_count_185 = 0;
				__m_carry_187 = 0;
				
			} else if (((selector_27 > 0) && (__m_count_185 >= selector_27))) {
				int wraps_188 = (__m_count_185 / selector_27);
				__m_carry_187 = (__m_carry_187 + wraps_188);
				__m_count_185 = (__m_count_185 - (wraps_188 * selector_27));
				carry_186 = 1;
				
			};
			int counter_189 = __m_count_185;
			int counter_190 = carry_186;
			int counter_191 = __m_carry_187;
			t_sample mul_43 = (switch_42 * counter_189);
			t_sample switch_103 = (selector_102 ? mul_43 : ((int)0));
			int index_trunc_189 = fixnan(floor(switch_103));
			int index_clamp_190 = ((index_trunc_189 < 0) ? 0 : ((index_trunc_189 > loopL_dim) ? loopL_dim : index_trunc_189));
			m_loopL_33.write((clamp_89 + (m_loopL_33.read(index_clamp_190, 0) * slide_127)), index_clamp_190, 0);
			t_sample mul_41 = (switch_42 * counter_189);
			t_sample switch_101 = (selector_102 ? mul_41 : ((int)0));
			int index_trunc_192 = fixnan(floor(switch_101));
			int index_clamp_193 = ((index_trunc_192 < 0) ? 0 : ((index_trunc_192 > loopL_dim) ? loopL_dim : index_trunc_192));
			if ((!chan_ignore_191)) {
				m_loopL_33.write((clamp_86 + (m_loopL_33.read(index_clamp_193, ((int)1)) * slide_127)), index_clamp_193, ((int)1));
				
			};
			__m_count_195 = (((int)0) ? 0 : (fixdenorm(__m_count_195 + ((int)1))));
			int carry_196 = 0;
			if ((((int)0) != 0)) {
				__m_count_195 = 0;
				__m_carry_197 = 0;
				
			} else if (((selector_25 > 0) && (__m_count_195 >= selector_25))) {
				int wraps_198 = (__m_count_195 / selector_25);
				__m_carry_197 = (__m_carry_197 + wraps_198);
				__m_count_195 = (__m_count_195 - (wraps_198 * selector_25));
				carry_196 = 1;
				
			};
			int counter_177 = __m_count_195;
			int counter_178 = carry_196;
			int counter_179 = __m_carry_197;
			t_sample mul_36 = (counter_177 * switch_37);
			t_sample switch_100 = (selector_102 ? mul_36 : ((int)0));
			int index_trunc_199 = fixnan(floor(switch_100));
			bool index_ignore_200 = ((index_trunc_199 >= loopR_dim) || (index_trunc_199 < 0));
			if ((!index_ignore_200)) {
				m_loopR_36.write((clamp_87 + (m_loopR_36.read(index_trunc_199, 0) * slide_127)), index_trunc_199, 0);
				
			};
			t_sample mul_35 = (counter_177 * switch_37);
			t_sample switch_97 = (selector_102 ? mul_35 : ((int)0));
			int index_trunc_202 = fixnan(floor(switch_97));
			bool index_ignore_203 = ((index_trunc_202 >= loopR_dim) || (index_trunc_202 < 0));
			if ((!(chan_ignore_201 || index_ignore_203))) {
				m_loopR_36.write((clamp_84 + (m_loopR_36.read(index_trunc_202, ((int)1)) * slide_127)), index_trunc_202, ((int)1));
				
			};
			m_history_22 = history_236_next_238;
			m_history_20 = history_232_next_240;
			m_history_21 = history_234_next_239;
			m_history_19 = history_256_next_260;
			m_history_18 = history_236_next_460;
			m_history_16 = history_232_next_451;
			m_history_17 = history_234_next_454;
			m_history_15 = history_236_next_467;
			m_history_13 = history_232_next_468;
			m_history_14 = history_234_next_465;
			m_history_12 = history_236_next_480;
			m_history_10 = history_232_next_481;
			m_history_11 = history_234_next_478;
			m_history_9 = history_236_next_498;
			m_history_7 = history_232_next_492;
			m_history_8 = history_234_next_490;
			m_history_6 = history_236_next_510;
			m_history_4 = history_232_next_505;
			m_history_5 = history_234_next_503;
			m_history_3 = history_236_next_524;
			m_history_1 = history_232_next_518;
			m_history_2 = history_234_next_516;
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
	inline void set_ctrl2(t_param _value) {
		m_ctrl_23 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_loopM(void * _value) {
		m_loopM_24.setbuffer(_value);
	};
	inline void set_ctrl1(t_param _value) {
		m_ctrl_25 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw1(t_param _value) {
		m_sw_26 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw2(t_param _value) {
		m_sw_27 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_gate(t_param _value) {
		m_gate_28 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_ctrl7(t_param _value) {
		m_ctrl_29 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_ctrl6(t_param _value) {
		m_ctrl_30 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_ctrl4(t_param _value) {
		m_ctrl_31 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_ctrl3(t_param _value) {
		m_ctrl_32 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_loopL(void * _value) {
		m_loopL_33.setbuffer(_value);
	};
	inline void set_ctrl5(t_param _value) {
		m_ctrl_34 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_button(t_param _value) {
		m_button_35 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_loopR(void * _value) {
		m_loopR_36.setbuffer(_value);
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
		case 0: *value = self->m_button_35; break;
		case 1: *value = self->m_ctrl_25; break;
		case 2: *value = self->m_ctrl_23; break;
		case 3: *value = self->m_ctrl_32; break;
		case 4: *value = self->m_ctrl_31; break;
		case 5: *value = self->m_ctrl_34; break;
		case 6: *value = self->m_ctrl_30; break;
		case 7: *value = self->m_ctrl_29; break;
		case 8: *value = self->m_gate_28; break;
		
		
		
		case 12: *value = self->m_sw_26; break;
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
	// initialize parameter 0 ("m_button_35")
	pi = self->__commonstate.params + 0;
	pi->name = "button";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_button_35;
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
	// initialize parameter 2 ("m_ctrl_23")
	pi = self->__commonstate.params + 2;
	pi->name = "ctrl2";
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
	// initialize parameter 3 ("m_ctrl_32")
	pi = self->__commonstate.params + 3;
	pi->name = "ctrl3";
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
	// initialize parameter 6 ("m_ctrl_30")
	pi = self->__commonstate.params + 6;
	pi->name = "ctrl6";
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
	// initialize parameter 8 ("m_gate_28")
	pi = self->__commonstate.params + 8;
	pi->name = "gate";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_gate_28;
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
	// initialize parameter 10 ("m_loopM_24")
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
	// initialize parameter 11 ("m_loopR_36")
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
	// initialize parameter 12 ("m_sw_26")
	pi = self->__commonstate.params + 12;
	pi->name = "sw1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_26;
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
