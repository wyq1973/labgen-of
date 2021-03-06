/**
 * Copyright - Benjamin Laugraud <blaugraud@ulg.ac.be> - 2017
 * http://www.montefiore.ulg.ac.be/~blaugraud
 * http://www.telecom.ulg.ac.be/labgen
 *
 * This file is part of LaBGen-OF.
 *
 * LaBGen-OF is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * LaBGen-OF is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with LaBGen-OF.  If not, see <http://www.gnu.org/licenses/>.
 */
#include <labgen-of/optical_flow/DISFlow.hpp>

using namespace cv;
using namespace cv::optflow;
using namespace ns_labgen_of;

/* ========================================================================== *
 * DISFlow                                                                    *
 * ========================================================================== */

DISFlow::DISFlow() : dis_flow(createOptFlow_DIS()) {}

/******************************************************************************/

void DISFlow::compute_flow(
  const Mat& previous_frame,
  const Mat& current_frame,
  Mat& optical_flow
) {
  dis_flow->calc(previous_frame, current_frame, optical_flow);
}

/******************************************************************************/

int DISFlow::get_frame_type() {
  return CV_8UC1;
}
