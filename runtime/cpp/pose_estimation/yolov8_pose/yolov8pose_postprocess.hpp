/**
* Copyright (c) 2021-2022 Hailo Technologies Ltd. All rights reserved.
* Distributed under the LGPL license (https://www.gnu.org/licenses/old-licenses/lgpl-2.1.txt)
**/
#pragma once
#include "common/hailo_objects.hpp"
#include "common/hailo_common.hpp"

#include <xtensor/views/xview.hpp>
#include <xtensor/misc/xsort.hpp>

struct KeyPt {
    float xs;
    float ys;
    float joints_scores;
};

struct PairPairs {
    std::pair<float, float> pt1;
    std::pair<float, float> pt2;
    float s1;
    float s2;
};

struct Triple {
    std::vector<HailoTensorPtr> boxes;
    xt::xarray<float> scores;
    std::vector<HailoTensorPtr> keypoints;
};

struct Decodings {
    HailoDetection detection_box;
    std::pair<xt::xarray<float>, xt::xarray<float>> keypoints;
    std::vector<PairPairs> joint_pairs;
};


__BEGIN_DECLS
std::pair<std::vector<KeyPt>, std::vector<PairPairs>> filter(HailoROIPtr roi);
__END_DECLS
