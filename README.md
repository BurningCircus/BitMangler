# BitMangler

A 32-bit, stereo VST plugin implemented using the JUCE interface.

The BitMangler is composed of a small collection of DSP algorithms which intentionally introduce distortion into the signal. These processes are wrapped in gain staging controls and filtering to tame noisy output. As with many distortion plugins, the gain staging can require extreme settings to maintain the perception of unity gain. The intent of the BitMangler is to be put to creative use shaping low fidelity sounds.

Distortion is a fundamental tone-shaping technique in modern music, and the BitMangler is a new twist on digital distortion implementations. Simple and efficient waveshaping algorithms produce clipping distortion in a controlled environment, while an original algorithm introduces error by duplicating and deleting samples, which produces an unusual tambre of digital distortion with a well-controlled smooth onset and good intelligibility. Continuously sweepable high- and low-pass filters provide flexibility for low fidelity tone shaping or noise control.

BitMangler.h, BitMangler.cpp: The DSP source code.

PluginProcessor.h, PluginProcessor.cpp: The JUCE wrapper for the DSP source.

PluginEditor.h, PluginEditor.cpp: The JUCE wrapper for GUI elements.
