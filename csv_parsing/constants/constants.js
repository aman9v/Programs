/*jshint esversion:6*/

const iotId = '@iot.id';
const iotCount = '@iot.count';
const iotNextLink = '@iot.nextLink';
const iotSelfLink = '@iot.selfLink';
const navigationLink = "@iot.navigationLink";



const entities = [
  "Things",
  "Locations",
  "HistoricalLocations",
  "Observations",
  "Sensors",
  "ObservedProperties",
  "DataStreams",
  "FeaturesOfInterest"
];

const obsTypeUrl = 'http://www.opengis.net/def/observationType/OGC-OM/2.0/';

const observationTypes = {
  OM_CATEGORY_OBSERVATION: obsTypeUrl + 'OM_CategoryObservation',
  OM_COUNT_OBSERVATION: obsTypeUrl + 'OM_CountObservation',
  OM_MEASUREMENT: obsTypeUrl + 'OM_Measurement',
  OM_OBSERVATION: obsTypeUrl + 'OM_Observation',
  OM_TRUTH_OBSERVATION: obsTypeUrl + 'OM_TruthObservation'
};

const encodingTypes = {
  UNKNOWN: 'unknown',
  GEO_JSON: 'application/vnd.geo+json',
  PDF: 'application/pdf',
  SENSOR_ML: 'http://www.opengis.net/doc/IS/SensorML/2.0',
  TEXT_HTML: 'text/html',
  LOCATION_TYPE: 'http://example.org/location_types#GeoJSON',
  TYPE_DESCRIPTION: 'http://schema.org/description'
};

module.exports = { entities, encodingTypes, observationTypes, iotId, iotCount, iotSelfLink, iotNextLink };
