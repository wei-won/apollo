/******************************************************************************
 * Copyright 2017 The Apollo Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/

/**
 * @file
 * @brief Define move sequence predictor
 */

#ifndef MODULES_PREDICTION_PREDICTOR_MOVE_SEQUENCE_MOVE_SEQUENCE_PREDICTOR_H_
#define MODULES_PREDICTION_PREDICTOR_MOVE_SEQUENCE_MOVE_SEQUENCE_PREDICTOR_H_

#include <array>

#include "modules/prediction/predictor/predictor.h"

namespace apollo {
namespace prediction {

class MoveSequencePredictor : public Predictor {
 public:
  /**
   * @brief Constructor
   */
  MoveSequencePredictor() = default;

  /**
   * @brief Destructor
   */
  virtual ~MoveSequencePredictor() = default;

  /**
   * @brief Make prediction
   * @param Obstacle pointer
   */
  void Predict(Obstacle* obstacle) override;

 private:
  double Cost(const double t, const std::array<double, 6>& coeffs,
              const double alpha);

  double Weight(const double t);
};

}  // namespace prediction
}  // namespace apollo

#endif  // MODULES_PREDICTION_PREDICTOR_MOVE_SEQUENCE_MOVE_SEQUENCE_PREDICTOR_H_
