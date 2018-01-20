//
// Created by macdoy on 20/01/18.
//

#ifndef RTYPE_NETWORKCOMPONENT_HPP
#define RTYPE_NETWORKCOMPONENT_HPP

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


#endif //RTYPE_NETWORKCOMPONENT_HPP
