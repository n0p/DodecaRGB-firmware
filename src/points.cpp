#include "points.h"
using namespace std;

float calculatePointDistance(LED_Point p1, LED_Point p2) {
    float dx = p1.x - p2.x;
    float dy = p1.y - p2.y;
    float dz = p1.z - p2.z;
    return sqrt(dx*dx + dy*dy + dz*dz);
};

bool compare_distance(distance_map a, distance_map b) {
    return a.distance < b.distance;
}

void LED_Point::find_nearest_leds() {
    std::vector<distance_map> candidate_points;
    for (int i=0; i<NUM_LEDS; i++) {
        distance_map d;
        d.led_number = i;
        d.distance = calculatePointDistance(points[this->index], points[i]);
        candidate_points.push_back(d);
    }
    // sort the candidate points by distance
    std::sort(candidate_points.begin(), candidate_points.end(), compare_distance);
    candidate_points.resize(MAX_LED_NEIGHBORS);
    
    for (int i=0; i<candidate_points.size(); i++) {
        this->neighbors[i] = candidate_points[i];
    } 
    
}

LED_Point points[] = {
/*
This file was generated 
from a Processing sketch which outputs all of the points.
--------------
format: index, x, y, z, sideNumber
*/
LED_Point(0, 0.0, 0.0, 267.0, 1, 0),
LED_Point(1, 47.022804, -64.72137, 267.0, 2, 0),
LED_Point(2, -1.66893E-5, -80.0, 267.0, 3, 0),
LED_Point(3, -47.022835, -64.72135, 267.0, 4, 0),
LED_Point(4, -76.084526, -24.72134, 267.0, 5, 0),
LED_Point(5, -76.08451, 24.721378, 267.0, 6, 0),
LED_Point(6, -47.0228, 64.721375, 267.0, 7, 0),
LED_Point(7, 2.3683124E-5, 80.0, 267.0, 8, 0),
LED_Point(8, 47.022823, 64.72136, 267.0, 9, 0),
LED_Point(9, 76.084526, 24.721352, 267.0, 10, 0),
LED_Point(10, 76.08451, -24.721386, 267.0, 11, 0),
LED_Point(11, 97.23558, -105.09635, 267.0, 12, 0),
LED_Point(12, 40.172184, -123.63736, 267.0, 13, 0),
LED_Point(13, -16.891212, -142.17838, 267.0, 14, 0),
LED_Point(14, -69.90512, -124.95308, 267.0, 15, 0),
LED_Point(15, -105.172226, -76.412056, 267.0, 16, 0),
LED_Point(16, -140.43933, -27.871029, 267.0, 17, 0),
LED_Point(17, -140.43932, 27.871082, 267.0, 18, 0),
LED_Point(18, -105.172195, 76.412094, 267.0, 19, 0),
LED_Point(19, -69.905075, 124.95311, 267.0, 20, 0),
LED_Point(20, -16.891155, 142.17838, 267.0, 21, 0),
LED_Point(21, 40.172234, 123.637344, 267.0, 22, 0),
LED_Point(22, 97.23563, 105.09631, 267.0, 23, 0),
LED_Point(23, 130.00002, 59.99997, 267.0, 24, 0),
LED_Point(24, 130.0, -2.8670349E-5, 267.0, 25, 0),
LED_Point(25, 129.99998, -60.00003, 267.0, 26, 0),
LED_Point(26, 73.77447, -227.05446, 119.551636, 1, 1),
LED_Point(27, 141.83446, -227.07884, 77.50598, 2, 1),
LED_Point(28, 107.81334, -251.81529, 51.520325, 3, 1),
LED_Point(29, 60.790516, -267.09393, 51.520325, 4, 1),
LED_Point(30, 18.727118, -267.07886, 77.50598, 5, 1),
LED_Point(31, -2.3100603, -251.77582, 119.551636, 6, 1),
LED_Point(32, 5.714468, -227.03006, 161.59729, 7, 1),
LED_Point(33, 39.735607, -202.29362, 187.58295, 8, 1),
LED_Point(34, 86.75841, -187.01498, 187.58295, 9, 1),
LED_Point(35, 128.82181, -187.03006, 161.59729, 10, 1),
LED_Point(36, 149.859, -202.3331, 119.551636, 11, 1),
LED_Point(37, 202.28436, -218.2105, 57.045715, 12, 1),
LED_Point(38, 160.99886, -248.22879, 25.511475, 13, 1),
LED_Point(39, 119.71335, -278.2471, -6.022766, 14, 1),
LED_Point(40, 66.69943, -295.47235, -6.022766, 15, 1),
LED_Point(41, 15.654436, -295.45407, 25.511475, 16, 1),
LED_Point(42, -35.39056, -295.4358, 57.045715, 17, 1),
LED_Point(43, -59.108044, -278.183, 104.44824, 18, 1),
LED_Point(44, -49.37008, -248.15341, 155.47174, 19, 1),
LED_Point(45, -39.632114, -218.12381, 206.49524, 20, 1),
LED_Point(46, -1.2764187, -190.23575, 235.79169, 21, 1),
LED_Point(47, 55.78698, -171.69472, 235.79169, 22, 1),
LED_Point(48, 112.85037, -153.15369, 235.79169, 23, 1),
LED_Point(49, 160.273, -153.17068, 206.4953, 24, 1),
LED_Point(50, 185.80214, -171.7413, 155.4718, 25, 1),
LED_Point(51, 211.33128, -190.31192, 104.4483, 26, 1),
LED_Point(52, 238.73918, 3.8895552E-5, 119.551636, 1, 2),
LED_Point(53, 217.68427, 64.72139, 161.59729, 2, 2),
LED_Point(54, 238.73917, 80.00004, 119.551636, 3, 2),
LED_Point(55, 259.79407, 64.721405, 77.50598, 4, 2),
LED_Point(56, 272.8067, 24.72141, 51.520325, 5, 2),
LED_Point(57, 272.80673, -24.72131, 51.520325, 6, 2),
LED_Point(58, 259.7941, -64.72132, 77.50598, 7, 2),
LED_Point(59, 238.7392, -79.99996, 119.551636, 8, 2),
LED_Point(60, 217.68431, -64.72134, 161.59729, 9, 2),
LED_Point(61, 204.67165, -24.721344, 187.58295, 10, 2),
LED_Point(62, 204.67165, 24.721394, 187.58295, 11, 2),
LED_Point(63, 195.20103, 105.09635, 206.49524, 12, 2),
LED_Point(64, 220.75168, 123.63738, 155.4718, 13, 2),
LED_Point(65, 246.30232, 142.1784, 104.448364, 14, 2),
LED_Point(66, 270.03983, 124.95314, 57.045715, 15, 2),
LED_Point(67, 285.831, 76.41213, 25.511475, 16, 2),
LED_Point(68, 301.62216, 27.87112, -6.022766, 17, 2),
LED_Point(69, 301.6222, -27.87099, -6.022766, 18, 2),
LED_Point(70, 285.83102, -76.41202, 25.511475, 19, 2),
LED_Point(71, 270.03986, -124.95305, 57.045715, 20, 2),
LED_Point(72, 246.3024, -142.17833, 104.44824, 21, 2),
LED_Point(73, 220.75174, -123.63732, 155.47174, 22, 2),
LED_Point(74, 195.20108, -105.09631, 206.49524, 23, 2),
LED_Point(75, 180.53052, -59.999985, 235.79169, 24, 2),
LED_Point(76, 180.5305, 1.7199976E-5, 235.79169, 25, 2),
LED_Point(77, 180.53049, 60.000015, 235.79169, 26, 2),
LED_Point(78, 73.77442, 227.05447, 119.551636, 1, 3),
LED_Point(79, 5.714429, 227.03006, 161.59729, 2, 3),
LED_Point(80, -2.3101146, 251.77582, 119.551636, 3, 3),
LED_Point(81, 18.727049, 267.07886, 77.50598, 4, 3),
LED_Point(82, 60.79044, 267.09396, 51.520325, 5, 3),
LED_Point(83, 107.81327, 251.81532, 51.520325, 6, 3),
LED_Point(84, 141.83441, 227.07889, 77.50598, 7, 3),
LED_Point(85, 149.85896, 202.33313, 119.551636, 8, 3),
LED_Point(86, 128.8218, 187.03009, 161.59729, 9, 3),
LED_Point(87, 86.75841, 187.015, 187.58295, 10, 3),
LED_Point(88, 39.73556, 202.29364, 187.58295, 11, 3),
LED_Point(89, -39.632153, 218.12378, 206.4953, 12, 3),
LED_Point(90, -49.370136, 248.15338, 155.4718, 13, 3),
LED_Point(91, -59.10812, 278.18298, 104.4483, 14, 3),
LED_Point(92, -35.39064, 295.43576, 57.045715, 15, 3),
LED_Point(93, 15.654351, 295.45407, 25.511475, 16, 3),
LED_Point(94, 66.69934, 295.47238, -6.022766, 17, 3),
LED_Point(95, 119.71326, 278.24713, -6.022766, 18, 3),
LED_Point(96, 160.99878, 248.22885, 25.511475, 19, 3),
LED_Point(97, 202.2843, 218.21056, 57.045715, 20, 3),
LED_Point(98, 211.33125, 190.31198, 104.4483, 21, 3),
LED_Point(99, 185.80212, 171.74135, 155.4718, 22, 3),
LED_Point(100, 160.273, 153.17072, 206.4953, 23, 3),
LED_Point(101, 112.85037, 153.15372, 235.79169, 24, 3),
LED_Point(102, 55.78697, 171.69472, 235.79169, 25, 3),
LED_Point(103, -1.2764308, 190.23572, 235.79169, 26, 3),
LED_Point(104, -193.14409, 140.32733, 119.551636, 1, 4),
LED_Point(105, -214.15256, 75.59089, 161.59729, 2, 4),
LED_Point(106, -240.16689, 75.60596, 119.551636, 3, 4),
LED_Point(107, -248.22011, 100.34239, 77.50598, 4, 4),
LED_Point(108, -235.23616, 140.35172, 51.520325, 5, 4),
LED_Point(109, -206.17447, 180.35173, 51.520325, 6, 4),
LED_Point(110, -172.13562, 205.06377, 77.50598, 7, 4),
LED_Point(111, -146.12129, 205.0487, 119.551636, 8, 4),
LED_Point(112, -138.06807, 180.31229, 161.59729, 9, 4),
LED_Point(113, -151.05202, 140.30296, 187.58295, 10, 4),
LED_Point(114, -180.11372, 100.30293, 187.58295, 11, 4),
LED_Point(115, -219.69502, 29.711536, 206.49524, 12, 4),
LED_Point(116, -251.26408, 29.72982, 155.4718, 13, 4),
LED_Point(117, -282.83316, 29.748104, 104.448364, 14, 4),
LED_Point(118, -291.9124, 57.636177, 57.045715, 15, 4),
LED_Point(119, -276.15607, 106.18851, 25.511475, 16, 4),
LED_Point(120, -260.39972, 154.74083, -6.022766, 17, 4),
LED_Point(121, -227.63533, 199.83716, -6.022766, 18, 4),
LED_Point(122, -186.32831, 229.82587, 25.511475, 19, 4),
LED_Point(123, -145.02129, 259.81454, 57.045715, 20, 4),
LED_Point(124, -115.69253, 259.79758, 104.44824, 21, 4),
LED_Point(125, -105.91974, 229.77931, 155.47174, 22, 4),
LED_Point(126, -96.14695, 199.76102, 206.49524, 23, 4),
LED_Point(127, -110.78516, 154.65417, 235.79169, 24, 4),
LED_Point(128, -146.05226, 106.113144, 235.79169, 25, 4),
LED_Point(129, -181.31937, 57.572113, 235.79169, 26, 4),
LED_Point(130, -193.14401, -140.32742, 119.551636, 1, 5),
LED_Point(131, -138.06798, -180.31233, 161.59729, 2, 5),
LED_Point(132, -146.12117, -205.04877, 119.551636, 3, 5),
LED_Point(133, -172.13548, -205.06386, 77.50598, 4, 5),
LED_Point(134, -206.17436, -180.35182, 51.520325, 5, 5),
LED_Point(135, -235.23607, -140.35184, 51.520325, 6, 5),
LED_Point(136, -248.22006, -100.342514, 77.50598, 7, 5),
LED_Point(137, -240.16685, -75.60608, 119.551636, 8, 5),
LED_Point(138, -214.15254, -75.59099, 161.59729, 9, 5),
LED_Point(139, -180.11368, -100.30301, 187.58295, 10, 5),
LED_Point(140, -151.05196, -140.30302, 187.58295, 11, 5),
LED_Point(141, -96.146835, -199.76103, 206.4953, 12, 5),
LED_Point(142, -105.91959, -229.77934, 155.4718, 13, 5),
LED_Point(143, -115.69235, -259.79767, 104.4483, 14, 5),
LED_Point(144, -145.02113, -259.81467, 57.045715, 15, 5),
LED_Point(145, -186.32816, -229.82597, 25.511475, 16, 5),
LED_Point(146, -227.63518, -199.8373, -6.022766, 17, 5),
LED_Point(147, -260.3996, -154.74098, -6.022766, 18, 5),
LED_Point(148, -276.156, -106.18866, 25.511475, 19, 5),
LED_Point(149, -291.9124, -57.636337, 57.045715, 20, 5),
LED_Point(150, -282.83316, -29.74826, 104.4483, 21, 5),
LED_Point(151, -251.2641, -29.72995, 155.4718, 22, 5),
LED_Point(152, -219.69505, -29.71164, 206.4953, 23, 5),
LED_Point(153, -181.31937, -57.57219, 235.79169, 24, 5),
LED_Point(154, -146.05223, -106.1132, 235.79169, 25, 5),
LED_Point(155, -110.785095, -154.6542, 235.79169, 26, 5),
LED_Point(156, -238.73917, -1.5842912E-4, -119.551636, 1, 6),
LED_Point(157, -204.6716, -24.721504, -187.58289, 2, 6),
LED_Point(158, -204.67163, 24.721214, -187.58289, 3, 6),
LED_Point(159, -217.68431, 64.721214, -161.59729, 4, 6),
LED_Point(160, -238.73921, 79.99985, -119.551636, 5, 6),
LED_Point(161, -259.7941, 64.72119, -77.50598, 6, 6),
LED_Point(162, -272.80673, 24.721176, -51.520386, 7, 6),
LED_Point(163, -272.8067, -24.721542, -51.520386, 8, 6),
LED_Point(164, -259.79404, -64.72151, -77.50598, 9, 6),
LED_Point(165, -238.73912, -80.00015, -119.551636, 10, 6),
LED_Point(166, -217.68422, -64.7215, -161.59729, 11, 6),
LED_Point(167, -180.53043, -60.000137, -235.79175, 12, 6),
LED_Point(168, -180.53046, -1.351833E-4, -235.79175, 13, 6),
LED_Point(169, -180.53049, 59.999863, -235.79175, 14, 6),
LED_Point(170, -195.2011, 105.0962, -206.49524, 15, 6),
LED_Point(171, -220.75177, 123.63721, -155.4718, 16, 6),
LED_Point(172, -246.30244, 142.17822, -104.448364, 17, 6),
LED_Point(173, -270.0399, 124.952934, -57.045776, 18, 6),
LED_Point(174, -285.83102, 76.41191, -25.511475, 19, 6),
LED_Point(175, -301.62216, 27.870884, 6.022766, 20, 6),
LED_Point(176, -301.62213, -27.871235, 6.022766, 21, 6),
LED_Point(177, -285.83093, -76.41225, -25.511475, 22, 6),
LED_Point(178, -270.03973, -124.95326, -57.045654, 23, 6),
LED_Point(179, -246.30226, -142.17853, -104.448364, 24, 6),
LED_Point(180, -220.75162, -123.6375, -155.4718, 25, 6),
LED_Point(181, -195.20097, -105.096466, -206.49524, 26, 6),
LED_Point(182, -73.77463, -227.05438, -119.551636, 1, 7),
LED_Point(183, -39.735744, -202.29356, -187.58289, 2, 7),
LED_Point(184, -86.75855, -187.0149, -187.58289, 3, 7),
LED_Point(185, -128.82195, -187.02994, -161.59729, 4, 7),
LED_Point(186, -149.85915, -202.33296, -119.551636, 5, 7),
LED_Point(187, -141.83461, -227.07874, -77.50598, 6, 7),
LED_Point(188, -107.81351, -251.8152, -51.520386, 7, 7),
LED_Point(189, -60.790695, -267.09387, -51.520386, 8, 7),
LED_Point(190, -18.72732, -267.07883, -77.50598, 9, 7),
LED_Point(191, 2.309874, -251.7758, -119.551636, 10, 7),
LED_Point(192, -5.714639, -227.03003, -161.59729, 11, 7),
LED_Point(193, 1.2762781, -190.2357, -235.79175, 12, 7),
LED_Point(194, -55.7871, -171.69464, -235.79175, 13, 7),
LED_Point(195, -112.85048, -153.15358, -235.79175, 14, 7),
LED_Point(196, -160.2731, -153.17053, -206.49524, 15, 7),
LED_Point(197, -185.80226, -171.74115, -155.4718, 16, 7),
LED_Point(198, -211.33142, -190.31177, -104.448364, 17, 7),
LED_Point(199, -202.28453, -218.21034, -57.045776, 18, 7),
LED_Point(200, -160.99904, -248.22867, -25.511475, 19, 7),
LED_Point(201, -119.713554, -278.247, 6.022766, 20, 7),
LED_Point(202, -66.699646, -295.4723, 6.022766, 21, 7),
LED_Point(203, -15.654649, -295.45404, -25.511475, 22, 7),
LED_Point(204, 35.39035, -295.4358, -57.045654, 23, 7),
LED_Point(205, 59.10785, -278.18304, -104.448364, 24, 7),
LED_Point(206, 49.369904, -248.15341, -155.4718, 25, 7),
LED_Point(207, 39.631958, -218.1238, -206.49524, 26, 7),
LED_Point(208, 193.14401, -140.32741, -119.551636, 1, 8),
LED_Point(209, 180.11365, -100.30299, -187.58289, 2, 8),
LED_Point(210, 151.05194, -140.303, -187.58289, 3, 8),
LED_Point(211, 138.06796, -180.31232, -161.59729, 4, 8),
LED_Point(212, 146.12117, -205.04877, -119.551636, 5, 8),
LED_Point(213, 172.13551, -205.06386, -77.50598, 6, 8),
LED_Point(214, 206.17438, -180.35182, -51.520386, 7, 8),
LED_Point(215, 235.23608, -140.35182, -51.520386, 8, 8),
LED_Point(216, 248.22005, -100.342514, -77.50598, 9, 8),
LED_Point(217, 240.16685, -75.60605, -119.551636, 10, 8),
LED_Point(218, 214.15251, -75.590965, -161.59729, 11, 8),
LED_Point(219, 181.31932, -57.57216, -235.79175, 12, 8),
LED_Point(220, 146.0522, -106.113174, -235.79175, 13, 8),
LED_Point(221, 110.78507, -154.65419, -235.79175, 14, 8),
LED_Point(222, 96.146835, -199.76103, -206.49524, 15, 8),
LED_Point(223, 105.91961, -229.77934, -155.4718, 16, 8),
LED_Point(224, 115.69238, -259.79767, -104.448364, 17, 8),
LED_Point(225, 145.02113, -259.81467, -57.045776, 18, 8),
LED_Point(226, 186.32817, -229.82597, -25.511475, 19, 8),
LED_Point(227, 227.63521, -199.8373, 6.022766, 20, 8),
LED_Point(228, 260.39963, -154.74098, 6.022766, 21, 8),
LED_Point(229, 276.156, -106.188644, -25.511475, 22, 8),
LED_Point(230, 291.91238, -57.636314, -57.045654, 23, 8),
LED_Point(231, 282.83316, -29.74823, -104.448364, 24, 8),
LED_Point(232, 251.26408, -29.72992, -155.4718, 25, 8),
LED_Point(233, 219.69502, -29.711609, -206.49524, 26, 8),
LED_Point(234, 193.14401, 140.32742, -119.551636, 1, 9),
LED_Point(235, 151.05194, 140.30302, -187.58289, 2, 9),
LED_Point(236, 180.11365, 100.303024, -187.58289, 3, 9),
LED_Point(237, 214.15251, 75.59099, -161.59729, 4, 9),
LED_Point(238, 240.16685, 75.606064, -119.551636, 5, 9),
LED_Point(239, 248.22005, 100.342514, -77.50598, 6, 9),
LED_Point(240, 235.23608, 140.35184, -51.520386, 7, 9),
LED_Point(241, 206.17438, 180.35182, -51.520386, 8, 9),
LED_Point(242, 172.13551, 205.06386, -77.50598, 9, 9),
LED_Point(243, 146.12117, 205.04878, -119.551636, 10, 9),
LED_Point(244, 138.06798, 180.31233, -161.59729, 11, 9),
LED_Point(245, 110.78506, 154.65422, -235.79175, 12, 9),
LED_Point(246, 146.05219, 106.113205, -235.79175, 13, 9),
LED_Point(247, 181.31932, 57.57219, -235.79175, 14, 9),
LED_Point(248, 219.69502, 29.71164, -206.49524, 15, 9),
LED_Point(249, 251.26408, 29.729942, -155.4718, 16, 9),
LED_Point(250, 282.83316, 29.748245, -104.448364, 17, 9),
LED_Point(251, 291.91238, 57.636307, -57.045776, 18, 9),
LED_Point(252, 276.156, 106.18863, -25.511475, 19, 9),
LED_Point(253, 260.39963, 154.74095, 6.022766, 20, 9),
LED_Point(254, 227.63522, 199.8373, 6.022766, 21, 9),
LED_Point(255, 186.32819, 229.82597, -25.511475, 22, 9),
LED_Point(256, 145.02115, 259.81467, -57.045654, 23, 9),
LED_Point(257, 115.69238, 259.79767, -104.448364, 24, 9),
LED_Point(258, 105.91961, 229.77934, -155.4718, 25, 9),
LED_Point(259, 96.146835, 199.76105, -206.49524, 26, 9),
LED_Point(260, -73.77464, 227.05437, -119.551636, 1, 10),
LED_Point(261, -107.81351, 251.81519, -51.520386, 2, 10),
LED_Point(262, -141.83463, 227.07872, -77.50598, 3, 10),
LED_Point(263, -149.85915, 202.33295, -119.551636, 4, 10),
LED_Point(264, -128.82196, 187.02992, -161.59729, 5, 10),
LED_Point(265, -86.75858, 187.01488, -187.58289, 6, 10),
LED_Point(266, -39.73577, 202.29355, -187.58289, 7, 10),
LED_Point(267, -5.7146544, 227.03001, -161.59729, 8, 10),
LED_Point(268, 2.3098588, 251.77579, -119.551636, 9, 10),
LED_Point(269, -18.727312, 267.0788, -77.50598, 10, 10),
LED_Point(270, -60.79071, 267.09384, -51.520386, 11, 10),
LED_Point(271, -119.71353, 278.24698, 6.022766, 12, 10),
LED_Point(272, -160.99902, 248.22865, -25.511475, 13, 10),
LED_Point(273, -202.28452, 218.21033, -57.045654, 14, 10),
LED_Point(274, -211.3314, 190.31174, -104.448364, 15, 10),
LED_Point(275, -185.80226, 171.74113, -155.4718, 16, 10),
LED_Point(276, -160.27312, 153.17053, -206.49524, 17, 10),
LED_Point(277, -112.850525, 153.15356, -235.79175, 18, 10),
LED_Point(278, -55.787155, 171.69463, -235.79175, 19, 10),
LED_Point(279, 1.2762169, 190.23569, -235.79175, 20, 10),
LED_Point(280, 39.631916, 218.12378, -206.49524, 21, 10),
LED_Point(281, 49.369873, 248.1534, -155.4718, 22, 10),
LED_Point(282, 59.10783, 278.183, -104.448364, 23, 10),
LED_Point(283, 35.390343, 295.4358, -57.045776, 24, 10),
LED_Point(284, -15.654647, 295.45404, -25.511475, 25, 10),
LED_Point(285, -66.69963, 295.4723, 6.022766, 26, 10),
LED_Point(286, 0.0, 2.3341881E-5, -267.0, 1, 11),
LED_Point(287, -47.02282, -64.72134, -267.0, 2, 11),
LED_Point(288, 0.0, -79.99998, -267.0, 3, 11),
LED_Point(289, 47.02282, -64.72134, -267.0, 4, 11),
LED_Point(290, 76.084526, -24.721334, -267.0, 5, 11),
LED_Point(291, 76.08452, 24.721386, -267.0, 6, 11),
LED_Point(292, 47.022816, 64.72139, -267.0, 7, 11),
LED_Point(293, -6.9938224E-6, 80.00002, -267.0, 8, 11),
LED_Point(294, -47.02281, 64.72139, -267.0, 9, 11),
LED_Point(295, -76.08452, 24.72139, -267.0, 10, 11),
LED_Point(296, -76.08452, -24.721348, -267.0, 11, 11),
LED_Point(297, -97.2356, -105.09631, -267.0, 12, 11),
LED_Point(298, -40.17221, -123.63733, -267.0, 13, 11),
LED_Point(299, 16.891182, -142.17834, -267.0, 14, 11),
LED_Point(300, 69.9051, -124.95308, -267.0, 15, 11),
LED_Point(301, 105.17221, -76.412056, -267.0, 16, 11),
LED_Point(302, 140.43933, -27.871037, -267.0, 17, 11),
LED_Point(303, 140.43933, 27.871075, -267.0, 18, 11),
LED_Point(304, 105.17221, 76.412094, -267.0, 19, 11),
LED_Point(305, 69.9051, 124.95311, -267.0, 20, 11),
LED_Point(306, 16.891186, 142.17839, -267.0, 21, 11),
LED_Point(307, -40.172207, 123.637375, -267.0, 22, 11),
LED_Point(308, -97.235596, 105.09636, -267.0, 23, 11),
LED_Point(309, -130.0, 60.000023, -267.0, 24, 11),
LED_Point(310, -130.0, 2.1791648E-5, -267.0, 25, 11),
LED_Point(311, -130.0, -59.999977, -267.0, 26, 11),

};

