#pragma once

#include "iodevice.h"

namespace cl
{
	/// \addtogroup clanCore_I_O_Data clanCore I/O Data
	/// \{

	class DataBuffer;

	/// \brief Memory I/O device.
	class MemoryDevice : public IODevice
	{
	public:
		/// \brief Constructs a memory I/O device.
		MemoryDevice();

		/// \brief Constructs a IODevice Memory
		///
		/// \param data = Data Buffer
		MemoryDevice(DataBuffer &data);

		/// \brief Retrieves the data buffer for the memory device.
		const DataBuffer &get_data() const;

		/// \brief Get Data
		///
		/// \return data
		DataBuffer &get_data();
	};

	/// \}
}
