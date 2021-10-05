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
	Data m_loop_23;
	Data m_loop_36;
	Data m_loop_25;
	Delta __m_delta_41;
	Phasor __m_phasor_73;
	Phasor __m_phasor_40;
	Phasor __m_phasor_116;
	Phasor __m_phasor_160;
	PlusEquals __m_pluseq_42;
	int __exception;
	int vectorsize;
	t_sample m_history_8;
	t_sample m_history_2;
	t_sample m_history_1;
	t_sample m_history_3;
	t_sample samples_to_seconds;
	t_sample __m_slide_37;
	t_sample m_history_4;
	t_sample __m_slide_43;
	t_sample m_ctrl_34;
	t_sample m_ctrl_35;
	t_sample __m_slide_46;
	t_sample __m_slide_49;
	t_sample __m_count_56;
	t_sample __m_slide_70;
	t_sample samplerate;
	t_sample __m_slide_113;
	t_sample m_ctrl_33;
	t_sample __m_carry_68;
	t_sample __m_carry_63;
	t_sample __m_count_66;
	t_sample __m_carry_58;
	t_sample __m_count_61;
	t_sample m_history_7;
	t_sample m_sw_32;
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
	t_sample m_ctrl_31;
	t_sample m_history_19;
	t_sample m_history_21;
	t_sample __m_slide_157;
	t_sample m_sw_28;
	t_sample m_ctrl_29;
	t_sample m_history_20;
	t_sample m_ctrl_26;
	t_sample m_button_24;
	t_sample m_history_5;
	t_sample m_history_22;
	t_sample m_history_6;
	t_sample m_gate_27;
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
		m_loop_23.reset("loop1", ((int)192000), ((int)2));
		m_button_24 = ((int)0);
		m_loop_25.reset("loop2", ((int)192000), ((int)2));
		m_ctrl_26 = ((int)0);
		m_gate_27 = ((int)0);
		m_sw_28 = ((int)0);
		m_ctrl_29 = ((int)0);
		m_ctrl_30 = ((int)0);
		m_ctrl_31 = ((int)0);
		m_sw_32 = ((int)0);
		m_ctrl_33 = ((int)0);
		m_ctrl_34 = ((int)0);
		m_ctrl_35 = ((int)0);
		m_loop_36.reset("loop3", ((int)192000), ((int)2));
		__m_slide_37 = 0;
		samples_to_seconds = (1 / samplerate);
		__m_phasor_40.reset(0);
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
		int loop3_dim_483 = loop3_dim;
		int loop2_dim = m_loop_25.dim;
		int loop2_channels = m_loop_25.channels;
		int loop2_dim_485 = loop2_dim;
		int loop1_dim = m_loop_23.dim;
		int loop1_channels = m_loop_23.channels;
		int loop1_dim_493 = loop1_dim;
		t_sample iup_38 = (1 / maximum(1, abs(((int)4000))));
		t_sample idown_39 = (1 / maximum(1, abs(((int)4000))));
		samples_to_seconds = (1 / samplerate);
		int or_562 = (m_gate_27 || m_button_24);
		int gt_353 = (or_562 > ((int)0));
		t_sample div_321 = (loop1_dim_493 * ((t_sample)0.25));
		t_sample div_323 = (loop2_dim_485 * ((t_sample)1));
		t_sample div_320 = (loop3_dim_483 * ((t_sample)0.5));
		int eq_525 = (m_sw_32 == ((int)0));
		t_sample iup_44 = (1 / maximum(1, abs(((int)4000))));
		t_sample idown_45 = (1 / maximum(1, abs(((int)4000))));
		t_sample iup_47 = (1 / maximum(1, abs(((int)4000))));
		t_sample idown_48 = (1 / maximum(1, abs(((int)4000))));
		t_sample iup_50 = (1 / maximum(1, abs(((int)4000))));
		t_sample idown_51 = (1 / maximum(1, abs(((int)4000))));
		int eq_529 = (m_sw_32 == ((t_sample)0.5));
		t_sample switch_528 = (eq_529 ? ((int)0) : m_sw_32);
		t_sample switch_526 = (eq_525 ? ((t_sample)0.5) : switch_528);
		t_sample sub_2081 = (switch_526 - ((int)0));
		t_sample scale_2078 = ((safepow((sub_2081 * ((t_sample)1)), ((int)1)) * ((int)2)) + ((int)1));
		t_sample choice_52 = int(scale_2078);
		t_sample choice_53 = int(scale_2078);
		t_sample choice_54 = int(scale_2078);
		int neq_327 = (scale_2078 != ((int)2));
		int eq_519 = (m_sw_28 == ((int)0));
		int eq_523 = (m_sw_28 == ((t_sample)0.5));
		t_sample switch_522 = (eq_523 ? ((int)0) : m_sw_28);
		t_sample switch_520 = (eq_519 ? ((t_sample)0.5) : switch_522);
		t_sample sub_2085 = (switch_520 - ((int)0));
		t_sample scale_2082 = ((safepow((sub_2085 * ((t_sample)1)), ((int)1)) * ((int)2)) + ((int)1));
		t_sample choice_55 = int(scale_2082);
		t_sample selector_324 = ((choice_55 >= 3) ? div_320 : ((choice_55 >= 2) ? div_323 : ((choice_55 >= 1) ? div_321 : 0)));
		t_sample choice_60 = int(scale_2082);
		t_sample selector_325 = ((choice_60 >= 3) ? ((int)0) : ((choice_60 >= 2) ? div_323 : ((choice_60 >= 1) ? div_321 : 0)));
		t_sample choice_65 = int(scale_2082);
		t_sample selector_326 = ((choice_65 >= 3) ? div_321 : ((choice_65 >= 2) ? div_323 : ((choice_65 >= 1) ? div_321 : 0)));
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
			t_sample out8 = ((int)0);
			t_sample out7 = ((int)0);
			t_sample out10 = ((int)0);
			t_sample mix_2050 = (m_history_22 + (((t_sample)0.0042742627044161) * (m_ctrl_30 - m_history_22)));
			t_sample mix_534 = mix_2050;
			t_sample mix_2051 = (m_history_21 + (((t_sample)0.0042742627044161) * (mix_534 - m_history_21)));
			t_sample mix_532 = mix_2051;
			t_sample mix_2052 = (m_history_20 + (((t_sample)0.0042742627044161) * (mix_532 - m_history_20)));
			t_sample mix_530 = mix_2052;
			t_sample gen_540 = mix_530;
			t_sample history_535_next_537 = fixdenorm(mix_534);
			t_sample history_533_next_538 = fixdenorm(mix_532);
			t_sample history_531_next_539 = fixdenorm(mix_530);
			__m_slide_37 = fixdenorm((__m_slide_37 + (((gen_540 > __m_slide_37) ? iup_38 : idown_39) * (gen_540 - __m_slide_37))));
			t_sample slide_426 = __m_slide_37;
			t_sample phasor_319 = __m_phasor_40(((int)1), samples_to_seconds);
			t_sample out9 = phasor_319;
			t_sample fold_344 = fold(in1, (-1), ((int)0));
			t_sample fold_364 = fold(in2, (-1), ((int)0));
			int delta_558 = __m_delta_41(or_562);
			int gtep_557 = ((delta_558 >= ((int)1)) ? delta_558 : 0);
			t_sample plusequals_556 = __m_pluseq_42.post(gtep_557, m_history_19, 0);
			t_sample gen_561 = plusequals_556;
			int eq_554 = (plusequals_556 == ((int)2));
			t_sample history_555_next_559 = fixdenorm(eq_554);
			int gt_350 = (gen_561 > ((int)0));
			t_sample mix_2053 = (m_history_18 + (((t_sample)0.0042742627044161) * (m_ctrl_29 - m_history_18)));
			t_sample mix_1809 = mix_2053;
			t_sample mix_2054 = (m_history_17 + (((t_sample)0.0042742627044161) * (mix_1809 - m_history_17)));
			t_sample mix_1800 = mix_2054;
			t_sample mix_2055 = (m_history_16 + (((t_sample)0.0042742627044161) * (mix_1800 - m_history_16)));
			t_sample mix_1805 = mix_2055;
			t_sample gen_546 = mix_1805;
			t_sample history_535_next_1803 = fixdenorm(mix_1809);
			t_sample history_533_next_1801 = fixdenorm(mix_1800);
			t_sample history_531_next_1806 = fixdenorm(mix_1805);
			t_sample abs_368 = fabs(in2);
			t_sample add_367 = (abs_368 + ((t_sample)0.0001));
			t_sample rsub_370 = (((int)1) - add_367);
			t_sample abs_346 = fabs(in1);
			t_sample add_345 = (abs_346 + ((t_sample)0.0001));
			t_sample rsub_348 = (((int)1) - add_345);
			t_sample mix_2056 = (m_history_15 + (((t_sample)0.0042742627044161) * (m_ctrl_26 - m_history_15)));
			t_sample mix_1822 = mix_2056;
			t_sample mix_2057 = (m_history_14 + (((t_sample)0.0042742627044161) * (mix_1822 - m_history_14)));
			t_sample mix_1813 = mix_2057;
			t_sample mix_2058 = (m_history_13 + (((t_sample)0.0042742627044161) * (mix_1813 - m_history_13)));
			t_sample mix_1820 = mix_2058;
			t_sample gen_545 = mix_1820;
			t_sample history_535_next_1817 = fixdenorm(mix_1822);
			t_sample history_533_next_1814 = fixdenorm(mix_1813);
			t_sample history_531_next_1821 = fixdenorm(mix_1820);
			t_sample mix_2059 = (m_history_12 + (((t_sample)0.0042742627044161) * (m_ctrl_34 - m_history_12)));
			t_sample mix_1833 = mix_2059;
			t_sample mix_2060 = (m_history_11 + (((t_sample)0.0042742627044161) * (mix_1833 - m_history_11)));
			t_sample mix_1826 = mix_2060;
			t_sample mix_2061 = (m_history_10 + (((t_sample)0.0042742627044161) * (mix_1826 - m_history_10)));
			t_sample mix_1834 = mix_2061;
			t_sample gen_544 = mix_1834;
			t_sample history_535_next_1830 = fixdenorm(mix_1833);
			t_sample history_533_next_1827 = fixdenorm(mix_1826);
			t_sample history_531_next_1835 = fixdenorm(mix_1834);
			t_sample sub_2065 = (gen_544 - ((int)0));
			t_sample scale_2062 = ((safepow((sub_2065 * ((t_sample)1)), ((int)1)) * ((int)2)) + (-1));
			t_sample gtep_414 = ((scale_2062 >= ((int)0)) ? scale_2062 : 0);
			__m_slide_43 = fixdenorm((__m_slide_43 + (((gtep_414 > __m_slide_43) ? iup_44 : idown_45) * (gtep_414 - __m_slide_43))));
			t_sample slide_411 = __m_slide_43;
			t_sample ceil_331 = ceil(slide_411);
			t_sample sub_2069 = (gen_544 - ((int)0));
			t_sample scale_2066 = ((safepow((sub_2069 * ((t_sample)1)), ((int)1)) * ((int)2)) + (-1));
			t_sample abs_419 = fabs(scale_2066);
			t_sample sub_2073 = (abs_419 - ((int)1));
			t_sample scale_2070 = ((safepow((sub_2073 * ((t_sample)-1)), ((int)1)) * ((int)1)) + ((int)0));
			__m_slide_46 = fixdenorm((__m_slide_46 + (((scale_2070 > __m_slide_46) ? iup_47 : idown_48) * (scale_2070 - __m_slide_46))));
			t_sample slide_412 = __m_slide_46;
			t_sample ceil_332 = ceil(slide_412);
			t_sample sub_2077 = (gen_544 - ((int)0));
			t_sample scale_2074 = ((safepow((sub_2077 * ((t_sample)1)), ((int)1)) * ((int)2)) + (-1));
			t_sample ltep_416 = ((scale_2074 <= ((int)0)) ? scale_2074 : 0);
			t_sample abs_417 = fabs(ltep_416);
			__m_slide_49 = fixdenorm((__m_slide_49 + (((abs_417 > __m_slide_49) ? iup_50 : idown_51) * (abs_417 - __m_slide_49))));
			t_sample slide_413 = __m_slide_49;
			t_sample ceil_333 = ceil(slide_413);
			t_sample selector_401 = ((choice_52 >= 3) ? gt_350 : ((choice_52 >= 2) ? ((int)1) : ((choice_52 >= 1) ? gt_353 : 0)));
			t_sample selector_369 = ((choice_53 >= 3) ? gt_350 : ((choice_53 >= 2) ? ((int)1) : ((choice_53 >= 1) ? gt_353 : 0)));
			t_sample switch_371 = (selector_369 ? rsub_370 : fold_364);
			t_sample out4 = switch_371;
			t_sample selector_347 = ((choice_54 >= 3) ? gt_350 : ((choice_54 >= 2) ? ((int)1) : ((choice_54 >= 1) ? gt_353 : 0)));
			t_sample switch_349 = (selector_347 ? rsub_348 : fold_344);
			t_sample out3 = switch_349;
			t_sample switch_336 = (neq_327 ? ceil_331 : ((int)1));
			t_sample switch_338 = (neq_327 ? ceil_332 : ((int)1));
			t_sample switch_341 = (neq_327 ? ceil_333 : ((int)1));
			__m_count_56 = (((int)0) ? 0 : (fixdenorm(__m_count_56 + ((int)1))));
			int carry_57 = 0;
			if ((((int)0) != 0)) {
				__m_count_56 = 0;
				__m_carry_58 = 0;
				
			} else if (((selector_324 > 0) && (__m_count_56 >= selector_324))) {
				int wraps_59 = (__m_count_56 / selector_324);
				__m_carry_58 = (__m_carry_58 + wraps_59);
				__m_count_56 = (__m_count_56 - (wraps_59 * selector_324));
				carry_57 = 1;
				
			};
			int counter_476 = __m_count_56;
			int counter_477 = carry_57;
			int counter_478 = __m_carry_58;
			t_sample mul_334 = (counter_476 * switch_336);
			t_sample switch_396 = (selector_401 ? mul_334 : ((int)0));
			t_sample mul_335 = (counter_476 * switch_336);
			t_sample switch_399 = (selector_401 ? mul_335 : ((int)0));
			__m_count_61 = (((int)0) ? 0 : (fixdenorm(__m_count_61 + ((int)1))));
			int carry_62 = 0;
			if ((((int)0) != 0)) {
				__m_count_61 = 0;
				__m_carry_63 = 0;
				
			} else if (((selector_325 > 0) && (__m_count_61 >= selector_325))) {
				int wraps_64 = (__m_count_61 / selector_325);
				__m_carry_63 = (__m_carry_63 + wraps_64);
				__m_count_61 = (__m_count_61 - (wraps_64 * selector_325));
				carry_62 = 1;
				
			};
			int counter_480 = __m_count_61;
			int counter_481 = carry_62;
			int counter_482 = __m_carry_63;
			t_sample mul_337 = (switch_338 * counter_480);
			t_sample switch_397 = (selector_401 ? mul_337 : ((int)0));
			t_sample mul_339 = (switch_338 * counter_480);
			t_sample switch_398 = (selector_401 ? mul_339 : ((int)0));
			__m_count_66 = (((int)0) ? 0 : (fixdenorm(__m_count_66 + ((int)1))));
			int carry_67 = 0;
			if ((((int)0) != 0)) {
				__m_count_66 = 0;
				__m_carry_68 = 0;
				
			} else if (((selector_326 > 0) && (__m_count_66 >= selector_326))) {
				int wraps_69 = (__m_count_66 / selector_326);
				__m_carry_68 = (__m_carry_68 + wraps_69);
				__m_count_66 = (__m_count_66 - (wraps_69 * selector_326));
				carry_67 = 1;
				
			};
			int counter_488 = __m_count_66;
			int counter_489 = carry_67;
			int counter_490 = __m_carry_68;
			t_sample mul_340 = (switch_341 * counter_488);
			t_sample switch_400 = (selector_401 ? mul_340 : ((int)0));
			t_sample mul_342 = (switch_341 * counter_488);
			t_sample switch_402 = (selector_401 ? mul_342 : ((int)0));
			t_sample mix_2086 = (m_history_9 + (((t_sample)0.0042742627044161) * (m_ctrl_35 - m_history_9)));
			t_sample mix_1842 = mix_2086;
			t_sample mix_2087 = (m_history_8 + (((t_sample)0.0042742627044161) * (mix_1842 - m_history_8)));
			t_sample mix_1839 = mix_2087;
			t_sample mix_2088 = (m_history_7 + (((t_sample)0.0042742627044161) * (mix_1839 - m_history_7)));
			t_sample mix_1847 = mix_2088;
			t_sample gen_542 = mix_1847;
			t_sample history_535_next_1841 = fixdenorm(mix_1842);
			t_sample history_533_next_1844 = fixdenorm(mix_1839);
			t_sample history_531_next_1848 = fixdenorm(mix_1847);
			t_sample sub_2092 = (gen_542 - ((int)0));
			t_sample scale_2089 = ((safepow((sub_2092 * ((t_sample)1)), ((int)1)) * ((int)2)) + (-1));
			t_sample abs_358 = fabs(scale_2089);
			t_sample sub_2096 = (abs_358 - ((int)1));
			t_sample scale_2093 = ((safepow((sub_2096 * ((t_sample)-1)), ((int)1)) * ((t_sample)7.5)) + ((t_sample)0.5));
			__m_slide_70 = fixdenorm((__m_slide_70 + (((scale_2093 > __m_slide_70) ? iup_71 : idown_72) * (scale_2093 - __m_slide_70))));
			t_sample slide_356 = __m_slide_70;
			t_sample rdiv_446 = safediv(((int)1), slide_356);
			t_sample phasor_447 = __m_phasor_73(rdiv_446, samples_to_seconds);
			t_sample mul_444 = (phasor_447 * ((int)2));
			t_sample sub_443 = (mul_444 - ((int)1));
			t_sample cos_442 = cos(sub_443);
			t_sample sub_441 = (cos_442 - ((t_sample)0.5));
			t_sample mul_440 = (sub_441 * ((int)10));
			t_sample clamp_439 = ((mul_440 <= ((int)0)) ? ((int)0) : ((mul_440 >= ((int)1)) ? ((int)1) : mul_440));
			t_sample fold_432 = fold(phasor_447, ((int)0), ((int)1));
			double sample_index_74 = (fold_432 * (loop3_dim - 1));
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
			t_sample sample_loop_437 = readinterp_88;
			t_sample index_loop_438 = sample_index_74;
			t_sample mul_431 = (sample_loop_437 * clamp_439);
			t_sample mix_2097 = (in1 + (gen_545 * (mul_431 - in1)));
			t_sample mul_408 = (mix_2097 * slide_411);
			t_sample clamp_386 = ((mul_408 <= min_89) ? min_89 : ((mul_408 >= ((int)1)) ? ((int)1) : mul_408));
			int index_trunc_90 = fixnan(floor(switch_399));
			int index_wrap_91 = ((index_trunc_90 < 0) ? ((loop3_dim - 1) + ((index_trunc_90 + 1) % loop3_dim)) : (index_trunc_90 % loop3_dim));
			m_loop_36.write((clamp_386 + (m_loop_36.read(index_wrap_91, 0) * slide_426)), index_wrap_91, 0);
			double sample_index_92 = (fold_432 * (loop3_dim - 1));
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
			t_sample sample_loop_435 = readinterp_107;
			t_sample index_loop_436 = sample_index_92;
			t_sample mul_430 = (sample_loop_435 * clamp_439);
			t_sample mix_2098 = (in2 + (gen_545 * (mul_430 - in2)));
			t_sample clamp_378 = ((mix_2098 <= min_108) ? min_108 : ((mix_2098 >= ((int)1)) ? ((int)1) : mix_2098));
			t_sample mul_405 = (clamp_378 * slide_411);
			t_sample clamp_383 = ((mul_405 <= min_109) ? min_109 : ((mul_405 >= ((int)1)) ? ((int)1) : mul_405));
			int index_trunc_111 = fixnan(floor(switch_396));
			int index_wrap_112 = ((index_trunc_111 < 0) ? ((loop3_dim - 1) + ((index_trunc_111 + 1) % loop3_dim)) : (index_trunc_111 % loop3_dim));
			if ((!chan_ignore_110)) {
				m_loop_36.write((clamp_383 + (m_loop_36.read(index_wrap_112, ((int)1)) * slide_426)), index_wrap_112, ((int)1));
				
			};
			t_sample mix_2099 = (m_history_6 + (((t_sample)0.0042742627044161) * (m_ctrl_31 - m_history_6)));
			t_sample mix_1855 = mix_2099;
			t_sample mix_2100 = (m_history_5 + (((t_sample)0.0042742627044161) * (mix_1855 - m_history_5)));
			t_sample mix_1852 = mix_2100;
			t_sample mix_2101 = (m_history_4 + (((t_sample)0.0042742627044161) * (mix_1852 - m_history_4)));
			t_sample mix_1860 = mix_2101;
			t_sample gen_541 = mix_1860;
			t_sample history_535_next_1854 = fixdenorm(mix_1855);
			t_sample history_533_next_1857 = fixdenorm(mix_1852);
			t_sample history_531_next_1861 = fixdenorm(mix_1860);
			t_sample sub_2105 = (gen_541 - ((int)0));
			t_sample scale_2102 = ((safepow((sub_2105 * ((t_sample)1)), ((int)1)) * ((int)2)) + (-1));
			t_sample abs_362 = fabs(scale_2102);
			t_sample sub_2109 = (abs_362 - ((int)1));
			t_sample scale_2106 = ((safepow((sub_2109 * ((t_sample)-1)), ((int)1)) * ((t_sample)7.5)) + ((t_sample)0.5));
			__m_slide_113 = fixdenorm((__m_slide_113 + (((scale_2106 > __m_slide_113) ? iup_114 : idown_115) * (scale_2106 - __m_slide_113))));
			t_sample slide_360 = __m_slide_113;
			t_sample rdiv_467 = safediv(((int)1), slide_360);
			t_sample phasor_468 = __m_phasor_116(rdiv_467, samples_to_seconds);
			t_sample mul_465 = (phasor_468 * ((int)2));
			t_sample sub_464 = (mul_465 - ((int)1));
			t_sample cos_463 = cos(sub_464);
			t_sample sub_462 = (cos_463 - ((t_sample)0.5));
			t_sample mul_461 = (sub_462 * ((int)10));
			t_sample clamp_460 = ((mul_461 <= ((int)0)) ? ((int)0) : ((mul_461 >= ((int)1)) ? ((int)1) : mul_461));
			t_sample fold_453 = fold(phasor_468, ((int)0), ((int)1));
			double sample_index_117 = (fold_453 * (loop2_dim - 1));
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
			double read_loop_128 = ((chan_ignore_127 || index_ignore_123) ? 0 : m_loop_25.read(index_trunc_120, 1));
			double read_loop_129 = ((chan_ignore_127 || index_ignore_124) ? 0 : m_loop_25.read(index_trunc_118, 1));
			double read_loop_130 = ((chan_ignore_127 || index_ignore_125) ? 0 : m_loop_25.read(index_trunc_121, 1));
			double read_loop_131 = ((chan_ignore_127 || index_ignore_126) ? 0 : m_loop_25.read(index_trunc_122, 1));
			double readinterp_132 = spline_interp(index_fract_119, read_loop_128, read_loop_129, read_loop_130, read_loop_131);
			t_sample sample_loop_456 = readinterp_132;
			t_sample index_loop_457 = sample_index_117;
			t_sample mul_451 = (sample_loop_456 * clamp_460);
			t_sample mix_2110 = (in2 + (gen_545 * (mul_451 - in2)));
			t_sample clamp_380 = ((mix_2110 <= min_133) ? min_133 : ((mix_2110 >= ((int)1)) ? ((int)1) : mix_2110));
			t_sample mul_406 = (clamp_380 * slide_412);
			t_sample clamp_384 = ((mul_406 <= min_134) ? min_134 : ((mul_406 >= ((int)1)) ? ((int)1) : mul_406));
			int index_trunc_136 = fixnan(floor(switch_397));
			int index_wrap_137 = ((index_trunc_136 < 0) ? ((loop2_dim - 1) + ((index_trunc_136 + 1) % loop2_dim)) : (index_trunc_136 % loop2_dim));
			if ((!chan_ignore_135)) {
				m_loop_25.write((clamp_384 + (m_loop_25.read(index_wrap_137, ((int)1)) * slide_426)), index_wrap_137, ((int)1));
				
			};
			double sample_index_138 = (fold_453 * (loop2_dim - 1));
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
			double read_loop_148 = (index_ignore_144 ? 0 : m_loop_25.read(index_trunc_141, 0));
			double read_loop_149 = (index_ignore_145 ? 0 : m_loop_25.read(index_trunc_139, 0));
			double read_loop_150 = (index_ignore_146 ? 0 : m_loop_25.read(index_trunc_142, 0));
			double read_loop_151 = (index_ignore_147 ? 0 : m_loop_25.read(index_trunc_143, 0));
			double readinterp_152 = spline_interp(index_fract_140, read_loop_148, read_loop_149, read_loop_150, read_loop_151);
			t_sample sample_loop_458 = readinterp_152;
			t_sample index_loop_459 = sample_index_138;
			t_sample mul_452 = (sample_loop_458 * clamp_460);
			t_sample mix_2111 = (in1 + (gen_545 * (mul_452 - in1)));
			t_sample clamp_390 = ((mix_2111 <= min_153) ? min_153 : ((mix_2111 >= ((int)1)) ? ((int)1) : mix_2111));
			t_sample mul_409 = (clamp_390 * slide_412);
			t_sample clamp_387 = ((mul_409 <= min_154) ? min_154 : ((mul_409 >= ((int)1)) ? ((int)1) : mul_409));
			int index_trunc_155 = fixnan(floor(switch_398));
			int index_wrap_156 = ((index_trunc_155 < 0) ? ((loop2_dim - 1) + ((index_trunc_155 + 1) % loop2_dim)) : (index_trunc_155 % loop2_dim));
			m_loop_25.write((clamp_387 + (m_loop_25.read(index_wrap_156, 0) * slide_426)), index_wrap_156, 0);
			t_sample mix_2112 = (m_history_3 + (((t_sample)0.0042742627044161) * (m_ctrl_33 - m_history_3)));
			t_sample mix_1872 = mix_2112;
			t_sample mix_2113 = (m_history_2 + (((t_sample)0.0042742627044161) * (mix_1872 - m_history_2)));
			t_sample mix_1869 = mix_2113;
			t_sample mix_2114 = (m_history_1 + (((t_sample)0.0042742627044161) * (mix_1869 - m_history_1)));
			t_sample mix_1873 = mix_2114;
			t_sample gen_543 = mix_1873;
			t_sample history_535_next_1868 = fixdenorm(mix_1872);
			t_sample history_533_next_1865 = fixdenorm(mix_1869);
			t_sample history_531_next_1874 = fixdenorm(mix_1873);
			t_sample sub_2118 = (gen_543 - ((int)0));
			t_sample scale_2115 = ((safepow((sub_2118 * ((t_sample)1)), ((int)1)) * ((int)2)) + (-1));
			t_sample abs_374 = fabs(scale_2115);
			t_sample sub_2122 = (abs_374 - ((int)1));
			t_sample scale_2119 = ((safepow((sub_2122 * ((t_sample)-1)), ((int)1)) * ((t_sample)7.5)) + ((t_sample)0.5));
			__m_slide_157 = fixdenorm((__m_slide_157 + (((scale_2119 > __m_slide_157) ? iup_158 : idown_159) * (scale_2119 - __m_slide_157))));
			t_sample slide_372 = __m_slide_157;
			t_sample rdiv_514 = safediv(((int)1), slide_372);
			t_sample phasor_515 = __m_phasor_160(rdiv_514, samples_to_seconds);
			t_sample mul_503 = (phasor_515 * ((int)2));
			t_sample sub_502 = (mul_503 - ((int)1));
			t_sample cos_501 = cos(sub_502);
			t_sample sub_500 = (cos_501 - ((t_sample)0.5));
			t_sample mul_499 = (sub_500 * ((int)10));
			t_sample clamp_498 = ((mul_499 <= ((int)0)) ? ((int)0) : ((mul_499 >= ((int)1)) ? ((int)1) : mul_499));
			t_sample fold_505 = fold(phasor_515, ((int)0), ((int)1));
			double sample_index_161 = (fold_505 * (loop1_dim - 1));
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
			double read_loop_172 = ((chan_ignore_171 || index_ignore_167) ? 0 : m_loop_23.read(index_trunc_164, 1));
			double read_loop_173 = ((chan_ignore_171 || index_ignore_168) ? 0 : m_loop_23.read(index_trunc_162, 1));
			double read_loop_174 = ((chan_ignore_171 || index_ignore_169) ? 0 : m_loop_23.read(index_trunc_165, 1));
			double read_loop_175 = ((chan_ignore_171 || index_ignore_170) ? 0 : m_loop_23.read(index_trunc_166, 1));
			double readinterp_176 = spline_interp(index_fract_163, read_loop_172, read_loop_173, read_loop_174, read_loop_175);
			t_sample sample_loop_509 = readinterp_176;
			t_sample index_loop_510 = sample_index_161;
			t_sample mul_497 = (sample_loop_509 * clamp_498);
			t_sample mix_2123 = (in2 + (gen_545 * (mul_497 - in2)));
			t_sample clamp_382 = ((mix_2123 <= min_177) ? min_177 : ((mix_2123 >= ((int)1)) ? ((int)1) : mix_2123));
			t_sample mul_407 = (clamp_382 * slide_413);
			t_sample clamp_385 = ((mul_407 <= min_178) ? min_178 : ((mul_407 >= ((int)1)) ? ((int)1) : mul_407));
			int index_trunc_180 = fixnan(floor(switch_400));
			int index_wrap_181 = ((index_trunc_180 < 0) ? ((loop1_dim - 1) + ((index_trunc_180 + 1) % loop1_dim)) : (index_trunc_180 % loop1_dim));
			if ((!chan_ignore_179)) {
				m_loop_23.write((clamp_385 + (m_loop_23.read(index_wrap_181, ((int)1)) * slide_426)), index_wrap_181, ((int)1));
				
			};
			t_sample mix_2124 = (mul_497 + (((t_sample)0.5) * (mul_451 - mul_497)));
			t_sample mix_2125 = (mix_2124 + (((t_sample)0.66) * (mul_430 - mix_2124)));
			t_sample mul_403 = (mix_2125 * ((int)4));
			t_sample mix_2126 = (in2 + (gen_546 * (mul_403 - in2)));
			t_sample clamp_423 = ((mix_2126 <= min_182) ? min_182 : ((mix_2126 >= ((int)1)) ? ((int)1) : mix_2126));
			t_sample out2 = clamp_423;
			t_sample fold_365 = fold(clamp_423, (-1), ((int)0));
			t_sample out6 = fold_365;
			double sample_index_183 = (fold_505 * (loop1_dim - 1));
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
			double read_loop_193 = (index_ignore_189 ? 0 : m_loop_23.read(index_trunc_186, 0));
			double read_loop_194 = (index_ignore_190 ? 0 : m_loop_23.read(index_trunc_184, 0));
			double read_loop_195 = (index_ignore_191 ? 0 : m_loop_23.read(index_trunc_187, 0));
			double read_loop_196 = (index_ignore_192 ? 0 : m_loop_23.read(index_trunc_188, 0));
			double readinterp_197 = spline_interp(index_fract_185, read_loop_193, read_loop_194, read_loop_195, read_loop_196);
			t_sample sample_loop_511 = readinterp_197;
			t_sample index_loop_512 = sample_index_183;
			t_sample mul_496 = (sample_loop_511 * clamp_498);
			t_sample mix_2127 = (in1 + (gen_545 * (mul_496 - in1)));
			t_sample clamp_391 = ((mix_2127 <= min_198) ? min_198 : ((mix_2127 >= ((int)1)) ? ((int)1) : mix_2127));
			t_sample mul_410 = (clamp_391 * slide_413);
			t_sample clamp_388 = ((mul_410 <= min_199) ? min_199 : ((mul_410 >= ((int)1)) ? ((int)1) : mul_410));
			int index_trunc_200 = fixnan(floor(switch_402));
			int index_wrap_201 = ((index_trunc_200 < 0) ? ((loop1_dim - 1) + ((index_trunc_200 + 1) % loop1_dim)) : (index_trunc_200 % loop1_dim));
			m_loop_23.write((clamp_388 + (m_loop_23.read(index_wrap_201, 0) * slide_426)), index_wrap_201, 0);
			t_sample mix_2128 = (mul_496 + (((t_sample)0.5) * (mul_452 - mul_496)));
			t_sample mix_2129 = (mix_2128 + (((t_sample)0.66) * (mul_431 - mix_2128)));
			t_sample mul_404 = (mix_2129 * ((int)4));
			t_sample mix_2130 = (in1 + (gen_546 * (mul_404 - in1)));
			t_sample clamp_424 = ((mix_2130 <= min_202) ? min_202 : ((mix_2130 >= ((int)1)) ? ((int)1) : mix_2130));
			t_sample out1 = clamp_424;
			t_sample fold_366 = fold(clamp_424, (-1), ((int)0));
			t_sample out5 = fold_366;
			m_history_22 = history_535_next_537;
			m_history_20 = history_531_next_539;
			m_history_21 = history_533_next_538;
			m_history_19 = history_555_next_559;
			m_history_18 = history_535_next_1803;
			m_history_16 = history_531_next_1806;
			m_history_17 = history_533_next_1801;
			m_history_15 = history_535_next_1817;
			m_history_13 = history_531_next_1821;
			m_history_14 = history_533_next_1814;
			m_history_12 = history_535_next_1830;
			m_history_10 = history_531_next_1835;
			m_history_11 = history_533_next_1827;
			m_history_9 = history_535_next_1841;
			m_history_7 = history_531_next_1848;
			m_history_8 = history_533_next_1844;
			m_history_6 = history_535_next_1854;
			m_history_4 = history_531_next_1861;
			m_history_5 = history_533_next_1857;
			m_history_3 = history_535_next_1868;
			m_history_1 = history_531_next_1874;
			m_history_2 = history_533_next_1865;
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
	inline void set_loop1(void * _value) {
		m_loop_23.setbuffer(_value);
	};
	inline void set_button(t_param _value) {
		m_button_24 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_loop2(void * _value) {
		m_loop_25.setbuffer(_value);
	};
	inline void set_ctrl5(t_param _value) {
		m_ctrl_26 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_gate(t_param _value) {
		m_gate_27 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw2(t_param _value) {
		m_sw_28 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_ctrl1(t_param _value) {
		m_ctrl_29 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_ctrl7(t_param _value) {
		m_ctrl_30 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_ctrl4(t_param _value) {
		m_ctrl_31 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw1(t_param _value) {
		m_sw_32 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_ctrl2(t_param _value) {
		m_ctrl_33 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_ctrl3(t_param _value) {
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
		case 0: *value = self->m_button_24; break;
		case 1: *value = self->m_ctrl_29; break;
		case 2: *value = self->m_ctrl_33; break;
		case 3: *value = self->m_ctrl_34; break;
		case 4: *value = self->m_ctrl_31; break;
		case 5: *value = self->m_ctrl_26; break;
		case 6: *value = self->m_ctrl_35; break;
		case 7: *value = self->m_ctrl_30; break;
		case 8: *value = self->m_gate_27; break;
		
		
		
		case 12: *value = self->m_sw_32; break;
		case 13: *value = self->m_sw_28; break;
		
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
	// initialize parameter 0 ("m_button_24")
	pi = self->__commonstate.params + 0;
	pi->name = "button";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_button_24;
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
	// initialize parameter 2 ("m_ctrl_33")
	pi = self->__commonstate.params + 2;
	pi->name = "ctrl2";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_ctrl_33;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 3 ("m_ctrl_34")
	pi = self->__commonstate.params + 3;
	pi->name = "ctrl3";
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
	// initialize parameter 5 ("m_ctrl_26")
	pi = self->__commonstate.params + 5;
	pi->name = "ctrl5";
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
	// initialize parameter 7 ("m_ctrl_30")
	pi = self->__commonstate.params + 7;
	pi->name = "ctrl7";
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
	// initialize parameter 8 ("m_gate_27")
	pi = self->__commonstate.params + 8;
	pi->name = "gate";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_gate_27;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 9 ("m_loop_23")
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
	// initialize parameter 10 ("m_loop_25")
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
	// initialize parameter 12 ("m_sw_32")
	pi = self->__commonstate.params + 12;
	pi->name = "sw1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_32;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 13 ("m_sw_28")
	pi = self->__commonstate.params + 13;
	pi->name = "sw2";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_28;
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
