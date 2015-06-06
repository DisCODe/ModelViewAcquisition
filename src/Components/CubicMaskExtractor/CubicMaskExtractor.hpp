/*!
 * \file
 * \brief
 * \author Łukasz Żmuda
 */

#ifndef CUBICMASKEXTRACTOR_HPP_
#define CUBICMASKEXTRACTOR_HPP_

#include "Component_Aux.hpp"
#include "Component.hpp"
#include "DataStream.hpp"
#include "Property.hpp"
#include "EventHandler2.hpp"

#include <opencv2/opencv.hpp>
#include <Types/CameraInfo.hpp>
#include "Types/HomogMatrix.hpp"

namespace Processors {
namespace CubicMaskExtractor {

/*!
 * \class CubicMaskExtractor
 * \brief CubicMaskExtractor processor class.
 *
 * CubicMaskExtractor processor.
 */
class CubicMaskExtractor: public Base::Component {
public:
	/*!
	 * Constructor.
	 */
	CubicMaskExtractor(const std::string & name = "CubicMaskExtractor");

	/*!
	 * Destructor
	 */
	virtual ~CubicMaskExtractor();

	/*!
	 * Prepare components interface (register streams and handlers).
	 * At this point, all properties are already initialized and loaded to
	 * values set in config file.
	 */
	void prepareInterface();

	Base::Property<double> prop_XAxisMin_treshold;
	Base::Property<double> prop_XAxisMax_treshold;
	Base::Property<double> prop_YAxisMin_treshold;
	Base::Property<double> prop_YAxisMax_treshold;
	Base::Property<double> prop_ZAxisMin_treshold;
	Base::Property<double> prop_ZAxisMax_treshold;

protected:

	/*!
	 * Connects source to given device.
	 */
	bool onInit();

	/*!
	 * Disconnect source from device, closes streams, etc.
	 */
	bool onFinish();

	/*!
	 * Start component
	 */
	bool onStart();

	/*!
	 * Stop component
	 */
	bool onStop();


	// Input data streams

	Base::DataStreamIn <cv::Mat>  in_image_xyz;
	//Base::DataStreamIn <cv::Point3d> in_centerMassPoint;
	// Output data streams
	Base::DataStreamOut <cv::Mat> out_mask;

	// Handlers
	Base::EventHandler2 h_filter;


	// Handlers
	void filter();

};

} //: namespace CubicMaskExtractor
} //: namespace Processors

/*
 * Register processor component.
 */
REGISTER_COMPONENT("CubicMaskExtractor", Processors::CubicMaskExtractor::CubicMaskExtractor)

#endif /* CUBICMASKEXTRACTOR_HPP_ */
