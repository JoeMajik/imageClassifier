#ifndef TRAININGIMAGEDBWRAPPER_H
#define TRAININGIMAGEDBWRAPPER_H

#include <ImageSequence.h>
#include <SegmentedImage.h>
#include <SegmentedRegion.h>
#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <iostream>
#include <QSqlError>
#include <QVariant>
#include <stdexcept>
#include <ConverterMethods.h>
#include <CvQt.h>
#include <unordered_map>
#include <map>
//#include <opencv2/core/core.hpp>
//#include <opencv2/highgui/highgui.hpp>
#include <ConverterMethods.h>

class TrainingImageDbWrapper
{
public:
    TrainingImageDbWrapper();

    static ImageSequence getTilesWithSingleProperty
    (QString dbFilePath, int captureDeviceID, int propertyID , int tileWidth, int tileHeight);

    static std::vector<ImageSequence> getPreClusteredTilesWithSingleProperty
    (QString dbFilePath, int captureDeviceID, int propertyID , int tileWidth, int tileHeight);

    //returns a pre-clustered list of tiles for a given property (for example, using target property = "road"
    //will return all tiles corresponding to any segmented region that is tagged with road. all of these tiles will be clustered into
    //individual image sequences based on all combinations of other properties of the segmented regions that are associated with road.
    static std::vector<SegmentedImage<int>> getSegmentedImagesWithSingleProperty(QString dbFilePath, int captureDeviceID, int propertyID);


};

#endif // TRAININGIMAGEDBWRAPPER_H
