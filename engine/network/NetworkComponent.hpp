//
// Created by macdoy on 20/01/18.
//

#ifndef ENGINE_NETWORK_COMPONENT
#define ENGINE_NETWORK_COMPONENT

#include <core/Component.hpp>

namespace engine {
    namespace network {
        class NetworkComponent : public core::Component {
        private:
            int _fd;
            int _id;
            bool _inRoom;
            std::string _roomName;
            bool isReady;

        public:
            NetworkComponent();
            virtual ~NetworkComponent();

            void setRoom(std::string roomName);
            void cleanRoom();

            void SendMessage(engine::core::Message *message) override;
            void Update(float dt) override;
            void Init(void) override;
            void ShutDown(void) override;

            int getFd() const;
            int getId() const;
            bool getInRoom() const;
            std::string getRoomName() const;
            bool getIsReady() const;

            void setFd(const int &);
            void setId(const int &);
            void setInRoom(const bool &);
            void setRoomName(const std::string &);
            void setIsReady(const bool &);
        };
    }
}

#endif //ENGINE_NETWORK_COMPONENT
