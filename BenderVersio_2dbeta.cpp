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
	Data m_sample_25;
	Data m_pitchloop_28;
	Delta __m_delta_42;
	Delta __m_delta_43;
	Delta __m_delta_50;
	Phasor __m_phasor_47;
	Phasor __m_phasor_41;
	PlusEquals __m_pluseq_30;
	PlusEquals __m_pluseq_51;
	Sah __m_sah_48;
	Sah __m_sah_54;
	int __exception;
	int vectorsize;
	t_sample __m_count_34;
	t_sample m_history_10;
	t_sample __m_carry_36;
	t_sample samples_to_seconds;
	t_sample __m_latch_32;
	t_sample m_history_6;
	t_sample __m_count_31;
	t_sample m_history_5;
	t_sample m_history_4;
	t_sample m_history_3;
	t_sample samplerate;
	t_sample __m_count_52;
	t_sample __m_count_29;
	t_sample m_history_1;
	t_sample __m_slide_44;
	t_sample m_history_2;
	t_sample m_history_9;
	t_sample m_history_7;
	t_sample m_ctrl_26;
	t_sample m_history_15;
	t_sample m_ctrl_16;
	t_sample m_ctrl_17;
	t_sample m_history_14;
	t_sample m_history_12;
	t_sample m_history_13;
	t_sample m_history_11;
	t_sample m_button_27;
	t_sample m_sw_18;
	t_sample m_ctrl_20;
	t_sample m_ctrl_24;
	t_sample m_history_8;
	t_sample m_ctrl_19;
	t_sample m_sw_23;
	t_sample m_gate_21;
	t_sample __m_latch_53;
	t_sample m_ctrl_22;
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
		m_ctrl_16 = ((int)0);
		m_ctrl_17 = ((int)0);
		m_sw_18 = ((int)0);
		m_ctrl_19 = ((int)0);
		m_ctrl_20 = ((int)0);
		m_gate_21 = ((int)0);
		m_ctrl_22 = ((int)0);
		m_sw_23 = ((int)0);
		m_ctrl_24 = ((int)0);
		m_sample_25.reset("sample", ((int)196000), ((int)1));
		m_ctrl_26 = ((int)0);
		m_button_27 = ((int)0);
		m_pitchloop_28.reset("pitchloop", ((int)48000), ((int)2));
		__m_count_29 = 0;
		__m_pluseq_30.reset(0);
		__m_count_31 = 0;
		__m_latch_32 = 0;
		__m_count_34 = 0;
		__m_carry_36 = 0;
		samples_to_seconds = (1 / samplerate);
		__m_phasor_41.reset(0);
		__m_delta_42.reset(0);
		__m_delta_43.reset(0);
		__m_slide_44 = 0;
		__m_phasor_47.reset(0);
		__m_sah_48.reset(0);
		__m_delta_50.reset(0);
		__m_pluseq_51.reset(0);
		__m_count_52 = 0;
		__m_latch_53 = 0;
		__m_sah_54.reset(0);
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
		int pitchloop_dim = m_pitchloop_28.dim;
		int pitchloop_channels = m_pitchloop_28.channels;
		int pitchloop_dim_1764 = pitchloop_dim;
		int sample_dim = m_sample_25.dim;
		int sample_channels = m_sample_25.channels;
		bool chan_ignore_39 = ((((int)1) < 0) || (((int)1) >= pitchloop_channels));
		samples_to_seconds = (1 / samplerate);
		t_sample iup_45 = (1 / maximum(1, abs(((int)300))));
		t_sample idown_46 = (1 / maximum(1, abs(((int)300))));
		int or_47 = (m_gate_21 || m_button_27);
		bool chan_ignore_80 = ((1 < 0) || (1 >= pitchloop_channels));
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			const t_sample in2 = (*(__in2++));
			t_sample out6 = ((int)0);
			t_sample out3 = ((int)0);
			t_sample out5 = ((int)0);
			t_sample out4 = ((int)0);
			t_sample out9 = ((int)0);
			t_sample out7 = ((int)0);
			t_sample out8 = ((int)0);
			__m_count_29 = (((int)0) ? 0 : (fixdenorm(__m_count_29 + ((int)1))));
			int counter_154 = __m_count_29;
			int counter_155 = ((int)0);
			int counter_156 = ((int)0);
			t_sample plusequals_163 = __m_pluseq_30.post(((int)0), m_history_15, 0);
			int eq_161 = (plusequals_163 == ((int)2));
			__m_count_31 = (m_history_15 ? 0 : (fixdenorm(__m_count_31 + plusequals_163)));
			t_sample counter_158 = __m_count_31;
			int counter_159 = ((int)0);
			int counter_160 = ((int)0);
			__m_latch_32 = ((eq_161 != 0) ? counter_158 : __m_latch_32);
			t_sample latch_157 = __m_latch_32;
			t_sample gen_167 = latch_157;
			t_sample history_162_next_166 = fixdenorm(eq_161);
			bool index_ignore_33 = ((counter_154 >= sample_dim) || (counter_154 < 0));
			if ((!index_ignore_33)) {
				m_sample_25.write(((int)0), counter_154, 0);
				
			};
			__m_count_34 = (((int)0) ? 0 : (fixdenorm(__m_count_34 + ((int)1))));
			int carry_35 = 0;
			if ((((int)0) != 0)) {
				__m_count_34 = 0;
				__m_carry_36 = 0;
				
			} else if (((pitchloop_dim_1764 > 0) && (__m_count_34 >= pitchloop_dim_1764))) {
				int wraps_37 = (__m_count_34 / pitchloop_dim_1764);
				__m_carry_36 = (__m_carry_36 + wraps_37);
				__m_count_34 = (__m_count_34 - (wraps_37 * pitchloop_dim_1764));
				carry_35 = 1;
				
			};
			int counter_1735 = __m_count_34;
			int counter_1736 = carry_35;
			int counter_1737 = __m_carry_36;
			int index_wrap_38 = ((counter_1735 < 0) ? ((pitchloop_dim - 1) + ((counter_1735 + 1) % pitchloop_dim)) : (counter_1735 % pitchloop_dim));
			m_pitchloop_28.write(in1, index_wrap_38, 0);
			int index_wrap_40 = ((counter_1735 < 0) ? ((pitchloop_dim - 1) + ((counter_1735 + 1) % pitchloop_dim)) : (counter_1735 % pitchloop_dim));
			if ((!chan_ignore_39)) {
				m_pitchloop_28.write(in2, index_wrap_40, ((int)1));
				
			};
			t_sample div_143 = safediv(gen_167, samplerate);
			t_sample rdiv_144 = safediv(((int)1), div_143);
			t_sample mix_2690 = (m_history_14 + (((t_sample)0.0042742627044161) * (m_ctrl_16 - m_history_14)));
			t_sample mix_19 = mix_2690;
			t_sample mix_2691 = (m_history_13 + (((t_sample)0.0042742627044161) * (mix_19 - m_history_13)));
			t_sample mix_17 = mix_2691;
			t_sample mix_2692 = (m_history_12 + (((t_sample)0.0042742627044161) * (mix_17 - m_history_12)));
			t_sample mix_15 = mix_2692;
			t_sample gen_31 = mix_15;
			t_sample history_20_next_22 = fixdenorm(mix_19);
			t_sample history_18_next_23 = fixdenorm(mix_17);
			t_sample history_16_next_24 = fixdenorm(mix_15);
			t_sample mix_2693 = (m_history_11 + (((t_sample)0.0042742627044161) * (m_ctrl_24 - m_history_11)));
			t_sample mix_2590 = mix_2693;
			t_sample mix_2694 = (m_history_10 + (((t_sample)0.0042742627044161) * (mix_2590 - m_history_10)));
			t_sample mix_2597 = mix_2694;
			t_sample mix_2695 = (m_history_9 + (((t_sample)0.0042742627044161) * (mix_2597 - m_history_9)));
			t_sample mix_2593 = mix_2695;
			t_sample gen_27 = mix_2593;
			t_sample history_20_next_2594 = fixdenorm(mix_2590);
			t_sample history_18_next_2591 = fixdenorm(mix_2597);
			t_sample history_16_next_2592 = fixdenorm(mix_2593);
			t_sample rsub_1708 = (((int)1) - gen_27);
			t_sample sub_2699 = (rsub_1708 - ((t_sample)0.0001));
			t_sample scale_2696 = ((safepow((sub_2699 * ((t_sample)1.000200040008)), ((int)1)) * ((t_sample)1.75)) + ((t_sample)0.25));
			t_sample rdiv_1741 = safediv(((int)1), scale_2696);
			t_sample phasor_1757 = __m_phasor_41(rdiv_1741, samples_to_seconds);
			t_sample mul_1721 = (phasor_1757 * ((int)2));
			t_sample sub_1720 = (mul_1721 - ((int)1));
			t_sample cos_1719 = cos(sub_1720);
			t_sample sub_1718 = (cos_1719 - ((t_sample)0.5));
			t_sample mul_1717 = (sub_1718 * ((int)10));
			t_sample clamp_1716 = ((mul_1717 <= ((int)0)) ? ((int)0) : ((mul_1717 >= ((int)1)) ? ((int)1) : mul_1717));
			t_sample rsub_1755 = (((int)1) - phasor_1757);
			t_sample delta_1728 = __m_delta_42(phasor_1757);
			t_sample abs_1724 = fabs(delta_1728);
			t_sample delta_1731 = __m_delta_43(phasor_1757);
			t_sample abs_1725 = fabs(delta_1731);
			t_sample mix_2700 = (m_history_8 + (((t_sample)0.0042742627044161) * (m_ctrl_19 - m_history_8)));
			t_sample mix_2603 = mix_2700;
			t_sample mix_2701 = (m_history_7 + (((t_sample)0.0042742627044161) * (mix_2603 - m_history_7)));
			t_sample mix_2611 = mix_2701;
			t_sample mix_2702 = (m_history_6 + (((t_sample)0.0042742627044161) * (mix_2611 - m_history_6)));
			t_sample mix_2609 = mix_2702;
			t_sample gen_28 = mix_2609;
			t_sample history_20_next_2607 = fixdenorm(mix_2603);
			t_sample history_18_next_2608 = fixdenorm(mix_2611);
			t_sample history_16_next_2605 = fixdenorm(mix_2609);
			t_sample MOD_2346 = gen_28;
			t_sample MOD_245 = MOD_2346;
			__m_slide_44 = fixdenorm((__m_slide_44 + (((MOD_245 > __m_slide_44) ? iup_45 : idown_46) * (MOD_245 - __m_slide_44))));
			t_sample slide_122 = __m_slide_44;
			t_sample mul_127 = (slide_122 * ((int)7));
			int int_130 = int(mul_127);
			t_sample pow_129 = safepow(((int)2), int_130);
			t_sample slices_134 = pow_129;
			t_sample mul_142 = (rdiv_144 * slices_134);
			t_sample phasor_145 = __m_phasor_47(mul_142, samples_to_seconds);
			t_sample mul_1712 = (MOD_2346 * ((int)2));
			t_sample sah_1730 = __m_sah_48(mul_1712, abs_1725, ((t_sample)0.999));
			t_sample mod_1713 = safemod(sah_1730, ((int)1));
			int gt_1711 = (mul_1712 > ((int)1));
			int add_1710 = (gt_1711 + ((int)1));
			int choice_49 = add_1710;
			t_sample selector_1756 = ((choice_49 >= 2) ? rsub_1755 : ((choice_49 >= 1) ? phasor_1757 : 0));
			t_sample mix_2703 = (m_history_5 + (((t_sample)0.0042742627044161) * (m_ctrl_22 - m_history_5)));
			t_sample mix_2616 = mix_2703;
			t_sample mix_2704 = (m_history_4 + (((t_sample)0.0042742627044161) * (mix_2616 - m_history_4)));
			t_sample mix_2624 = mix_2704;
			t_sample mix_2705 = (m_history_3 + (((t_sample)0.0042742627044161) * (mix_2624 - m_history_3)));
			t_sample mix_2622 = mix_2705;
			t_sample gen_29 = mix_2622;
			t_sample history_20_next_2620 = fixdenorm(mix_2616);
			t_sample history_18_next_2621 = fixdenorm(mix_2624);
			t_sample history_16_next_2618 = fixdenorm(mix_2622);
			int delta_1705 = __m_delta_50(or_47);
			int gtep_1704 = ((delta_1705 >= ((int)1)) ? delta_1705 : 0);
			t_sample plusequals_1703 = __m_pluseq_51.post(gtep_1704, m_history_2, 0);
			int eq_1701 = (plusequals_1703 == ((int)2));
			__m_count_52 = (m_history_2 ? 0 : (fixdenorm(__m_count_52 + plusequals_1703)));
			t_sample counter_1698 = __m_count_52;
			int counter_1699 = ((int)0);
			int counter_1700 = ((int)0);
			__m_latch_53 = ((eq_1701 != 0) ? counter_1698 : __m_latch_53);
			t_sample latch_1697 = __m_latch_53;
			t_sample history_1702_next_1706 = fixdenorm(eq_1701);
			t_sample mul_1694 = (gen_29 * ((int)8));
			t_sample ceil_1693 = ceil(mul_1694);
			t_sample div_1692 = safediv(latch_1697, ceil_1693);
			t_sample div_1691 = (div_1692 * ((t_sample)2.0833333333333e-06));
			t_sample sah_1727 = __m_sah_54(div_1691, abs_1724, ((t_sample)0.9999));
			t_sample mod_1733 = safemod(selector_1756, sah_1727);
			t_sample add_1732 = (mod_1733 + mod_1713);
			t_sample fold_1723 = fold(add_1732, ((int)0), ((int)1));
			double sample_index_55 = (fold_1723 * (pitchloop_dim - 1));
			int index_trunc_56 = fixnan(floor(sample_index_55));
			double index_fract_57 = (sample_index_55 - index_trunc_56);
			int index_trunc_58 = (index_trunc_56 - 1);
			int index_trunc_59 = (index_trunc_56 + 1);
			int index_trunc_60 = (index_trunc_56 + 2);
			bool index_ignore_61 = ((index_trunc_58 >= pitchloop_dim) || (index_trunc_58 < 0));
			bool index_ignore_62 = ((index_trunc_56 >= pitchloop_dim) || (index_trunc_56 < 0));
			bool index_ignore_63 = ((index_trunc_59 >= pitchloop_dim) || (index_trunc_59 < 0));
			bool index_ignore_64 = ((index_trunc_60 >= pitchloop_dim) || (index_trunc_60 < 0));
			// phase pitchloop channel 1;
			double read_pitchloop_65 = (index_ignore_61 ? 0 : m_pitchloop_28.read(index_trunc_58, 0));
			double read_pitchloop_66 = (index_ignore_62 ? 0 : m_pitchloop_28.read(index_trunc_56, 0));
			double read_pitchloop_67 = (index_ignore_63 ? 0 : m_pitchloop_28.read(index_trunc_59, 0));
			double read_pitchloop_68 = (index_ignore_64 ? 0 : m_pitchloop_28.read(index_trunc_60, 0));
			double readinterp_69 = spline_interp(index_fract_57, read_pitchloop_65, read_pitchloop_66, read_pitchloop_67, read_pitchloop_68);
			t_sample sample_pitchloop_1761 = readinterp_69;
			t_sample index_pitchloop_1762 = sample_index_55;
			t_sample mul_1714 = (sample_pitchloop_1761 * clamp_1716);
			t_sample mix_2706 = (in1 + (gen_31 * (mul_1714 - in1)));
			t_sample out1 = mix_2706;
			double sample_index_70 = (fold_1723 * (pitchloop_dim - 1));
			int index_trunc_71 = fixnan(floor(sample_index_70));
			double index_fract_72 = (sample_index_70 - index_trunc_71);
			int index_trunc_73 = (index_trunc_71 - 1);
			int index_trunc_74 = (index_trunc_71 + 1);
			int index_trunc_75 = (index_trunc_71 + 2);
			bool index_ignore_76 = ((index_trunc_73 >= pitchloop_dim) || (index_trunc_73 < 0));
			bool index_ignore_77 = ((index_trunc_71 >= pitchloop_dim) || (index_trunc_71 < 0));
			bool index_ignore_78 = ((index_trunc_74 >= pitchloop_dim) || (index_trunc_74 < 0));
			bool index_ignore_79 = ((index_trunc_75 >= pitchloop_dim) || (index_trunc_75 < 0));
			// phase pitchloop channel 1;
			double read_pitchloop_81 = ((chan_ignore_80 || index_ignore_76) ? 0 : m_pitchloop_28.read(index_trunc_73, 1));
			double read_pitchloop_82 = ((chan_ignore_80 || index_ignore_77) ? 0 : m_pitchloop_28.read(index_trunc_71, 1));
			double read_pitchloop_83 = ((chan_ignore_80 || index_ignore_78) ? 0 : m_pitchloop_28.read(index_trunc_74, 1));
			double read_pitchloop_84 = ((chan_ignore_80 || index_ignore_79) ? 0 : m_pitchloop_28.read(index_trunc_75, 1));
			double readinterp_85 = spline_interp(index_fract_72, read_pitchloop_81, read_pitchloop_82, read_pitchloop_83, read_pitchloop_84);
			t_sample sample_pitchloop_1759 = readinterp_85;
			t_sample index_pitchloop_1760 = sample_index_70;
			t_sample mul_1715 = (sample_pitchloop_1759 * clamp_1716);
			t_sample mix_2707 = (in2 + (gen_31 * (mul_1715 - in2)));
			t_sample out2 = mix_2707;
			t_sample history_135_next_2629 = fixdenorm(phasor_145);
			m_history_15 = history_162_next_166;
			m_history_14 = history_20_next_22;
			m_history_12 = history_16_next_24;
			m_history_13 = history_18_next_23;
			m_history_11 = history_20_next_2594;
			m_history_9 = history_16_next_2592;
			m_history_10 = history_18_next_2591;
			m_history_8 = history_20_next_2607;
			m_history_6 = history_16_next_2605;
			m_history_7 = history_18_next_2608;
			m_history_5 = history_20_next_2620;
			m_history_3 = history_16_next_2618;
			m_history_4 = history_18_next_2621;
			m_history_2 = history_1702_next_1706;
			m_history_1 = history_135_next_2629;
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
	inline void set_ctrl1(t_param _value) {
		m_ctrl_16 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_ctrl7(t_param _value) {
		m_ctrl_17 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw1(t_param _value) {
		m_sw_18 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_ctrl2(t_param _value) {
		m_ctrl_19 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_ctrl5(t_param _value) {
		m_ctrl_20 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_gate(t_param _value) {
		m_gate_21 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_ctrl3(t_param _value) {
		m_ctrl_22 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw2(t_param _value) {
		m_sw_23 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_ctrl6(t_param _value) {
		m_ctrl_24 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sample(void * _value) {
		m_sample_25.setbuffer(_value);
	};
	inline void set_ctrl4(t_param _value) {
		m_ctrl_26 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_button(t_param _value) {
		m_button_27 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_pitchloop(void * _value) {
		m_pitchloop_28.setbuffer(_value);
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
int num_params() { return 13; }

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
		case 10: self->set_sample(ref); break;
		case 11: self->set_sw1(value); break;
		case 12: self->set_sw2(value); break;
		
		default: break;
	}
}

/// Get the value of a parameter of a State object

void getparameter(CommonState *cself, long index, t_param *value) {
	State *self = (State *)cself;
	switch (index) {
		case 0: *value = self->m_button_27; break;
		case 1: *value = self->m_ctrl_16; break;
		case 2: *value = self->m_ctrl_19; break;
		case 3: *value = self->m_ctrl_22; break;
		case 4: *value = self->m_ctrl_26; break;
		case 5: *value = self->m_ctrl_20; break;
		case 6: *value = self->m_ctrl_24; break;
		case 7: *value = self->m_ctrl_17; break;
		case 8: *value = self->m_gate_21; break;
		
		
		case 11: *value = self->m_sw_18; break;
		case 12: *value = self->m_sw_23; break;
		
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
	self->__commonstate.params = (ParamInfo *)genlib_sysmem_newptr(13 * sizeof(ParamInfo));
	self->__commonstate.numparams = 13;
	// initialize parameter 0 ("m_button_27")
	pi = self->__commonstate.params + 0;
	pi->name = "button";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_button_27;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 1 ("m_ctrl_16")
	pi = self->__commonstate.params + 1;
	pi->name = "ctrl1";
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
	// initialize parameter 2 ("m_ctrl_19")
	pi = self->__commonstate.params + 2;
	pi->name = "ctrl2";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_ctrl_19;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 3 ("m_ctrl_22")
	pi = self->__commonstate.params + 3;
	pi->name = "ctrl3";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_ctrl_22;
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
	// initialize parameter 5 ("m_ctrl_20")
	pi = self->__commonstate.params + 5;
	pi->name = "ctrl5";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_ctrl_20;
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
	// initialize parameter 7 ("m_ctrl_17")
	pi = self->__commonstate.params + 7;
	pi->name = "ctrl7";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_ctrl_17;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 8 ("m_gate_21")
	pi = self->__commonstate.params + 8;
	pi->name = "gate";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_gate_21;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 9 ("m_pitchloop_28")
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
	// initialize parameter 10 ("m_sample_25")
	pi = self->__commonstate.params + 10;
	pi->name = "sample";
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
	// initialize parameter 11 ("m_sw_18")
	pi = self->__commonstate.params + 11;
	pi->name = "sw1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_18;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 12 ("m_sw_23")
	pi = self->__commonstate.params + 12;
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
