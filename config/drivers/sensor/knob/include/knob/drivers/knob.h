/*
 * Copyright (c) 2022-2023 XiNGRZ
 * SPDX-License-Identifier: MIT
 */

#ifndef KNOB_INCLUDE_DRIVERS_KNOB_H_
#define KNOB_INCLUDE_DRIVERS_KNOB_H_

#include <stdbool.h>
#include <device.h>

/**
 * @file
 * @brief Extended public API for knob
 */

#ifdef __cplusplus
extern "C" {
#endif

enum knob_mode {
	KNOB_DISABLE = 0,
	KNOB_INERTIA,
	KNOB_ENCODER,
	KNOB_SPRING,
	KNOB_DAMPED,
	KNOB_SPIN,
};

void knob_set_mode(const struct device *dev, enum knob_mode mode);

void knob_set_enable(const struct device *dev, bool enable);

void knob_set_encoder_report(const struct device *dev, bool report);

void knob_set_position_limit(const struct device *dev, float min, float max);

float knob_get_position(const struct device *dev);

float knob_get_velocity(const struct device *dev);

int knob_get_encoder_position(const struct device *dev);

void knob_calibrate_set(const struct device *dev, float zero_offset, int direction);
void knob_calibrate_get(const struct device *dev, float *zero_offset, int *direction);

bool knob_calibrate_auto(const struct device *dev);

#ifdef __cplusplus
}
#endif

#endif /* KNOB_INCLUDE_DRIVERS_KNOB_H_ */
