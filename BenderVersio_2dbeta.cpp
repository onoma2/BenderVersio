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
	Data m_loop_23;
	Data m_loop_26;
	Data m_loop_27;
	Phasor __m_phasor_57;
	Phasor __m_phasor_95;
	Phasor __m_phasor_134;
	int __exception;
	int vectorsize;
	t_sample m_sw_33;
	t_sample m_ctrl_34;
	t_sample m_button_32;
	t_sample m_ctrl_35;
	t_sample m_ctrl_31;
	t_sample m_ctrl_29;
	t_sample m_ctrl_30;
	t_sample m_ctrl_28;
	t_sample __m_count_36;
	t_sample __m_carry_38;
	t_sample __m_count_40;
	t_sample __m_slide_51;
	t_sample __m_slide_54;
	t_sample samples_to_seconds;
	t_sample samplerate;
	t_sample __m_slide_48;
	t_sample __m_count_44;
	t_sample __m_carry_46;
	t_sample __m_carry_42;
	t_sample m_history_3;
	t_sample m_history_1;
	t_sample m_sw_24;
	t_sample m_history_10;
	t_sample m_history_11;
	t_sample m_history_12;
	t_sample m_history_13;
	t_sample m_history_9;
	t_sample m_history_7;
	t_sample m_history_8;
	t_sample m_history_5;
	t_sample m_history_6;
	t_sample m_ctrl_25;
	t_sample m_history_14;
	t_sample m_history_16;
	t_sample m_history_21;
	t_sample m_gate_22;
	t_sample m_history_2;
	t_sample m_history_15;
	t_sample m_history_20;
	t_sample m_history_18;
	t_sample m_history_19;
	t_sample m_history_17;
	t_sample m_history_4;
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
		m_gate_22 = ((int)0);
		m_loop_23.reset("loop3", ((int)96000), ((int)2));
		m_sw_24 = ((int)0);
		m_ctrl_25 = ((int)0);
		m_loop_26.reset("loop1", ((int)96000), ((int)2));
		m_loop_27.reset("loop2", ((int)96000), ((int)2));
		m_ctrl_28 = ((int)0);
		m_ctrl_29 = ((int)0);
		m_ctrl_30 = ((int)0);
		m_ctrl_31 = ((int)0);
		m_button_32 = ((int)0);
		m_sw_33 = ((int)0);
		m_ctrl_34 = ((int)0);
		m_ctrl_35 = ((int)0);
		__m_count_36 = 0;
		__m_carry_38 = 0;
		__m_count_40 = 0;
		__m_carry_42 = 0;
		__m_count_44 = 0;
		__m_carry_46 = 0;
		__m_slide_48 = 0;
		__m_slide_51 = 0;
		__m_slide_54 = 0;
		samples_to_seconds = (1 / samplerate);
		__m_phasor_57.reset(0);
		__m_phasor_95.reset(0);
		__m_phasor_134.reset(0);
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
		int loop2_dim = m_loop_27.dim;
		int loop2_channels = m_loop_27.channels;
		int loop2_dim_3906 = loop2_dim;
		int loop1_dim = m_loop_26.dim;
		int loop1_channels = m_loop_26.channels;
		int loop1_dim_3914 = loop1_dim;
		int loop3_dim = m_loop_23.dim;
		int loop3_channels = m_loop_23.channels;
		int loop3_dim_3904 = loop3_dim;
		int or_3986 = (m_gate_22 || m_button_32);
		int gt_3818 = (or_3986 > ((int)0));
		t_sample iup_49 = (1 / maximum(1, abs(((int)4000))));
		t_sample idown_50 = (1 / maximum(1, abs(((int)4000))));
		t_sample iup_52 = (1 / maximum(1, abs(((int)4000))));
		t_sample idown_53 = (1 / maximum(1, abs(((int)4000))));
		t_sample iup_55 = (1 / maximum(1, abs(((int)4000))));
		t_sample idown_56 = (1 / maximum(1, abs(((int)4000))));
		samples_to_seconds = (1 / samplerate);
		int min_73 = (-1);
		bool chan_ignore_85 = ((1 < 0) || (1 >= loop3_channels));
		int min_91 = (-1);
		int min_92 = (-1);
		bool chan_ignore_93 = ((((int)1) < 0) || (((int)1) >= loop3_channels));
		int min_111 = (-1);
		int min_112 = (-1);
		bool chan_ignore_124 = ((1 < 0) || (1 >= loop2_channels));
		int min_130 = (-1);
		int min_131 = (-1);
		bool chan_ignore_132 = ((((int)1) < 0) || (((int)1) >= loop2_channels));
		bool chan_ignore_145 = ((1 < 0) || (1 >= loop1_channels));
		int min_151 = (-1);
		int min_152 = (-1);
		bool chan_ignore_153 = ((((int)1) < 0) || (((int)1) >= loop1_channels));
		int min_155 = (-1);
		int min_171 = (-1);
		int min_172 = (-1);
		int min_174 = (-1);
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			const t_sample in2 = (*(__in2++));
			t_sample out5 = ((int)0);
			t_sample out6 = ((int)0);
			t_sample out4 = ((int)0);
			t_sample out3 = ((int)0);
			t_sample out7 = ((int)0);
			__m_count_36 = (((int)0) ? 0 : (fixdenorm(__m_count_36 + ((int)1))));
			int carry_37 = 0;
			if ((((int)0) != 0)) {
				__m_count_36 = 0;
				__m_carry_38 = 0;
				
			} else if (((loop3_dim_3904 > 0) && (__m_count_36 >= loop3_dim_3904))) {
				int wraps_39 = (__m_count_36 / loop3_dim_3904);
				__m_carry_38 = (__m_carry_38 + wraps_39);
				__m_count_36 = (__m_count_36 - (wraps_39 * loop3_dim_3904));
				carry_37 = 1;
				
			};
			int counter_3897 = __m_count_36;
			int counter_3898 = carry_37;
			int counter_3899 = __m_carry_38;
			int switch_3816 = (gt_3818 ? ((int)0) : counter_3897);
			int switch_3813 = (gt_3818 ? ((int)0) : counter_3897);
			t_sample mix_11491 = (m_history_21 + (((t_sample)0.0019634941468452) * (m_ctrl_31 - m_history_21)));
			t_sample mix_3958 = mix_11491;
			t_sample mix_11492 = (m_history_20 + (((t_sample)0.0019634941468452) * (mix_3958 - m_history_20)));
			t_sample mix_3956 = mix_11492;
			t_sample mix_11493 = (m_history_19 + (((t_sample)0.0019634941468452) * (mix_3956 - m_history_19)));
			t_sample mix_3954 = mix_11493;
			t_sample gen_3967 = mix_3954;
			t_sample history_3959_next_3961 = fixdenorm(mix_3958);
			t_sample history_3957_next_3962 = fixdenorm(mix_3956);
			t_sample history_3955_next_3963 = fixdenorm(mix_3954);
			t_sample sub_11497 = (gen_3967 - ((int)0));
			t_sample scale_11494 = ((safepow((sub_11497 * ((t_sample)1)), ((int)1)) * ((t_sample)1.1)) + ((int)0));
			__m_count_40 = (((int)0) ? 0 : (fixdenorm(__m_count_40 + ((int)1))));
			int carry_41 = 0;
			if ((((int)0) != 0)) {
				__m_count_40 = 0;
				__m_carry_42 = 0;
				
			} else if (((loop2_dim_3906 > 0) && (__m_count_40 >= loop2_dim_3906))) {
				int wraps_43 = (__m_count_40 / loop2_dim_3906);
				__m_carry_42 = (__m_carry_42 + wraps_43);
				__m_count_40 = (__m_count_40 - (wraps_43 * loop2_dim_3906));
				carry_41 = 1;
				
			};
			int counter_3901 = __m_count_40;
			int counter_3902 = carry_41;
			int counter_3903 = __m_carry_42;
			int switch_3815 = (gt_3818 ? ((int)0) : counter_3901);
			int switch_3814 = (gt_3818 ? ((int)0) : counter_3901);
			__m_count_44 = (((int)0) ? 0 : (fixdenorm(__m_count_44 + ((int)1))));
			int carry_45 = 0;
			if ((((int)0) != 0)) {
				__m_count_44 = 0;
				__m_carry_46 = 0;
				
			} else if (((loop1_dim_3914 > 0) && (__m_count_44 >= loop1_dim_3914))) {
				int wraps_47 = (__m_count_44 / loop1_dim_3914);
				__m_carry_46 = (__m_carry_46 + wraps_47);
				__m_count_44 = (__m_count_44 - (wraps_47 * loop1_dim_3914));
				carry_45 = 1;
				
			};
			int counter_3909 = __m_count_44;
			int counter_3910 = carry_45;
			int counter_3911 = __m_carry_46;
			int switch_3817 = (gt_3818 ? ((int)0) : counter_3909);
			int switch_3819 = (gt_3818 ? ((int)0) : counter_3909);
			t_sample mix_11498 = (m_history_18 + (((t_sample)0.0019634941468452) * (m_ctrl_30 - m_history_18)));
			t_sample mix_11000 = mix_11498;
			t_sample mix_11499 = (m_history_17 + (((t_sample)0.0019634941468452) * (mix_11000 - m_history_17)));
			t_sample mix_10997 = mix_11499;
			t_sample mix_11500 = (m_history_16 + (((t_sample)0.0019634941468452) * (mix_10997 - m_history_16)));
			t_sample mix_10993 = mix_11500;
			t_sample gen_3970 = mix_10993;
			t_sample history_3959_next_10995 = fixdenorm(mix_11000);
			t_sample history_3957_next_10998 = fixdenorm(mix_10997);
			t_sample history_3955_next_10999 = fixdenorm(mix_10993);
			t_sample mix_11501 = (m_history_15 + (((t_sample)0.0019634941468452) * (m_ctrl_34 - m_history_15)));
			t_sample mix_11014 = mix_11501;
			t_sample mix_11502 = (m_history_14 + (((t_sample)0.0019634941468452) * (mix_11014 - m_history_14)));
			t_sample mix_11011 = mix_11502;
			t_sample mix_11503 = (m_history_13 + (((t_sample)0.0019634941468452) * (mix_11011 - m_history_13)));
			t_sample mix_11006 = mix_11503;
			t_sample gen_3965 = mix_11006;
			t_sample history_3959_next_11008 = fixdenorm(mix_11014);
			t_sample history_3957_next_11013 = fixdenorm(mix_11011);
			t_sample history_3955_next_11012 = fixdenorm(mix_11006);
			t_sample sub_11507 = (gen_3965 - ((int)0));
			t_sample scale_11504 = ((safepow((sub_11507 * ((t_sample)1)), ((int)1)) * ((int)2)) + (-1));
			t_sample gtep_3831 = ((scale_11504 >= ((int)0)) ? scale_11504 : 0);
			__m_slide_48 = fixdenorm((__m_slide_48 + (((gtep_3831 > __m_slide_48) ? iup_49 : idown_50) * (gtep_3831 - __m_slide_48))));
			t_sample slide_3828 = __m_slide_48;
			t_sample out10 = slide_3828;
			t_sample sub_11511 = (gen_3965 - ((int)0));
			t_sample scale_11508 = ((safepow((sub_11511 * ((t_sample)1)), ((int)1)) * ((int)2)) + (-1));
			t_sample abs_3836 = fabs(scale_11508);
			t_sample sub_11515 = (abs_3836 - ((int)1));
			t_sample scale_11512 = ((safepow((sub_11515 * ((t_sample)-1)), ((int)1)) * ((int)1)) + ((int)0));
			__m_slide_51 = fixdenorm((__m_slide_51 + (((scale_11512 > __m_slide_51) ? iup_52 : idown_53) * (scale_11512 - __m_slide_51))));
			t_sample slide_3829 = __m_slide_51;
			t_sample out9 = slide_3829;
			t_sample sub_11519 = (gen_3965 - ((int)0));
			t_sample scale_11516 = ((safepow((sub_11519 * ((t_sample)1)), ((int)1)) * ((int)2)) + (-1));
			t_sample ltep_3833 = ((scale_11516 <= ((int)0)) ? scale_11516 : 0);
			t_sample abs_3834 = fabs(ltep_3833);
			__m_slide_54 = fixdenorm((__m_slide_54 + (((abs_3834 > __m_slide_54) ? iup_55 : idown_56) * (abs_3834 - __m_slide_54))));
			t_sample slide_3830 = __m_slide_54;
			t_sample out8 = slide_3830;
			t_sample mix_11520 = (m_history_12 + (((t_sample)0.0019634941468452) * (m_ctrl_28 - m_history_12)));
			t_sample mix_11022 = mix_11520;
			t_sample mix_11521 = (m_history_11 + (((t_sample)0.0019634941468452) * (mix_11022 - m_history_11)));
			t_sample mix_11021 = mix_11521;
			t_sample mix_11522 = (m_history_10 + (((t_sample)0.0019634941468452) * (mix_11021 - m_history_10)));
			t_sample mix_11023 = mix_11522;
			t_sample gen_3964 = mix_11023;
			t_sample history_3959_next_11020 = fixdenorm(mix_11022);
			t_sample history_3957_next_11028 = fixdenorm(mix_11021);
			t_sample history_3955_next_11026 = fixdenorm(mix_11023);
			t_sample mix_11523 = (m_history_9 + (((t_sample)0.0019634941468452) * (m_ctrl_29 - m_history_9)));
			t_sample mix_11035 = mix_11523;
			t_sample mix_11524 = (m_history_8 + (((t_sample)0.0019634941468452) * (mix_11035 - m_history_8)));
			t_sample mix_11034 = mix_11524;
			t_sample mix_11525 = (m_history_7 + (((t_sample)0.0019634941468452) * (mix_11034 - m_history_7)));
			t_sample mix_11036 = mix_11525;
			t_sample gen_3966 = mix_11036;
			t_sample history_3959_next_11033 = fixdenorm(mix_11035);
			t_sample history_3957_next_11041 = fixdenorm(mix_11034);
			t_sample history_3955_next_11039 = fixdenorm(mix_11036);
			t_sample rsub_3863 = (((int)1) - gen_3966);
			t_sample sub_11529 = (rsub_3863 - ((t_sample)0.0001));
			t_sample scale_11526 = ((safepow((sub_11529 * ((t_sample)1.000200040008)), ((int)1)) * ((int)-4)) + ((int)2));
			t_sample rdiv_3864 = safediv(((int)1), scale_11526);
			t_sample phasor_3866 = __m_phasor_57(rdiv_3864, samples_to_seconds);
			t_sample mul_3861 = (phasor_3866 * ((int)2));
			t_sample sub_3860 = (mul_3861 - ((int)1));
			t_sample cos_3859 = cos(sub_3860);
			t_sample sub_3858 = (cos_3859 - ((t_sample)0.5));
			t_sample mul_3857 = (sub_3858 * ((int)10));
			t_sample clamp_3856 = ((mul_3857 <= ((int)0)) ? ((int)0) : ((mul_3857 >= ((int)1)) ? ((int)1) : mul_3857));
			t_sample fold_3849 = fold(phasor_3866, ((int)0), ((int)1));
			double sample_index_58 = (fold_3849 * (loop3_dim - 1));
			int index_trunc_59 = fixnan(floor(sample_index_58));
			double index_fract_60 = (sample_index_58 - index_trunc_59);
			int index_trunc_61 = (index_trunc_59 - 1);
			int index_trunc_62 = (index_trunc_59 + 1);
			int index_trunc_63 = (index_trunc_59 + 2);
			bool index_ignore_64 = ((index_trunc_61 >= loop3_dim) || (index_trunc_61 < 0));
			bool index_ignore_65 = ((index_trunc_59 >= loop3_dim) || (index_trunc_59 < 0));
			bool index_ignore_66 = ((index_trunc_62 >= loop3_dim) || (index_trunc_62 < 0));
			bool index_ignore_67 = ((index_trunc_63 >= loop3_dim) || (index_trunc_63 < 0));
			// phase loop3 channel 1;
			double read_loop_68 = (index_ignore_64 ? 0 : m_loop_23.read(index_trunc_61, 0));
			double read_loop_69 = (index_ignore_65 ? 0 : m_loop_23.read(index_trunc_59, 0));
			double read_loop_70 = (index_ignore_66 ? 0 : m_loop_23.read(index_trunc_62, 0));
			double read_loop_71 = (index_ignore_67 ? 0 : m_loop_23.read(index_trunc_63, 0));
			double readinterp_72 = spline_interp(index_fract_60, read_loop_68, read_loop_69, read_loop_70, read_loop_71);
			t_sample sample_loop_3854 = readinterp_72;
			t_sample index_loop_3855 = sample_index_58;
			t_sample mul_3848 = (sample_loop_3854 * clamp_3856);
			t_sample mix_11530 = (in1 + (gen_3964 * (mul_3848 - in1)));
			t_sample mul_3825 = (mix_11530 * slide_3828);
			t_sample clamp_6186 = ((mul_3825 <= min_73) ? min_73 : ((mul_3825 >= ((int)1)) ? ((int)1) : mul_3825));
			int index_wrap_74 = ((switch_3816 < 0) ? ((loop3_dim - 1) + ((switch_3816 + 1) % loop3_dim)) : (switch_3816 % loop3_dim));
			m_loop_23.write((clamp_6186 + (m_loop_23.read(index_wrap_74, 0) * scale_11494)), index_wrap_74, 0);
			double sample_index_75 = (fold_3849 * (loop3_dim - 1));
			int index_trunc_76 = fixnan(floor(sample_index_75));
			double index_fract_77 = (sample_index_75 - index_trunc_76);
			int index_trunc_78 = (index_trunc_76 - 1);
			int index_trunc_79 = (index_trunc_76 + 1);
			int index_trunc_80 = (index_trunc_76 + 2);
			bool index_ignore_81 = ((index_trunc_78 >= loop3_dim) || (index_trunc_78 < 0));
			bool index_ignore_82 = ((index_trunc_76 >= loop3_dim) || (index_trunc_76 < 0));
			bool index_ignore_83 = ((index_trunc_79 >= loop3_dim) || (index_trunc_79 < 0));
			bool index_ignore_84 = ((index_trunc_80 >= loop3_dim) || (index_trunc_80 < 0));
			// phase loop3 channel 1;
			double read_loop_86 = ((chan_ignore_85 || index_ignore_81) ? 0 : m_loop_23.read(index_trunc_78, 1));
			double read_loop_87 = ((chan_ignore_85 || index_ignore_82) ? 0 : m_loop_23.read(index_trunc_76, 1));
			double read_loop_88 = ((chan_ignore_85 || index_ignore_83) ? 0 : m_loop_23.read(index_trunc_79, 1));
			double read_loop_89 = ((chan_ignore_85 || index_ignore_84) ? 0 : m_loop_23.read(index_trunc_80, 1));
			double readinterp_90 = spline_interp(index_fract_77, read_loop_86, read_loop_87, read_loop_88, read_loop_89);
			t_sample sample_loop_3852 = readinterp_90;
			t_sample index_loop_3853 = sample_index_75;
			t_sample mul_3847 = (sample_loop_3852 * clamp_3856);
			t_sample mix_11531 = (in2 + (gen_3964 * (mul_3847 - in2)));
			t_sample clamp_8372 = ((mix_11531 <= min_91) ? min_91 : ((mix_11531 >= ((int)1)) ? ((int)1) : mix_11531));
			t_sample mul_3822 = (clamp_8372 * slide_3828);
			t_sample clamp_7059 = ((mul_3822 <= min_92) ? min_92 : ((mul_3822 >= ((int)1)) ? ((int)1) : mul_3822));
			int index_wrap_94 = ((switch_3813 < 0) ? ((loop3_dim - 1) + ((switch_3813 + 1) % loop3_dim)) : (switch_3813 % loop3_dim));
			if ((!chan_ignore_93)) {
				m_loop_23.write((clamp_7059 + (m_loop_23.read(index_wrap_94, ((int)1)) * scale_11494)), index_wrap_94, ((int)1));
				
			};
			t_sample mix_11532 = (m_history_6 + (((t_sample)0.0019634941468452) * (m_ctrl_25 - m_history_6)));
			t_sample mix_11048 = mix_11532;
			t_sample mix_11533 = (m_history_5 + (((t_sample)0.0019634941468452) * (mix_11048 - m_history_5)));
			t_sample mix_11047 = mix_11533;
			t_sample mix_11534 = (m_history_4 + (((t_sample)0.0019634941468452) * (mix_11047 - m_history_4)));
			t_sample mix_11052 = mix_11534;
			t_sample gen_3968 = mix_11052;
			t_sample history_3959_next_11046 = fixdenorm(mix_11048);
			t_sample history_3957_next_11051 = fixdenorm(mix_11047);
			t_sample history_3955_next_11050 = fixdenorm(mix_11052);
			t_sample rsub_3886 = (((int)1) - gen_3968);
			t_sample sub_11538 = (rsub_3886 - ((t_sample)0.0001));
			t_sample scale_11535 = ((safepow((sub_11538 * ((t_sample)1.000200040008)), ((int)1)) * ((int)-4)) + ((int)2));
			t_sample rdiv_3887 = safediv(((int)1), scale_11535);
			t_sample phasor_3889 = __m_phasor_95(rdiv_3887, samples_to_seconds);
			t_sample mul_3884 = (phasor_3889 * ((int)2));
			t_sample sub_3883 = (mul_3884 - ((int)1));
			t_sample cos_3882 = cos(sub_3883);
			t_sample sub_3881 = (cos_3882 - ((t_sample)0.5));
			t_sample mul_3880 = (sub_3881 * ((int)10));
			t_sample clamp_3879 = ((mul_3880 <= ((int)0)) ? ((int)0) : ((mul_3880 >= ((int)1)) ? ((int)1) : mul_3880));
			t_sample fold_3872 = fold(phasor_3889, ((int)0), ((int)1));
			double sample_index_96 = (fold_3872 * (loop2_dim - 1));
			int index_trunc_97 = fixnan(floor(sample_index_96));
			double index_fract_98 = (sample_index_96 - index_trunc_97);
			int index_trunc_99 = (index_trunc_97 - 1);
			int index_trunc_100 = (index_trunc_97 + 1);
			int index_trunc_101 = (index_trunc_97 + 2);
			bool index_ignore_102 = ((index_trunc_99 >= loop2_dim) || (index_trunc_99 < 0));
			bool index_ignore_103 = ((index_trunc_97 >= loop2_dim) || (index_trunc_97 < 0));
			bool index_ignore_104 = ((index_trunc_100 >= loop2_dim) || (index_trunc_100 < 0));
			bool index_ignore_105 = ((index_trunc_101 >= loop2_dim) || (index_trunc_101 < 0));
			// phase loop2 channel 1;
			double read_loop_106 = (index_ignore_102 ? 0 : m_loop_27.read(index_trunc_99, 0));
			double read_loop_107 = (index_ignore_103 ? 0 : m_loop_27.read(index_trunc_97, 0));
			double read_loop_108 = (index_ignore_104 ? 0 : m_loop_27.read(index_trunc_100, 0));
			double read_loop_109 = (index_ignore_105 ? 0 : m_loop_27.read(index_trunc_101, 0));
			double readinterp_110 = spline_interp(index_fract_98, read_loop_106, read_loop_107, read_loop_108, read_loop_109);
			t_sample sample_loop_3877 = readinterp_110;
			t_sample index_loop_3878 = sample_index_96;
			t_sample mul_3871 = (sample_loop_3877 * clamp_3879);
			t_sample mix_11539 = (in1 + (gen_3964 * (mul_3871 - in1)));
			t_sample clamp_5170 = ((mix_11539 <= min_111) ? min_111 : ((mix_11539 >= ((int)1)) ? ((int)1) : mix_11539));
			t_sample mul_3826 = (clamp_5170 * slide_3829);
			t_sample clamp_5896 = ((mul_3826 <= min_112) ? min_112 : ((mul_3826 >= ((int)1)) ? ((int)1) : mul_3826));
			int index_wrap_113 = ((switch_3815 < 0) ? ((loop2_dim - 1) + ((switch_3815 + 1) % loop2_dim)) : (switch_3815 % loop2_dim));
			m_loop_27.write((clamp_5896 + (m_loop_27.read(index_wrap_113, 0) * scale_11494)), index_wrap_113, 0);
			double sample_index_114 = (fold_3872 * (loop2_dim - 1));
			int index_trunc_115 = fixnan(floor(sample_index_114));
			double index_fract_116 = (sample_index_114 - index_trunc_115);
			int index_trunc_117 = (index_trunc_115 - 1);
			int index_trunc_118 = (index_trunc_115 + 1);
			int index_trunc_119 = (index_trunc_115 + 2);
			bool index_ignore_120 = ((index_trunc_117 >= loop2_dim) || (index_trunc_117 < 0));
			bool index_ignore_121 = ((index_trunc_115 >= loop2_dim) || (index_trunc_115 < 0));
			bool index_ignore_122 = ((index_trunc_118 >= loop2_dim) || (index_trunc_118 < 0));
			bool index_ignore_123 = ((index_trunc_119 >= loop2_dim) || (index_trunc_119 < 0));
			// phase loop2 channel 1;
			double read_loop_125 = ((chan_ignore_124 || index_ignore_120) ? 0 : m_loop_27.read(index_trunc_117, 1));
			double read_loop_126 = ((chan_ignore_124 || index_ignore_121) ? 0 : m_loop_27.read(index_trunc_115, 1));
			double read_loop_127 = ((chan_ignore_124 || index_ignore_122) ? 0 : m_loop_27.read(index_trunc_118, 1));
			double read_loop_128 = ((chan_ignore_124 || index_ignore_123) ? 0 : m_loop_27.read(index_trunc_119, 1));
			double readinterp_129 = spline_interp(index_fract_116, read_loop_125, read_loop_126, read_loop_127, read_loop_128);
			t_sample sample_loop_3875 = readinterp_129;
			t_sample index_loop_3876 = sample_index_114;
			t_sample mul_3870 = (sample_loop_3875 * clamp_3879);
			t_sample mix_11540 = (in2 + (gen_3964 * (mul_3870 - in2)));
			t_sample clamp_8225 = ((mix_11540 <= min_130) ? min_130 : ((mix_11540 >= ((int)1)) ? ((int)1) : mix_11540));
			t_sample mul_3823 = (clamp_8225 * slide_3829);
			t_sample clamp_6768 = ((mul_3823 <= min_131) ? min_131 : ((mul_3823 >= ((int)1)) ? ((int)1) : mul_3823));
			int index_wrap_133 = ((switch_3814 < 0) ? ((loop2_dim - 1) + ((switch_3814 + 1) % loop2_dim)) : (switch_3814 % loop2_dim));
			if ((!chan_ignore_132)) {
				m_loop_27.write((clamp_6768 + (m_loop_27.read(index_wrap_133, ((int)1)) * scale_11494)), index_wrap_133, ((int)1));
				
			};
			t_sample mix_11541 = (m_history_3 + (((t_sample)0.0019634941468452) * (m_ctrl_35 - m_history_3)));
			t_sample mix_11061 = mix_11541;
			t_sample mix_11542 = (m_history_2 + (((t_sample)0.0019634941468452) * (mix_11061 - m_history_2)));
			t_sample mix_11060 = mix_11542;
			t_sample mix_11543 = (m_history_1 + (((t_sample)0.0019634941468452) * (mix_11060 - m_history_1)));
			t_sample mix_11065 = mix_11543;
			t_sample gen_3969 = mix_11065;
			t_sample history_3959_next_11059 = fixdenorm(mix_11061);
			t_sample history_3957_next_11064 = fixdenorm(mix_11060);
			t_sample history_3955_next_11063 = fixdenorm(mix_11065);
			t_sample rsub_3935 = (((int)1) - gen_3969);
			t_sample sub_11547 = (rsub_3935 - ((t_sample)0.0001));
			t_sample scale_11544 = ((safepow((sub_11547 * ((t_sample)1.000200040008)), ((int)1)) * ((int)-4)) + ((int)2));
			t_sample rdiv_3936 = safediv(((int)1), scale_11544);
			t_sample phasor_3938 = __m_phasor_134(rdiv_3936, samples_to_seconds);
			t_sample mul_3924 = (phasor_3938 * ((int)2));
			t_sample sub_3923 = (mul_3924 - ((int)1));
			t_sample cos_3922 = cos(sub_3923);
			t_sample sub_3921 = (cos_3922 - ((t_sample)0.5));
			t_sample mul_3920 = (sub_3921 * ((int)10));
			t_sample clamp_3919 = ((mul_3920 <= ((int)0)) ? ((int)0) : ((mul_3920 >= ((int)1)) ? ((int)1) : mul_3920));
			t_sample fold_3926 = fold(phasor_3938, ((int)0), ((int)1));
			double sample_index_135 = (fold_3926 * (loop1_dim - 1));
			int index_trunc_136 = fixnan(floor(sample_index_135));
			double index_fract_137 = (sample_index_135 - index_trunc_136);
			int index_trunc_138 = (index_trunc_136 - 1);
			int index_trunc_139 = (index_trunc_136 + 1);
			int index_trunc_140 = (index_trunc_136 + 2);
			bool index_ignore_141 = ((index_trunc_138 >= loop1_dim) || (index_trunc_138 < 0));
			bool index_ignore_142 = ((index_trunc_136 >= loop1_dim) || (index_trunc_136 < 0));
			bool index_ignore_143 = ((index_trunc_139 >= loop1_dim) || (index_trunc_139 < 0));
			bool index_ignore_144 = ((index_trunc_140 >= loop1_dim) || (index_trunc_140 < 0));
			// phase loop1 channel 1;
			double read_loop_146 = ((chan_ignore_145 || index_ignore_141) ? 0 : m_loop_26.read(index_trunc_138, 1));
			double read_loop_147 = ((chan_ignore_145 || index_ignore_142) ? 0 : m_loop_26.read(index_trunc_136, 1));
			double read_loop_148 = ((chan_ignore_145 || index_ignore_143) ? 0 : m_loop_26.read(index_trunc_139, 1));
			double read_loop_149 = ((chan_ignore_145 || index_ignore_144) ? 0 : m_loop_26.read(index_trunc_140, 1));
			double readinterp_150 = spline_interp(index_fract_137, read_loop_146, read_loop_147, read_loop_148, read_loop_149);
			t_sample sample_loop_3930 = readinterp_150;
			t_sample index_loop_3931 = sample_index_135;
			t_sample mul_3918 = (sample_loop_3930 * clamp_3919);
			t_sample mix_11548 = (in2 + (gen_3964 * (mul_3918 - in2)));
			t_sample clamp_7205 = ((mix_11548 <= min_151) ? min_151 : ((mix_11548 >= ((int)1)) ? ((int)1) : mix_11548));
			t_sample mul_3824 = (clamp_7205 * slide_3830);
			t_sample clamp_6477 = ((mul_3824 <= min_152) ? min_152 : ((mul_3824 >= ((int)1)) ? ((int)1) : mul_3824));
			int index_wrap_154 = ((switch_3817 < 0) ? ((loop1_dim - 1) + ((switch_3817 + 1) % loop1_dim)) : (switch_3817 % loop1_dim));
			if ((!chan_ignore_153)) {
				m_loop_26.write((clamp_6477 + (m_loop_26.read(index_wrap_154, ((int)1)) * scale_11494)), index_wrap_154, ((int)1));
				
			};
			t_sample mix_11549 = (mul_3918 + (((t_sample)0.5) * (mul_3870 - mul_3918)));
			t_sample mix_11550 = (mix_11549 + (((t_sample)0.66) * (mul_3847 - mix_11549)));
			t_sample mul_3820 = (mix_11550 * ((int)2));
			t_sample mix_11551 = (in2 + (gen_3970 * (mul_3820 - in2)));
			t_sample clamp_3840 = ((mix_11551 <= min_155) ? min_155 : ((mix_11551 >= ((int)1)) ? ((int)1) : mix_11551));
			t_sample out2 = clamp_3840;
			double sample_index_156 = (fold_3926 * (loop1_dim - 1));
			int index_trunc_157 = fixnan(floor(sample_index_156));
			double index_fract_158 = (sample_index_156 - index_trunc_157);
			int index_trunc_159 = (index_trunc_157 - 1);
			int index_trunc_160 = (index_trunc_157 + 1);
			int index_trunc_161 = (index_trunc_157 + 2);
			bool index_ignore_162 = ((index_trunc_159 >= loop1_dim) || (index_trunc_159 < 0));
			bool index_ignore_163 = ((index_trunc_157 >= loop1_dim) || (index_trunc_157 < 0));
			bool index_ignore_164 = ((index_trunc_160 >= loop1_dim) || (index_trunc_160 < 0));
			bool index_ignore_165 = ((index_trunc_161 >= loop1_dim) || (index_trunc_161 < 0));
			// phase loop1 channel 1;
			double read_loop_166 = (index_ignore_162 ? 0 : m_loop_26.read(index_trunc_159, 0));
			double read_loop_167 = (index_ignore_163 ? 0 : m_loop_26.read(index_trunc_157, 0));
			double read_loop_168 = (index_ignore_164 ? 0 : m_loop_26.read(index_trunc_160, 0));
			double read_loop_169 = (index_ignore_165 ? 0 : m_loop_26.read(index_trunc_161, 0));
			double readinterp_170 = spline_interp(index_fract_158, read_loop_166, read_loop_167, read_loop_168, read_loop_169);
			t_sample sample_loop_3932 = readinterp_170;
			t_sample index_loop_3933 = sample_index_156;
			t_sample mul_3917 = (sample_loop_3932 * clamp_3919);
			t_sample mix_11552 = (in1 + (gen_3964 * (mul_3917 - in1)));
			t_sample clamp_4880 = ((mix_11552 <= min_171) ? min_171 : ((mix_11552 >= ((int)1)) ? ((int)1) : mix_11552));
			t_sample mul_3827 = (clamp_4880 * slide_3830);
			t_sample clamp_5606 = ((mul_3827 <= min_172) ? min_172 : ((mul_3827 >= ((int)1)) ? ((int)1) : mul_3827));
			int index_wrap_173 = ((switch_3819 < 0) ? ((loop1_dim - 1) + ((switch_3819 + 1) % loop1_dim)) : (switch_3819 % loop1_dim));
			m_loop_26.write((clamp_5606 + (m_loop_26.read(index_wrap_173, 0) * scale_11494)), index_wrap_173, 0);
			t_sample mix_11553 = (mul_3917 + (((t_sample)0.5) * (mul_3871 - mul_3917)));
			t_sample mix_11554 = (mix_11553 + (((t_sample)0.66) * (mul_3848 - mix_11553)));
			t_sample mul_3821 = (mix_11554 * ((int)2));
			t_sample mix_11555 = (in1 + (gen_3970 * (mul_3821 - in1)));
			t_sample clamp_3841 = ((mix_11555 <= min_174) ? min_174 : ((mix_11555 >= ((int)1)) ? ((int)1) : mix_11555));
			t_sample out1 = clamp_3841;
			m_history_21 = history_3959_next_3961;
			m_history_19 = history_3955_next_3963;
			m_history_20 = history_3957_next_3962;
			m_history_18 = history_3959_next_10995;
			m_history_16 = history_3955_next_10999;
			m_history_17 = history_3957_next_10998;
			m_history_15 = history_3959_next_11008;
			m_history_13 = history_3955_next_11012;
			m_history_14 = history_3957_next_11013;
			m_history_12 = history_3959_next_11020;
			m_history_10 = history_3955_next_11026;
			m_history_11 = history_3957_next_11028;
			m_history_9 = history_3959_next_11033;
			m_history_7 = history_3955_next_11039;
			m_history_8 = history_3957_next_11041;
			m_history_6 = history_3959_next_11046;
			m_history_4 = history_3955_next_11050;
			m_history_5 = history_3957_next_11051;
			m_history_3 = history_3959_next_11059;
			m_history_1 = history_3955_next_11063;
			m_history_2 = history_3957_next_11064;
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
		m_gate_22 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_loop3(void * _value) {
		m_loop_23.setbuffer(_value);
	};
	inline void set_sw2(t_param _value) {
		m_sw_24 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_ctrl3(t_param _value) {
		m_ctrl_25 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_loop1(void * _value) {
		m_loop_26.setbuffer(_value);
	};
	inline void set_loop2(void * _value) {
		m_loop_27.setbuffer(_value);
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
	inline void set_ctrl2(t_param _value) {
		m_ctrl_31 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_button(t_param _value) {
		m_button_32 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw1(t_param _value) {
		m_sw_33 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_ctrl4(t_param _value) {
		m_ctrl_34 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_ctrl5(t_param _value) {
		m_ctrl_35 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
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
		case 0: *value = self->m_button_32; break;
		case 1: *value = self->m_ctrl_30; break;
		case 2: *value = self->m_ctrl_31; break;
		case 3: *value = self->m_ctrl_25; break;
		case 4: *value = self->m_ctrl_34; break;
		case 5: *value = self->m_ctrl_35; break;
		case 6: *value = self->m_ctrl_29; break;
		case 7: *value = self->m_ctrl_28; break;
		case 8: *value = self->m_gate_22; break;
		
		
		
		case 12: *value = self->m_sw_33; break;
		case 13: *value = self->m_sw_24; break;
		
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
	// initialize parameter 0 ("m_button_32")
	pi = self->__commonstate.params + 0;
	pi->name = "button";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_button_32;
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
	// initialize parameter 2 ("m_ctrl_31")
	pi = self->__commonstate.params + 2;
	pi->name = "ctrl2";
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
	// initialize parameter 3 ("m_ctrl_25")
	pi = self->__commonstate.params + 3;
	pi->name = "ctrl3";
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
	// initialize parameter 4 ("m_ctrl_34")
	pi = self->__commonstate.params + 4;
	pi->name = "ctrl4";
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
	// initialize parameter 5 ("m_ctrl_35")
	pi = self->__commonstate.params + 5;
	pi->name = "ctrl5";
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
	// initialize parameter 8 ("m_gate_22")
	pi = self->__commonstate.params + 8;
	pi->name = "gate";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_gate_22;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 9 ("m_loop_26")
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
	// initialize parameter 10 ("m_loop_27")
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
	// initialize parameter 11 ("m_loop_23")
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
	// initialize parameter 12 ("m_sw_33")
	pi = self->__commonstate.params + 12;
	pi->name = "sw1";
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
	// initialize parameter 13 ("m_sw_24")
	pi = self->__commonstate.params + 13;
	pi->name = "sw2";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_24;
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
