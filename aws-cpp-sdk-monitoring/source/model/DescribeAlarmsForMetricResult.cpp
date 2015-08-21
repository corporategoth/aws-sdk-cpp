/*
* Copyright 2010-2015 Amazon.com, Inc. or its affiliates. All Rights Reserved.
*
* Licensed under the Apache License, Version 2.0 (the "License").
* You may not use this file except in compliance with the License.
* A copy of the License is located at
*
*  http://aws.amazon.com/apache2.0
*
* or in the "license" file accompanying this file. This file is distributed
* on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
* express or implied. See the License for the specific language governing
* permissions and limitations under the License.
*/
#include <aws/monitoring/model/DescribeAlarmsForMetricResult.h>
#include <aws/core/utils/xml/XmlSerializer.h>
#include <aws/core/AmazonWebServiceResult.h>
#include <aws/core/utils/StringUtils.h>

#include <utility>

using namespace Aws::CloudWatch::Model;
using namespace Aws::Utils::Xml;
using namespace Aws::Utils;
using namespace Aws;

DescribeAlarmsForMetricResult::DescribeAlarmsForMetricResult()
{
}

DescribeAlarmsForMetricResult::DescribeAlarmsForMetricResult(const AmazonWebServiceResult<XmlDocument>& result)
{
  *this = result;
}

DescribeAlarmsForMetricResult& DescribeAlarmsForMetricResult::operator =(const AmazonWebServiceResult<XmlDocument>& result)
{
  const XmlDocument& xmlDocument = result.GetPayload();
  XmlNode rootNode = xmlDocument.GetRootElement();
  XmlNode resultNode = rootNode.FirstChild("DescribeAlarmsForMetricResult");

  if(!resultNode.IsNull())
  {
    XmlNode metricAlarmsNode = resultNode.FirstChild("MetricAlarms");
    if(!metricAlarmsNode.IsNull())
    {
      XmlNode metricAlarmsMember = metricAlarmsNode.FirstChild("member");
      while(!metricAlarmsMember.IsNull())
      {
        m_metricAlarms.push_back(metricAlarmsMember);
        metricAlarmsMember = metricAlarmsMember.NextNode("member");
      }

    }
  }

  XmlNode responseMetadataNode = rootNode.FirstChild("ResponseMetadata");
  m_responseMetadata = responseMetadataNode;

  return *this;
}
