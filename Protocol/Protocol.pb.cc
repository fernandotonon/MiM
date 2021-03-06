// Generated by the protocol buffer compiler.  DO NOT EDIT!

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "Protocol.pb.h"
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace Protocol {

namespace {

const ::google::protobuf::Descriptor* Config_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  Config_reflection_ = NULL;
const ::google::protobuf::Descriptor* Data_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  Data_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_Protocol_2eproto() {
  protobuf_AddDesc_Protocol_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "Protocol.proto");
  GOOGLE_CHECK(file != NULL);
  Config_descriptor_ = file->message_type(0);
  static const int Config_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Config, key_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Config, value_),
  };
  Config_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      Config_descriptor_,
      Config::default_instance_,
      Config_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Config, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Config, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(Config));
  Data_descriptor_ = file->message_type(1);
  static const int Data_offsets_[3] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Data, config_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Data, data_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Data, exception_),
  };
  Data_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      Data_descriptor_,
      Data::default_instance_,
      Data_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Data, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Data, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(Data));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_Protocol_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    Config_descriptor_, &Config::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    Data_descriptor_, &Data::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_Protocol_2eproto() {
  delete Config::default_instance_;
  delete Config_reflection_;
  delete Data::default_instance_;
  delete Data_reflection_;
}

void protobuf_AddDesc_Protocol_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\016Protocol.proto\022\010Protocol\"$\n\006Config\022\013\n\003"
    "key\030\001 \002(\t\022\r\n\005value\030\002 \002(\t\"I\n\004Data\022 \n\006conf"
    "ig\030\001 \003(\0132\020.Protocol.Config\022\014\n\004data\030\002 \001(\t"
    "\022\021\n\texception\030\003 \001(\t", 139);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "Protocol.proto", &protobuf_RegisterTypes);
  Config::default_instance_ = new Config();
  Data::default_instance_ = new Data();
  Config::default_instance_->InitAsDefaultInstance();
  Data::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_Protocol_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_Protocol_2eproto {
  StaticDescriptorInitializer_Protocol_2eproto() {
    protobuf_AddDesc_Protocol_2eproto();
  }
} static_descriptor_initializer_Protocol_2eproto_;


// ===================================================================

const ::std::string Config::_default_key_;
const ::std::string Config::_default_value_;
#ifndef _MSC_VER
const int Config::kKeyFieldNumber;
const int Config::kValueFieldNumber;
#endif  // !_MSC_VER

Config::Config()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void Config::InitAsDefaultInstance() {
}

Config::Config(const Config& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void Config::SharedCtor() {
  _cached_size_ = 0;
  key_ = const_cast< ::std::string*>(&_default_key_);
  value_ = const_cast< ::std::string*>(&_default_value_);
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

Config::~Config() {
  SharedDtor();
}

void Config::SharedDtor() {
  if (key_ != &_default_key_) {
    delete key_;
  }
  if (value_ != &_default_value_) {
    delete value_;
  }
  if (this != default_instance_) {
  }
}

void Config::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* Config::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return Config_descriptor_;
}

const Config& Config::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_Protocol_2eproto();  return *default_instance_;
}

Config* Config::default_instance_ = NULL;

Config* Config::New() const {
  return new Config;
}

void Config::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (_has_bit(0)) {
      if (key_ != &_default_key_) {
        key_->clear();
      }
    }
    if (_has_bit(1)) {
      if (value_ != &_default_value_) {
        value_->clear();
      }
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool Config::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required string key = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_key()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8String(
            this->key().data(), this->key().length(),
            ::google::protobuf::internal::WireFormat::PARSE);
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(18)) goto parse_value;
        break;
      }
      
      // required string value = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_value:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_value()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8String(
            this->value().data(), this->value().length(),
            ::google::protobuf::internal::WireFormat::PARSE);
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectAtEnd()) return true;
        break;
      }
      
      default: {
      handle_uninterpreted:
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          return true;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
  return true;
#undef DO_
}

void Config::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // required string key = 1;
  if (_has_bit(0)) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->key().data(), this->key().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      1, this->key(), output);
  }
  
  // required string value = 2;
  if (_has_bit(1)) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->value().data(), this->value().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      2, this->value(), output);
  }
  
  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* Config::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // required string key = 1;
  if (_has_bit(0)) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->key().data(), this->key().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->key(), target);
  }
  
  // required string value = 2;
  if (_has_bit(1)) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->value().data(), this->value().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        2, this->value(), target);
  }
  
  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int Config::ByteSize() const {
  int total_size = 0;
  
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required string key = 1;
    if (has_key()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->key());
    }
    
    // required string value = 2;
    if (has_value()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->value());
    }
    
  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void Config::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const Config* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const Config*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void Config::MergeFrom(const Config& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from._has_bit(0)) {
      set_key(from.key());
    }
    if (from._has_bit(1)) {
      set_value(from.value());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void Config::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Config::CopyFrom(const Config& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Config::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000003) != 0x00000003) return false;
  
  return true;
}

void Config::Swap(Config* other) {
  if (other != this) {
    std::swap(key_, other->key_);
    std::swap(value_, other->value_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata Config::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = Config_descriptor_;
  metadata.reflection = Config_reflection_;
  return metadata;
}


// ===================================================================

const ::std::string Data::_default_data_;
const ::std::string Data::_default_exception_;
#ifndef _MSC_VER
const int Data::kConfigFieldNumber;
const int Data::kDataFieldNumber;
const int Data::kExceptionFieldNumber;
#endif  // !_MSC_VER

Data::Data()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void Data::InitAsDefaultInstance() {
}

Data::Data(const Data& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void Data::SharedCtor() {
  _cached_size_ = 0;
  data_ = const_cast< ::std::string*>(&_default_data_);
  exception_ = const_cast< ::std::string*>(&_default_exception_);
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

Data::~Data() {
  SharedDtor();
}

void Data::SharedDtor() {
  if (data_ != &_default_data_) {
    delete data_;
  }
  if (exception_ != &_default_exception_) {
    delete exception_;
  }
  if (this != default_instance_) {
  }
}

void Data::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* Data::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return Data_descriptor_;
}

const Data& Data::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_Protocol_2eproto();  return *default_instance_;
}

Data* Data::default_instance_ = NULL;

Data* Data::New() const {
  return new Data;
}

void Data::Clear() {
  if (_has_bits_[1 / 32] & (0xffu << (1 % 32))) {
    if (_has_bit(1)) {
      if (data_ != &_default_data_) {
        data_->clear();
      }
    }
    if (_has_bit(2)) {
      if (exception_ != &_default_exception_) {
        exception_->clear();
      }
    }
  }
  config_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool Data::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // repeated .Protocol.Config config = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_config:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_config()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(10)) goto parse_config;
        if (input->ExpectTag(18)) goto parse_data;
        break;
      }
      
      // optional string data = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_data:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_data()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8String(
            this->data().data(), this->data().length(),
            ::google::protobuf::internal::WireFormat::PARSE);
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(26)) goto parse_exception;
        break;
      }
      
      // optional string exception = 3;
      case 3: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_exception:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_exception()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8String(
            this->exception().data(), this->exception().length(),
            ::google::protobuf::internal::WireFormat::PARSE);
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectAtEnd()) return true;
        break;
      }
      
      default: {
      handle_uninterpreted:
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          return true;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
  return true;
#undef DO_
}

void Data::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // repeated .Protocol.Config config = 1;
  for (int i = 0; i < this->config_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->config(i), output);
  }
  
  // optional string data = 2;
  if (_has_bit(1)) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->data().data(), this->data().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      2, this->data(), output);
  }
  
  // optional string exception = 3;
  if (_has_bit(2)) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->exception().data(), this->exception().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      3, this->exception(), output);
  }
  
  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* Data::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // repeated .Protocol.Config config = 1;
  for (int i = 0; i < this->config_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->config(i), target);
  }
  
  // optional string data = 2;
  if (_has_bit(1)) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->data().data(), this->data().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        2, this->data(), target);
  }
  
  // optional string exception = 3;
  if (_has_bit(2)) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->exception().data(), this->exception().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        3, this->exception(), target);
  }
  
  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int Data::ByteSize() const {
  int total_size = 0;
  
  if (_has_bits_[1 / 32] & (0xffu << (1 % 32))) {
    // optional string data = 2;
    if (has_data()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->data());
    }
    
    // optional string exception = 3;
    if (has_exception()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->exception());
    }
    
  }
  // repeated .Protocol.Config config = 1;
  total_size += 1 * this->config_size();
  for (int i = 0; i < this->config_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->config(i));
  }
  
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void Data::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const Data* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const Data*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void Data::MergeFrom(const Data& from) {
  GOOGLE_CHECK_NE(&from, this);
  config_.MergeFrom(from.config_);
  if (from._has_bits_[1 / 32] & (0xffu << (1 % 32))) {
    if (from._has_bit(1)) {
      set_data(from.data());
    }
    if (from._has_bit(2)) {
      set_exception(from.exception());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void Data::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Data::CopyFrom(const Data& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Data::IsInitialized() const {
  
  for (int i = 0; i < config_size(); i++) {
    if (!this->config(i).IsInitialized()) return false;
  }
  return true;
}

void Data::Swap(Data* other) {
  if (other != this) {
    config_.Swap(&other->config_);
    std::swap(data_, other->data_);
    std::swap(exception_, other->exception_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata Data::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = Data_descriptor_;
  metadata.reflection = Data_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace Protocol

// @@protoc_insertion_point(global_scope)
