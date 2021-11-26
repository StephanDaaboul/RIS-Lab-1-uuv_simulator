//#line 2 "/home/stephan/catkinws/src/dynamic_reconfigure/templates/ConfigType.h.template"
// *********************************************************
//
// File autogenerated for the uuv_control package
// by the dynamic_reconfigure package.
// Please do not edit.
//
// ********************************************************/

#ifndef __uuv_control__POSITIONCONTROLCONFIG_H__
#define __uuv_control__POSITIONCONTROLCONFIG_H__

#if __cplusplus >= 201103L
#define DYNAMIC_RECONFIGURE_FINAL final
#else
#define DYNAMIC_RECONFIGURE_FINAL
#endif

#include <dynamic_reconfigure/config_tools.h>
#include <limits>
#include <ros/node_handle.h>
#include <dynamic_reconfigure/ConfigDescription.h>
#include <dynamic_reconfigure/ParamDescription.h>
#include <dynamic_reconfigure/Group.h>
#include <dynamic_reconfigure/config_init_mutex.h>
#include <boost/any.hpp>

namespace uuv_control
{
  class PositionControlConfigStatics;

  class PositionControlConfig
  {
  public:
    class AbstractParamDescription : public dynamic_reconfigure::ParamDescription
    {
    public:
      AbstractParamDescription(std::string n, std::string t, uint32_t l,
          std::string d, std::string e)
      {
        name = n;
        type = t;
        level = l;
        description = d;
        edit_method = e;
      }
      virtual ~AbstractParamDescription() = default;

      virtual void clamp(PositionControlConfig &config, const PositionControlConfig &max, const PositionControlConfig &min) const = 0;
      virtual void calcLevel(uint32_t &level, const PositionControlConfig &config1, const PositionControlConfig &config2) const = 0;
      virtual void fromServer(const ros::NodeHandle &nh, PositionControlConfig &config) const = 0;
      virtual void toServer(const ros::NodeHandle &nh, const PositionControlConfig &config) const = 0;
      virtual bool fromMessage(const dynamic_reconfigure::Config &msg, PositionControlConfig &config) const = 0;
      virtual void toMessage(dynamic_reconfigure::Config &msg, const PositionControlConfig &config) const = 0;
      virtual void getValue(const PositionControlConfig &config, boost::any &val) const = 0;
    };

    typedef boost::shared_ptr<AbstractParamDescription> AbstractParamDescriptionPtr;
    typedef boost::shared_ptr<const AbstractParamDescription> AbstractParamDescriptionConstPtr;

    // Final keyword added to class because it has virtual methods and inherits
    // from a class with a non-virtual destructor.
    template <class T>
    class ParamDescription DYNAMIC_RECONFIGURE_FINAL : public AbstractParamDescription
    {
    public:
      ParamDescription(std::string a_name, std::string a_type, uint32_t a_level,
          std::string a_description, std::string a_edit_method, T PositionControlConfig::* a_f) :
        AbstractParamDescription(a_name, a_type, a_level, a_description, a_edit_method),
        field(a_f)
      {}

      T PositionControlConfig::* field;

      virtual void clamp(PositionControlConfig &config, const PositionControlConfig &max, const PositionControlConfig &min) const override
      {
        if (config.*field > max.*field)
          config.*field = max.*field;

        if (config.*field < min.*field)
          config.*field = min.*field;
      }

      virtual void calcLevel(uint32_t &comb_level, const PositionControlConfig &config1, const PositionControlConfig &config2) const override
      {
        if (config1.*field != config2.*field)
          comb_level |= level;
      }

      virtual void fromServer(const ros::NodeHandle &nh, PositionControlConfig &config) const override
      {
        nh.getParam(name, config.*field);
      }

      virtual void toServer(const ros::NodeHandle &nh, const PositionControlConfig &config) const override
      {
        nh.setParam(name, config.*field);
      }

      virtual bool fromMessage(const dynamic_reconfigure::Config &msg, PositionControlConfig &config) const override
      {
        return dynamic_reconfigure::ConfigTools::getParameter(msg, name, config.*field);
      }

      virtual void toMessage(dynamic_reconfigure::Config &msg, const PositionControlConfig &config) const override
      {
        dynamic_reconfigure::ConfigTools::appendParameter(msg, name, config.*field);
      }

      virtual void getValue(const PositionControlConfig &config, boost::any &val) const override
      {
        val = config.*field;
      }
    };

    class AbstractGroupDescription : public dynamic_reconfigure::Group
    {
      public:
      AbstractGroupDescription(std::string n, std::string t, int p, int i, bool s)
      {
        name = n;
        type = t;
        parent = p;
        state = s;
        id = i;
      }

      virtual ~AbstractGroupDescription() = default;

      std::vector<AbstractParamDescriptionConstPtr> abstract_parameters;
      bool state;

      virtual void toMessage(dynamic_reconfigure::Config &msg, const boost::any &config) const = 0;
      virtual bool fromMessage(const dynamic_reconfigure::Config &msg, boost::any &config) const =0;
      virtual void updateParams(boost::any &cfg, PositionControlConfig &top) const= 0;
      virtual void setInitialState(boost::any &cfg) const = 0;


      void convertParams()
      {
        for(std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = abstract_parameters.begin(); i != abstract_parameters.end(); ++i)
        {
          parameters.push_back(dynamic_reconfigure::ParamDescription(**i));
        }
      }
    };

    typedef boost::shared_ptr<AbstractGroupDescription> AbstractGroupDescriptionPtr;
    typedef boost::shared_ptr<const AbstractGroupDescription> AbstractGroupDescriptionConstPtr;

    // Final keyword added to class because it has virtual methods and inherits
    // from a class with a non-virtual destructor.
    template<class T, class PT>
    class GroupDescription DYNAMIC_RECONFIGURE_FINAL : public AbstractGroupDescription
    {
    public:
      GroupDescription(std::string a_name, std::string a_type, int a_parent, int a_id, bool a_s, T PT::* a_f) : AbstractGroupDescription(a_name, a_type, a_parent, a_id, a_s), field(a_f)
      {
      }

      GroupDescription(const GroupDescription<T, PT>& g): AbstractGroupDescription(g.name, g.type, g.parent, g.id, g.state), field(g.field), groups(g.groups)
      {
        parameters = g.parameters;
        abstract_parameters = g.abstract_parameters;
      }

      virtual bool fromMessage(const dynamic_reconfigure::Config &msg, boost::any &cfg) const override
      {
        PT* config = boost::any_cast<PT*>(cfg);
        if(!dynamic_reconfigure::ConfigTools::getGroupState(msg, name, (*config).*field))
          return false;

        for(std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = groups.begin(); i != groups.end(); ++i)
        {
          boost::any n = &((*config).*field);
          if(!(*i)->fromMessage(msg, n))
            return false;
        }

        return true;
      }

      virtual void setInitialState(boost::any &cfg) const override
      {
        PT* config = boost::any_cast<PT*>(cfg);
        T* group = &((*config).*field);
        group->state = state;

        for(std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = groups.begin(); i != groups.end(); ++i)
        {
          boost::any n = boost::any(&((*config).*field));
          (*i)->setInitialState(n);
        }

      }

      virtual void updateParams(boost::any &cfg, PositionControlConfig &top) const override
      {
        PT* config = boost::any_cast<PT*>(cfg);

        T* f = &((*config).*field);
        f->setParams(top, abstract_parameters);

        for(std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = groups.begin(); i != groups.end(); ++i)
        {
          boost::any n = &((*config).*field);
          (*i)->updateParams(n, top);
        }
      }

      virtual void toMessage(dynamic_reconfigure::Config &msg, const boost::any &cfg) const override
      {
        const PT config = boost::any_cast<PT>(cfg);
        dynamic_reconfigure::ConfigTools::appendGroup<T>(msg, name, id, parent, config.*field);

        for(std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = groups.begin(); i != groups.end(); ++i)
        {
          (*i)->toMessage(msg, config.*field);
        }
      }

      T PT::* field;
      std::vector<PositionControlConfig::AbstractGroupDescriptionConstPtr> groups;
    };

class DEFAULT
{
  public:
    DEFAULT()
    {
      state = true;
      name = "Default";
    }

    void setParams(PositionControlConfig &config, const std::vector<AbstractParamDescriptionConstPtr> params)
    {
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator _i = params.begin(); _i != params.end(); ++_i)
      {
        boost::any val;
        (*_i)->getValue(config, val);

        if("pos_p"==(*_i)->name){pos_p = boost::any_cast<double>(val);}
        if("pos_i"==(*_i)->name){pos_i = boost::any_cast<double>(val);}
        if("pos_d"==(*_i)->name){pos_d = boost::any_cast<double>(val);}
        if("pos_sat"==(*_i)->name){pos_sat = boost::any_cast<double>(val);}
        if("rot_p"==(*_i)->name){rot_p = boost::any_cast<double>(val);}
        if("rot_i"==(*_i)->name){rot_i = boost::any_cast<double>(val);}
        if("rot_d"==(*_i)->name){rot_d = boost::any_cast<double>(val);}
        if("rot_sat"==(*_i)->name){rot_sat = boost::any_cast<double>(val);}
      }
    }

    double pos_p;
double pos_i;
double pos_d;
double pos_sat;
double rot_p;
double rot_i;
double rot_d;
double rot_sat;

    bool state;
    std::string name;

    
}groups;



//#line 291 "/home/stephan/catkinws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py"
      double pos_p;
//#line 291 "/home/stephan/catkinws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py"
      double pos_i;
//#line 291 "/home/stephan/catkinws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py"
      double pos_d;
//#line 291 "/home/stephan/catkinws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py"
      double pos_sat;
//#line 291 "/home/stephan/catkinws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py"
      double rot_p;
//#line 291 "/home/stephan/catkinws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py"
      double rot_i;
//#line 291 "/home/stephan/catkinws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py"
      double rot_d;
//#line 291 "/home/stephan/catkinws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py"
      double rot_sat;
//#line 231 "/home/stephan/catkinws/src/dynamic_reconfigure/templates/ConfigType.h.template"

    bool __fromMessage__(dynamic_reconfigure::Config &msg)
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      const std::vector<AbstractGroupDescriptionConstPtr> &__group_descriptions__ = __getGroupDescriptions__();

      int count = 0;
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        if ((*i)->fromMessage(msg, *this))
          count++;

      for (std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = __group_descriptions__.begin(); i != __group_descriptions__.end(); i ++)
      {
        if ((*i)->id == 0)
        {
          boost::any n = boost::any(this);
          (*i)->updateParams(n, *this);
          (*i)->fromMessage(msg, n);
        }
      }

      if (count != dynamic_reconfigure::ConfigTools::size(msg))
      {
        ROS_ERROR("PositionControlConfig::__fromMessage__ called with an unexpected parameter.");
        ROS_ERROR("Booleans:");
        for (unsigned int i = 0; i < msg.bools.size(); i++)
          ROS_ERROR("  %s", msg.bools[i].name.c_str());
        ROS_ERROR("Integers:");
        for (unsigned int i = 0; i < msg.ints.size(); i++)
          ROS_ERROR("  %s", msg.ints[i].name.c_str());
        ROS_ERROR("Doubles:");
        for (unsigned int i = 0; i < msg.doubles.size(); i++)
          ROS_ERROR("  %s", msg.doubles[i].name.c_str());
        ROS_ERROR("Strings:");
        for (unsigned int i = 0; i < msg.strs.size(); i++)
          ROS_ERROR("  %s", msg.strs[i].name.c_str());
        // @todo Check that there are no duplicates. Make this error more
        // explicit.
        return false;
      }
      return true;
    }

    // This version of __toMessage__ is used during initialization of
    // statics when __getParamDescriptions__ can't be called yet.
    void __toMessage__(dynamic_reconfigure::Config &msg, const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__, const std::vector<AbstractGroupDescriptionConstPtr> &__group_descriptions__) const
    {
      dynamic_reconfigure::ConfigTools::clear(msg);
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        (*i)->toMessage(msg, *this);

      for (std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = __group_descriptions__.begin(); i != __group_descriptions__.end(); ++i)
      {
        if((*i)->id == 0)
        {
          (*i)->toMessage(msg, *this);
        }
      }
    }

    void __toMessage__(dynamic_reconfigure::Config &msg) const
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      const std::vector<AbstractGroupDescriptionConstPtr> &__group_descriptions__ = __getGroupDescriptions__();
      __toMessage__(msg, __param_descriptions__, __group_descriptions__);
    }

    void __toServer__(const ros::NodeHandle &nh) const
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        (*i)->toServer(nh, *this);
    }

    void __fromServer__(const ros::NodeHandle &nh)
    {
      static bool setup=false;

      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        (*i)->fromServer(nh, *this);

      const std::vector<AbstractGroupDescriptionConstPtr> &__group_descriptions__ = __getGroupDescriptions__();
      for (std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = __group_descriptions__.begin(); i != __group_descriptions__.end(); i++){
        if (!setup && (*i)->id == 0) {
          setup = true;
          boost::any n = boost::any(this);
          (*i)->setInitialState(n);
        }
      }
    }

    void __clamp__()
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      const PositionControlConfig &__max__ = __getMax__();
      const PositionControlConfig &__min__ = __getMin__();
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        (*i)->clamp(*this, __max__, __min__);
    }

    uint32_t __level__(const PositionControlConfig &config) const
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      uint32_t level = 0;
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        (*i)->calcLevel(level, config, *this);
      return level;
    }

    static const dynamic_reconfigure::ConfigDescription &__getDescriptionMessage__();
    static const PositionControlConfig &__getDefault__();
    static const PositionControlConfig &__getMax__();
    static const PositionControlConfig &__getMin__();
    static const std::vector<AbstractParamDescriptionConstPtr> &__getParamDescriptions__();
    static const std::vector<AbstractGroupDescriptionConstPtr> &__getGroupDescriptions__();

  private:
    static const PositionControlConfigStatics *__get_statics__();
  };

  template <> // Max and min are ignored for strings.
  inline void PositionControlConfig::ParamDescription<std::string>::clamp(PositionControlConfig &config, const PositionControlConfig &max, const PositionControlConfig &min) const
  {
    (void) config;
    (void) min;
    (void) max;
    return;
  }

  class PositionControlConfigStatics
  {
    friend class PositionControlConfig;

    PositionControlConfigStatics()
    {
PositionControlConfig::GroupDescription<PositionControlConfig::DEFAULT, PositionControlConfig> Default("Default", "", 0, 0, true, &PositionControlConfig::groups);
//#line 291 "/home/stephan/catkinws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.pos_p = 0.0;
//#line 291 "/home/stephan/catkinws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.pos_p = 100.0;
//#line 291 "/home/stephan/catkinws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.pos_p = 1.0;
//#line 291 "/home/stephan/catkinws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(PositionControlConfig::AbstractParamDescriptionConstPtr(new PositionControlConfig::ParamDescription<double>("pos_p", "double", 0, "p component of pid for position", "", &PositionControlConfig::pos_p)));
//#line 291 "/home/stephan/catkinws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(PositionControlConfig::AbstractParamDescriptionConstPtr(new PositionControlConfig::ParamDescription<double>("pos_p", "double", 0, "p component of pid for position", "", &PositionControlConfig::pos_p)));
//#line 291 "/home/stephan/catkinws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.pos_i = 0.0;
//#line 291 "/home/stephan/catkinws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.pos_i = 100.0;
//#line 291 "/home/stephan/catkinws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.pos_i = 0.0;
//#line 291 "/home/stephan/catkinws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(PositionControlConfig::AbstractParamDescriptionConstPtr(new PositionControlConfig::ParamDescription<double>("pos_i", "double", 0, "i component of pid for position.", "", &PositionControlConfig::pos_i)));
//#line 291 "/home/stephan/catkinws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(PositionControlConfig::AbstractParamDescriptionConstPtr(new PositionControlConfig::ParamDescription<double>("pos_i", "double", 0, "i component of pid for position.", "", &PositionControlConfig::pos_i)));
//#line 291 "/home/stephan/catkinws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.pos_d = 0.0;
//#line 291 "/home/stephan/catkinws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.pos_d = 100.0;
//#line 291 "/home/stephan/catkinws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.pos_d = 0.0;
//#line 291 "/home/stephan/catkinws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(PositionControlConfig::AbstractParamDescriptionConstPtr(new PositionControlConfig::ParamDescription<double>("pos_d", "double", 0, "d component of pid for position.", "", &PositionControlConfig::pos_d)));
//#line 291 "/home/stephan/catkinws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(PositionControlConfig::AbstractParamDescriptionConstPtr(new PositionControlConfig::ParamDescription<double>("pos_d", "double", 0, "d component of pid for position.", "", &PositionControlConfig::pos_d)));
//#line 291 "/home/stephan/catkinws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.pos_sat = 0.0;
//#line 291 "/home/stephan/catkinws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.pos_sat = 100.0;
//#line 291 "/home/stephan/catkinws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.pos_sat = 10.0;
//#line 291 "/home/stephan/catkinws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(PositionControlConfig::AbstractParamDescriptionConstPtr(new PositionControlConfig::ParamDescription<double>("pos_sat", "double", 0, "saturation of pid for position.", "", &PositionControlConfig::pos_sat)));
//#line 291 "/home/stephan/catkinws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(PositionControlConfig::AbstractParamDescriptionConstPtr(new PositionControlConfig::ParamDescription<double>("pos_sat", "double", 0, "saturation of pid for position.", "", &PositionControlConfig::pos_sat)));
//#line 291 "/home/stephan/catkinws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.rot_p = 0.0;
//#line 291 "/home/stephan/catkinws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.rot_p = 100.0;
//#line 291 "/home/stephan/catkinws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.rot_p = 1.0;
//#line 291 "/home/stephan/catkinws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(PositionControlConfig::AbstractParamDescriptionConstPtr(new PositionControlConfig::ParamDescription<double>("rot_p", "double", 0, "p component of pid for orientation.", "", &PositionControlConfig::rot_p)));
//#line 291 "/home/stephan/catkinws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(PositionControlConfig::AbstractParamDescriptionConstPtr(new PositionControlConfig::ParamDescription<double>("rot_p", "double", 0, "p component of pid for orientation.", "", &PositionControlConfig::rot_p)));
//#line 291 "/home/stephan/catkinws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.rot_i = 0.0;
//#line 291 "/home/stephan/catkinws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.rot_i = 100.0;
//#line 291 "/home/stephan/catkinws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.rot_i = 0.0;
//#line 291 "/home/stephan/catkinws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(PositionControlConfig::AbstractParamDescriptionConstPtr(new PositionControlConfig::ParamDescription<double>("rot_i", "double", 0, "i component of pid for orientation.", "", &PositionControlConfig::rot_i)));
//#line 291 "/home/stephan/catkinws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(PositionControlConfig::AbstractParamDescriptionConstPtr(new PositionControlConfig::ParamDescription<double>("rot_i", "double", 0, "i component of pid for orientation.", "", &PositionControlConfig::rot_i)));
//#line 291 "/home/stephan/catkinws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.rot_d = 0.0;
//#line 291 "/home/stephan/catkinws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.rot_d = 100.0;
//#line 291 "/home/stephan/catkinws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.rot_d = 0.0;
//#line 291 "/home/stephan/catkinws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(PositionControlConfig::AbstractParamDescriptionConstPtr(new PositionControlConfig::ParamDescription<double>("rot_d", "double", 0, "d component of pid for orientation.", "", &PositionControlConfig::rot_d)));
//#line 291 "/home/stephan/catkinws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(PositionControlConfig::AbstractParamDescriptionConstPtr(new PositionControlConfig::ParamDescription<double>("rot_d", "double", 0, "d component of pid for orientation.", "", &PositionControlConfig::rot_d)));
//#line 291 "/home/stephan/catkinws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.rot_sat = 0.0;
//#line 291 "/home/stephan/catkinws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.rot_sat = 100.0;
//#line 291 "/home/stephan/catkinws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.rot_sat = 3.0;
//#line 291 "/home/stephan/catkinws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(PositionControlConfig::AbstractParamDescriptionConstPtr(new PositionControlConfig::ParamDescription<double>("rot_sat", "double", 0, "saturation of pid for orientation.", "", &PositionControlConfig::rot_sat)));
//#line 291 "/home/stephan/catkinws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(PositionControlConfig::AbstractParamDescriptionConstPtr(new PositionControlConfig::ParamDescription<double>("rot_sat", "double", 0, "saturation of pid for orientation.", "", &PositionControlConfig::rot_sat)));
//#line 246 "/home/stephan/catkinws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.convertParams();
//#line 246 "/home/stephan/catkinws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py"
      __group_descriptions__.push_back(PositionControlConfig::AbstractGroupDescriptionConstPtr(new PositionControlConfig::GroupDescription<PositionControlConfig::DEFAULT, PositionControlConfig>(Default)));
//#line 369 "/home/stephan/catkinws/src/dynamic_reconfigure/templates/ConfigType.h.template"

      for (std::vector<PositionControlConfig::AbstractGroupDescriptionConstPtr>::const_iterator i = __group_descriptions__.begin(); i != __group_descriptions__.end(); ++i)
      {
        __description_message__.groups.push_back(**i);
      }
      __max__.__toMessage__(__description_message__.max, __param_descriptions__, __group_descriptions__);
      __min__.__toMessage__(__description_message__.min, __param_descriptions__, __group_descriptions__);
      __default__.__toMessage__(__description_message__.dflt, __param_descriptions__, __group_descriptions__);
    }
    std::vector<PositionControlConfig::AbstractParamDescriptionConstPtr> __param_descriptions__;
    std::vector<PositionControlConfig::AbstractGroupDescriptionConstPtr> __group_descriptions__;
    PositionControlConfig __max__;
    PositionControlConfig __min__;
    PositionControlConfig __default__;
    dynamic_reconfigure::ConfigDescription __description_message__;

    static const PositionControlConfigStatics *get_instance()
    {
      // Split this off in a separate function because I know that
      // instance will get initialized the first time get_instance is
      // called, and I am guaranteeing that get_instance gets called at
      // most once.
      static PositionControlConfigStatics instance;
      return &instance;
    }
  };

  inline const dynamic_reconfigure::ConfigDescription &PositionControlConfig::__getDescriptionMessage__()
  {
    return __get_statics__()->__description_message__;
  }

  inline const PositionControlConfig &PositionControlConfig::__getDefault__()
  {
    return __get_statics__()->__default__;
  }

  inline const PositionControlConfig &PositionControlConfig::__getMax__()
  {
    return __get_statics__()->__max__;
  }

  inline const PositionControlConfig &PositionControlConfig::__getMin__()
  {
    return __get_statics__()->__min__;
  }

  inline const std::vector<PositionControlConfig::AbstractParamDescriptionConstPtr> &PositionControlConfig::__getParamDescriptions__()
  {
    return __get_statics__()->__param_descriptions__;
  }

  inline const std::vector<PositionControlConfig::AbstractGroupDescriptionConstPtr> &PositionControlConfig::__getGroupDescriptions__()
  {
    return __get_statics__()->__group_descriptions__;
  }

  inline const PositionControlConfigStatics *PositionControlConfig::__get_statics__()
  {
    const static PositionControlConfigStatics *statics;

    if (statics) // Common case
      return statics;

    boost::mutex::scoped_lock lock(dynamic_reconfigure::__init_mutex__);

    if (statics) // In case we lost a race.
      return statics;

    statics = PositionControlConfigStatics::get_instance();

    return statics;
  }


}

#undef DYNAMIC_RECONFIGURE_FINAL

#endif // __POSITIONCONTROLRECONFIGURATOR_H__
